#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

#define MAX 1000

// Global grid and visited tracker
int grid[MAX][MAX];
bool visited[MAX][MAX];

int rows, cols;

// 4-neighbor directions (DO NOT MODIFY)
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// ------------------------------------------------------------
// Helper: check if (r, c) is inside grid bounds
// ------------------------------------------------------------
bool inBounds(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

// ------------------------------------------------------------
// TODO 1:
// Count how many 4-neighbor edge pixels (value == 1)
// surround (r, c)
// ------------------------------------------------------------
//
// complete the function below!
int countNeighbors(int r, int c) {
    // Loop over 4 directions using dr, dc
    // Count neighbors where grid[nr][nc] == 1
    int count = 0; // neighbor count
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i]; // neighbor row handling (r is current row, dr[i] the change in row for direction i)
        int nc = c + dc[i]; // neighbor column handling (c is current column, dc[i] the change in column for direction i)
        if(inBounds(nr, nc) && grid[nr][nc] == 1) { // check if neighbor in bounds and is an edge pixel
            // increment for each valid neighbor 
            count++;
        }
    }
    return count; // return how many neighbors are edge pixels
    // this is how we know if we found the outline of the image
}

// ------------------------------------------------------------
// TODO 2:
// From current position (r, c), find the next unvisited
// neighboring edge pixel (value == 1)
//
// Return true if found and update (*nr, *nc)
// Return false if no valid move exists
// ------------------------------------------------------------
//
// comlete the function below
bool getNext(int r, int c, int* nr, int* nc) {
    // Check all 4 neighbors
    // Conditions:
    //   - in bounds
    //   - grid == 1
    //   - not visited
    // If found:
    //   set (*nr, *nc)
    //   return true
    for(int i = 0; i < 4; i++) {
        int nextRow = r + dr[i]; // row pos + direction change
        int nextCol = c + dc[i]; // col pos + direction change
        if(inBounds(nextRow, nextCol) && grid[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]) { // if pixel in bounds is edge and has not ever been visited before
            *nr = nextRow;
            *nc = nextCol;
            return true; // we found a valid next move
            // return true and move to the next pixel position
        }
    }
    return false;
}

// ------------------------------------------------------------
// Main
// ------------------------------------------------------------
int main(int argc, char* argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        exit(1);
    }

    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");

    if (!in || !out) {
        fprintf(stderr, "File error\n");
        exit(1);
    }

    // --------------------------------------------------------
    // Read input
    // --------------------------------------------------------
    fscanf(in, "%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(in, "%d", &grid[i][j]);
            visited[i][j] = false;
        }
    }

    // --------------------------------------------------------
    // TODO 3:
    // Find the edge path.
    // Path should contain the ordered list of edge pixels.
    // --------------------------------------------------------
    //
    // put your code here
    // variables available to use: grid, visited, rows, cols, dr, dc
    for(int i = 0; i < rows; i++) { // there is a problem with this; i dont like nested for loops
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) { // if we find an edge pixel
                visited[i][j] = true; // mark it as visited
                break; // break out of the loop to start tracing the path from this pixel
            }
        }
    }
    List path = newList();


    // --------------------------------------------------------
    // TODO 4:
    // Prints the ordered list of edge pixels from starting point
    // to ending point.
    // --------------------------------------------------------
    //
    // put your code here
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                int currentRow = i;
                int currentCol = j;
                append(path, currentRow);
                append(path, currentCol);
                visited[currentRow][currentCol] = true; // mark the starting pixel as visited
                int nextRow, nextCol;
                while(getNext(currentRow, currentCol, &nextRow, &nextCol)) {
                    append(path, nextRow);
                    append(path, nextCol);
                    visited[nextRow][nextCol] = true; // mark the next pixel as visited
                    currentRow = nextRow; // move to the next pixel
                    currentCol = nextCol;
                }
            }
            printList(out, path);
        }
    }

    // Cleanup
    freeList(&path);
    fclose(in);
    fclose(out);

    return 0;
}
