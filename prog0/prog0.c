#include <stdio.h>
#include <stdlib.h>

// Tower of Hanoi: recursion in C
// inputs: version number where 1 is standard ToH, 2 is bicolor ToH, and 3 is monochrome ToH with n number of disks or p number of pairs
// outputs: semakequence of steps needed to transfer n disks from start peg to end peg, and total number of steps needed

typedef struct { // struct for tracking each move (disk #, from peg, to peg)
		int disk; // disk number being moved
		int from; // where the disk came from (peg number 1 2 3 for ABC)
		int to; // where the disk is going to (peg number 1 2 3 for ABC)
} Move;

static void print_usage(void) {
// usage message for how to run the program
		printf("Usage: %s <version> <n/p>\n", 0); // print usage msg with version (initialize at 0) and n/p info
		// check args for validity (e.g. version is 1, 2, 3 for regular, bicolor, monochrome, n/p is a positive integer for disks/pairs)
		printf("version: 1 for standard ToH, 2 for bicolor ToH, 3 for monochrome ToH \n");
		printf("n/p: number of disks for standard ToH, number of pairs for bicolor\n");
		return; // exit
}

static void print_not_implemented(void) {
// message for reserved modes (e.g. bicolor)
// we aren't going to worry about this yet until the basic ToH is implemented
		printf("Mode not implemented yet.\n");
		return; // exit
}

static void print_move_line(int disk, int from, int to) {
// helper function for printing move info (helpful to debug)
		printf("Move disk %d from peg %d to peg %d\n", disk, from, to);
		return; // exit
}

static void print_total_moves(int total) {
// helper function for printing total number of moves (calculation logic)
		printf("Total moves: %d\n", total); // print total moves computed from recursive functions
		return; // exit
}

static void print_peg_header(char peg_name) {
// helper function for printing peg header (e.g. Peg A, B, C)
		printf("Peg %c:\n", peg_name); // debugging purposes, tracks peg states at each step (e.g. A to C, B to C, etc.)
		return; // exit
}

static void print_disk_line(int disk) {
// helper function for printing disk info
		printf("Disk %d\n", disk); // debugging purposes, tracks disk states at each step (e.g. which disk # is being moved)
		return; // exit
}

// EACH HELPER FUNCTION ABOVE IS PRIMARILY FOR DEBUGGING PURPOSES. THANKS FOR UNDERSTANDING
// THE REAL MEAT AND BONES LIES BELOW HERE

static void run_standard(int n) {
// helper function logging number of moves as well as moves themselves
// You can only move 1 disk at a time. A move is indicated by the following string: Move disk n from peg i to peg j.

		for(int i = 0; i < n; i++) { // loop through until we reach n disks
		// call recursive functions from elsewhere as needed...
		}
}

static void run_bicolor(int pairs) {
// helper function for the bicolor version of the problem
// bicolor version: each disk has two colors, the disks must be stacked in same-size pairs and can be differing colors

		for(int i = 0; i < pairs; i++) { // loop through until we reach the pair number

		}
}

// IGNORE BELOW FOR NOW
// static void run_monochrome(int pairs);
// THIS CAN BE FIGURED OUT LATER ONCE WE GET THE BASIC IMPLEMENTATION

static int parse_positive_int(const char *s, int *out) { // *s represents the desired string to parse (disks/pairs from cli is a string)
// *out points to the integer variable where the parsed value gets stored
// helper function for parsing positive integers from cli (e.g. number of disks/pairs)

}

static void std_collect(int n, int from, int aux, int to, Move *out, int *len, int cap) {
// For standard Tower of Hanoi, to move n disks from peg A to peg C:
// Move n - 1 disks from A to B
// Move disk n from A to C
// Move n - 1 disks from B to C

		if(n == 0) { // base case, assumes there's no disks left to move
			return;
		}
		// call the function recursively
		std_collect(n - 1, from, to, aux, out, len, cap); // move n - 1 disks from A to B
		out[(*len)++] = (Move){.disk = n, .from = from, .to = to}; // move disk n from A to C
		std_collect(n - 1, aux, from, to, out, len, cap); // move n - 1 disks from B to C

}

static int solve_bicolor(int n, int from, int aux, int to, Move *out, int *len, int cap) {
		if(n == 0) { // assuming that there's no disks left to move
			return 0;
		}
		int moves = 0; // we track moves needed to move n pairs of disks from peg A to peg C
		moves += solve_bicolor(n - 1, from, to, aux, out, len, cap); // increment by # of moves needed to move n - 1 pairs of disks from A to B

}

// IGNORE BELOW FOR NOW
// static int solve_monochrome(/* args you need */);
// THIS CAN BE FIGURED OUT LATER ONCE WE GET THE BASIC IMPLEMENTATION!

int main(int argc, char *argv[])
{
		if (argc != 3) { // check for correct number of arguments
			print_usage(); // then call helper function to print usage message
			return 1; // error exit
}

/* parse mode and k */
/* dispatch to the correct mode */
/* reserved mode -> print_not_implemented(); */

		return 0;
}