CSE 101 — Programming Assignment 1 (Prog 1)
This assignment is about tracing a single connected edge path through a 2D binary grid and storing that path in order using the List ADT from Homework 1. The important part is that students are not doing image processing or edge detection themselves. The edge pixels are already given in the input as 1s, and the task is to recover the ordered path from one endpoint to the other.

Core idea
The input is a grid of 0s and 1s.
 A 1 means “edge pixel.”
 A 0 means “background.”
All of the 1s together form exactly one connected component under 4-neighbor connectivity. That means neighbors are only:
up
down
left
right
Diagonal neighbors do not count.
The assignment also guarantees that this connected component is a simple path:
no branches
no cycles
at least two edge pixels
exactly two endpoints
Because of that, once the correct starting endpoint is found, the rest of the path can be followed uniquely one step at a time until the other endpoint is reached.
What students are really building
You are writing a client program called TraceEdges that:
reads a grid from an input file
finds the two endpoints
chooses the correct starting endpoint
walks the path in order
stores the visited pixels in a List
writes the coordinates to the output file in the required order
So this assignment is not mainly about tricky algorithms. It is more about:
careful file I/O
correct grid traversal
correct use of the List ADT
correct output formatting
What files matter

The provided files are:
Makefile
List.h
List.c
TraceEdges.c
sample input/output files such as prog1.in and prog1.out

You must use the List ADT from Homework 1. That means they are not allowed to replace it with arrays, vectors, or any other container structure for storing the final ordered path. Arrays are allowed for storing the grid itself.

What the program must do
The program runs like this:
./TraceEdges input.in output.out
The input file begins with:
 rows cols
After that come rows lines, each with cols integers, each either 0 or 1.
The output file must contain exactly one coordinate per line, written like:
 (row,col)
The coordinates must appear in path order from the starting endpoint to the ending endpoint.

How the starting point is chosen
You are not free to start from either endpoint.

You must:
identify both endpoints
choose as the starting endpoint the one with the smaller row
if the rows are tied, choose the one with the smaller column
The other endpoint is the ending point. This matters because even if you find the correct path, reversing the order would still be wrong.
How to recognize an endpoint
An endpoint is an edge pixel that has exactly one neighboring edge pixel under 4-neighbor connectivity.
So for each grid cell containing 1, students should count how many of these four positions also contain 1:
(r - 1, c)
(r + 1, c)
(r, c - 1)
(r, c + 1)
If exactly one neighbor is an edge pixel, that cell is an endpoint. The assignment guarantees there will be exactly two such cells.
How to think about the traversal
Once the starting endpoint is known, the traversal is straightforward.
At the first step, the path has only one valid neighboring edge pixel.
After that, at each step there is exactly one valid “next” edge pixel that is not the pixel you just came from.
Because the input is guaranteed to be a simple path with no branches and no cycles, you do not need a full graph-search algorithm like BFS or DFS to handle ambiguity. You mainly need a careful step-by-step walk.
How the List ADT must be used
Each pixel must be stored in the List in encoded form using:
id = row * numCols + col
Later, when writing output, students recover the coordinates using:
row = id / numCols
 col = id % numCols
The List must store the path sequentially from the starting point to the ending point, and students must use List operations to insert and traverse the sequence. That is a required part of the assignment, not just a suggestion.

Most mistakes in this assignment come from one of these categories.
Wrong endpoint detection
You accidentally count diagonal neighbors, or forget to check bounds before reading neighboring cells.
Starting at the wrong endpoint
You find both endpoints but forget the tie-breaking rule based on row first, then column.
Wrong next-step logic
You do not correctly avoid going back to the previous pixel, so they can bounce back and forth instead of progressing along the path.
Storing coordinates incorrectly
You forget to encode coordinates as row * numCols + col, or decode them incorrectly when printing.
Output formatting mistakes
You print extra spaces, omit parentheses, or print to stdout instead of writing to the output file.
Not using the List ADT properly
You use an array or some other structure to simulate the final ordered path, which violates the assignment rules.
