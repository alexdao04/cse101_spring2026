#include <stdio.h>
#include <stdlib.h>

// Name: Alexander Dao
// Class: CSE 101, Prof. Alex Pang
// Date: 4/7/2026

// Tower of Hanoi: recursion in C
// inputs: version number where 1 is standard ToH, 2 is bicolor ToH, and 3 is monochrome ToH with n number of disks or p number of pairs
// outputs: sequence of steps needed to transfer n disks from start peg to end peg, and total number of steps needed

typedef struct { // struct for tracking each move (disk #, from peg, to peg)
		int disk; // disk number being moved
		int from; // where the disk came from
		int to; // where the disk is going to
} Move;

static void print_usage(void) {
		printf("Use one of the following:\n");
		// check args for validity
		// version 1 is standard ToH, version 2 is bicolor ToH
		// version 1 will interpret n disks whereas version 2 will interpret p pairs of disks (2 disks per pair)
		printf("Usage: prog0 1 n, 1 is standard,   n is number of disks\n");
		printf("Usage: prog0 2 p, 2 is bicolor,    p is number of pairs\n");
		printf("Usage: prog0 3 p, 3 is monochrome, p is number of pairs\n");
		return; // exit
}

static void print_not_implemented(void) {
// message for modes that havent been implemented like monochrome
		if (1) { // placeholder condition for modes that haven't been implemented yet
				// e.g. if version == 3 for monochrome ToH, then we would call this function to print the message and exit
		}
		printf("Not Implemented.\n");
		return; // exit
}

static void print_move_line(int disk, char from, char to) {
// helper function for printing move info (helpful to debug)
		printf("Move disk %d from peg %c to peg %c\n", disk, from, to);
		return; // exit
}

static int solve_standard(int n, char from, char aux, char to) {
// standard Tower of Hanoi recursion
		if(n == 0) { // recursion case case
				return 0; // exit
		}
		int moves = 0; // track moves needed to move n disks from peg A to peg C
		moves += solve_standard(n - 1, from, to, aux); // first move n - 1 disks from A to B, increment moves by # of moves needed to move n - 1 disks from A to B 
		print_move_line(n, from, to); // print move info for moving disk n from A to C (also helps for debugging)
		moves += 1; // increment moves by 1 for this move (we're moving 1 disk from A to C)
		moves += solve_standard(n - 1, aux, from, to); // then move n - 1 disks from B to C, increment moves by # of moves needed to move n - 1 disks from B to C
		return moves; // and done!
}

static int reverse_bicolor(int p, char from, char aux, char to); // static declaration

static int solve_bicolor(int p, char from, char aux, char to) {
// This is similar to standard ToH except you there are n pairs of disks. Each pair has 2 disks of the same size but different colors, hence the name. Note that p pairs means you have 2n disks. Peg A initially contains the bicolored tower of disks. The goal is to move the tower to pegC. You don't need to maintain the same black/white ordering in pegC. The only change to the rules is that disks of the same size can be on top of each other.
		if(p == 0) { // assuming that there's no pairs left to move
			return 0; 
		}
		int moves = 0; // we track moves needed to move n pairs of disks from peg A to peg C
		moves += solve_bicolor(p - 1, from, to, aux); // move p - 1 pairs of disks from A to B, increment moves counter
		print_move_line(2 * p - 1, from, to); // move disk 2*p - 1 from A to C (helps w/ debugging)
		print_move_line(2 * p, from, to); // move disk 2*p from A to C (helps w/ debugging)
		moves += 2; // increment moves by 2 since we're working with 2 disks of the same size
		moves += reverse_bicolor(p - 1, aux, from, to); // move p - 1 pairs of disks from B to C, increment moves counter
		return moves; // done
}

