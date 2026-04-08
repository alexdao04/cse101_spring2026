#include <stdio.h>
#include <stdlib.h>

// Name: Alexander Dao
// Class: CSE 101, Prof. Alex Pang
// Date: 4/7/2026

// Tower of Hanoi: recursion in C
// inputs: version number where 1 is standard ToH, 2 is bicolor ToH, and 3 is monochrome ToH with n number of disks or p number of pairs
// outputs: semakequence of steps needed to transfer n disks from start peg to end peg, and total number of steps needed

typedef struct { // struct for tracking each move (disk #, from peg, to peg)
		int disk; // disk number being moved
		int from; // where the disk came from (peg number 1 2 3 for ABC)
		int to; // where the disk is going to (peg number 1 2 3 for ABC)
} Move;

static void print_usage(void) {
		printf("Usage: prog0 <version> <n/p>\n"); // print usage msg
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

static int solve_standard(int n, int from, int aux, int to) {
// standard Tower of Hanoi recursion
		if(n == 0) {
				return 0;
		}

		int moves = 0; // track moves needed to move n disks from peg A to peg C
		moves += solve_standard(n - 1, from, to, aux); // first move n - 1 disks from A to B, increment moves by # of moves needed to move n - 1 disks from A to B 
		print_move_line(n, from, to); // then move disk n from A to C
		moves += 1; // increment moves by 1 for this move
		moves += solve_standard(n - 1, aux, from, to); // then move n - 1 disks from B to C, increment moves by # of moves needed to move n - 1 disks from B to C
		return moves; // and done
}

static int solve_bicolor(int p, int from, int aux, int to, Move *out, int *len, int cap) {
// bicolor tower of hanoi: how it works
// To move n pairs of disks from peg A to peg C:
// Move n - 1 pairs of disks from A to B
// Move the nth pair of disks from A to C (two moves)
// Move n - 1 pairs of disks from B to C

		if(p == 0) { // assuming that there's no pairs left to move
			return 0;
		}
		int moves = 0; // we track moves needed to move n pairs of disks from peg A to peg C
		moves += solve_bicolor(p - 1, from, to, aux, out, len, cap); // increment by # of moves needed to move n - 1 pairs of disks from A to B
		moves += 2; // increment by 2 moves (instead of 1 like in standard) needed to move the nth pair from A to C
		moves += solve_bicolor(p - 1, aux, from, to, out, len, cap); // increment by # of moves needed to move n - 1 pairs of disks from B to C
		return moves; // increment by # of moves needed to move n - 1 pairs of disks from B to C
}

// static int solve_monochrome(/* args you need */) {
// // function for solving the monochrome version of the problem
// // may or may not be implemented
// }

// EACH HELPER FUNCTION ABOVE IS PRIMARILY FOR DEBUGGING PURPOSES. THANKS FOR UNDERSTANDING
// THE REAL MEAT AND BONES LIES BELOW HERE

static void run_standard(int n) {
// helper function logging number of moves as well as moves themselves
// You can only move 1 disk at a time. A move is indicated by the following string: Move disk n from peg i to peg j.
		int total = solve_standard(n, 1, 2, 3); // n is number of disks, 1 2 3 for A B C
		print_total_moves(total);
		return;
}

static void run_bicolor(int p) {
// helper function for the bicolor version of the problem
// bicolor version: each disk has two colors, the disks must be stacked in same-size pairs and can be differing colors
		int len = 0;
		int total = solve_bicolor(p, 1, 2, 3, NULL, &len, 0);
		print_total_moves(total);
		return;
}

// static void run_monochrome(int p) {
// // helper function for the monochrome problem ver
// // we might implement this or not depending on how much time we got
// }

static int parse_positive_int(const char *s, int *out) {
// this helper function parses n/p from the command line
// its an initial validity check (e.g. is n/p a positive integer)
// returning 0 if parsing succeeded and -1 if it failed (e.g. if s is not a positive integer)
		for(int i = 0; s[i] != '\0'; i++) {
			// until we reach null terminator (s is a string)
			// this reads each digit in the n/p field on command line
			// if any character is not a digit (0-9), then we return -1 for invalid input
			if(s[i] < '0' || s[i] > '9') { // s[i] is less than 0 or greater than 9
				// our digits are strings technically so they're not actual ints but individual chars
				return -1;
			}
			else {
				*out = *out * 10 + (s[i] - '0'); // convert char digit to int and set to out pointer
				// if s is "123" then we do 0 * 10 + 1 = 1, then 1 * 10 + 2 = 12, then 12 * 10 + 3 = 123
				// parses the string into int and stores it in out
			}
		}
		return 0; // assuming successful parsing for the n/p value, return 0
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
		out[(*len)++] = (Move){.disk = n, .from = from, .to = to}; // move disk n from A to C and store the move in the out array, increment len for the next move
		std_collect(n - 1, aux, from, to, out, len, cap); // move n - 1 disks from B to C
		return;
}

int main(int argc, char *argv[])
{
		if (argc != 3) { // check for correct number of arguments
			print_usage(); // then call helper function to print usage message
			return 1; // error exit
		}
		if (argv[1][0] < '1' || argv[1][0] > '3' || argv[1][1] != '\0') { // check if version number is valid (1, 2, or 3)
			print_usage(); // then call helper function to print usage message
			return 1; // error exit
		}

		run_standard(argv[2][0] - '0'); // convert char digit to int for n (number of disks) and call helper function for standard ToH
		run_bicolor(argv[2][0] - '0'); // convert char digit to int for p (number of pairs) and call helper function for bicolor ToH
		return 0;
}