static int reverse_bicolor(int p, char from, char aux, char to) {
// handles the case in bicolor where the order of the disks in the pairs is reversed (e.g. peg A has disk 1 on top of disk 2, but peg B has disk 2 on top of disk 1). 
// this is needed because in bicolor ToH, disks of the same size can be on top of each other, so we can have different orderings of the disks in the pairs. This function is similar to solve_bicolor but with the order of the disks reversed.
		if(p == 0) { // assuming that there's no pairs left to move
			return 0; 
		}
		int moves = 0; // we track moves needed to move n pairs of disks from peg A to peg C
		moves += reverse_bicolor(p - 1, from, to, aux); // move p - 1 pairs of disks from A to B, increment moves counter
		print_move_line(2 * p, from, to); // move disk 2*p - 1 from A to C (helps w/ debugging)
		print_move_line(2 * p - 1, from, to); // move disk 2*p from A to C (helps w/ debugging)
		moves += 2; // increment moves by 2 since we're working with 2 disks of the same size
		moves += reverse_bicolor(p - 1, aux, from, to); // move p - 1 pairs of disks from B to C, increment moves counter
		return moves; // done
}

// EACH HELPER FUNCTION ABOVE IS PRIMARILY FOR DEBUGGING PURPOSES. THANKS FOR UNDERSTANDING
// THE REAL MEAT AND BONES LIES BELOW HERE

static void run_standard(int n) {
// helper function logging number of moves as well as moves themselves
// You can only move 1 disk at a time. A move is indicated by the following string: Move disk n from peg i to peg j.
		printf("Solving standard Tower of Hanoi with %d disks.\n", n); // debugging purposes, tracks number of disks being moved
		int total = solve_standard(n, 'A', 'B', 'C'); // n is number of disks, A B C for pegs
		printf("\nHere's what's in pegC\n"); // debugging purposes, tracks what's in pegC at the end of the moves
			for(int i = 1; i <= n; i++) { // print disks in pegC from smallest to largest (1 to n)
				printf("disk %d.\n", i);
			}
		printf("\nThere are a total of %d moves required.\n", total); // debugging purposes, tracks total number of moves needed to move n disks from A to C
		return;
}

static void run_bicolor(int p) {
// helper function for the bicolor version of the problem
// bicolor version: each disk has two colors, the disks must be stacked in same-size pairs and can be differing colors
		printf("Solving bicolor Tower of Hanoi with %d pair of disks.\n", p); // debugging purposes, tracks number of pairs being moved
		int total = solve_bicolor(p, 'A', 'B', 'C'); // p is number of pairs, A B C for pegs
		printf("\nHere's what's in pegC\n"); // debugging purposes, tracks what's in pegC at the end of the moves
		for(int i = 1; i < p; i++) { // print disks in pegC from smallest to largest (1 to 2*p since we have p pairs
			printf("disk %d.\n", 2 * i - 1);
			printf("disk %d.\n", 2 * i);
		}
		printf("disk %d.\n", 2*p); // print the last disk in pegC, which is the largest disk of size 2*p (since we have p pairs, the largest disk is 2*p)
    	printf("disk %d.\n", 2*p - 1); // print the second to last disk in pegC, which is the other disk of size 2*p (since we have p pairs, the largest disk is 2*p and the second to last disk is 2*p - 1)
		printf("\nThere are a total of %d moves required.\n", total);
		return;
}

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

int main(int argc, char *argv[])
{
		if (argc != 3) { // check for correct number of arguments
			print_usage(); // then call helper function to print usage message
			return 1; // error exit
		}
		int ver = atoi(argv[1]); // convert from string to int for version number
		// args were originally strings so convert version # to int

		if (ver < 1 || ver > 3) { // check if version number is valid (1, 2, or 3)
			print_not_implemented(); // then call helper function to print usage message
			return 0; // error exit
		}
		if (ver == 1) {
				int n = 0; // variable for number of disks
				if (parse_positive_int(argv[2], &n) != 0) { // parse n from command line, check if it's a valid positive integer
						print_usage(); // if not, print usage message
						return 1; // error exit
				}
				run_standard(n); // run standard ToH with n disks
		}
		else if (ver == 2) {
				int p = 0; // variable for number of pairs of disks
				if (parse_positive_int(argv[2], &p) != 0) { // parse p from command line, check if it's a valid positive integer
						print_usage(); // if not, print usage message
						return 1; // error exit
				}
				run_bicolor(p); // run bicolor ToH with p pairs of disks
		}
		else if (ver == 3) {
				print_not_implemented(); // helper because monochrome wasnt implemented
		}
		return 0; // exit the program when done
}