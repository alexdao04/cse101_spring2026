// Tower of Hanoi: recursion in C
// inputs: version number where 1 is standard ToH, 2 is bicolor ToH, and 3 is monochrome ToH with n number of disks or p number of pairs
// outputs: sequence of steps needed to transfer n disks from start peg to end peg, and total number of steps needed

// For standard Tower of Hanoi, to move n disks from peg A to peg C:
// Move n - 1 disks from A to B
// Move disk n from A to C
// Move n - 1 disks from B to C

#include <stdio.h>
#include <stdlib.h>

typedef struct {
		int disk;
		int from;
		int to;
} Move;

static void print_usage(void) {
// usage message for how to run the program
		printf("Usage: %s <version> <n/p>\n", argv[0]);
		// check args for validity (e.g. version is 1, 2, 3 for regular, bicolor, monochrome, n/p is a positive integer for disks/pairs)
		printf("version: 1 for standard ToH, 2 for bicolor ToH, 3 for monochrome ToH \n");
		printf("n/p: number of disks for standard ToH, number of pairs for bicolor\n");
		return 0; // exit
}

static void print_not_implemented(void) {
// message for reserved modes (e.g. bicolor)
// we aren't going to worry about this yet until the basic ToH is implemented
		printf("Mode not implemented yet.\n");
		return 0; // exit
}

static void print_move_line(int disk, int from, int to) {
// helper function for printing move info (helpful to debug)
		printf("Move disk %d from peg %d to peg %d\n", disk, from, to);
		return 0; // exit
}

// EACH HELPER FUNCTION ABOVE IS PRIMARILY FOR DEBUGGING PURPOSES. THANKS FOR UNDERSTANDING

static void print_total_moves(int total);
// helper function for printing total number of moves (calculation logic)


static void print_peg_header(char peg_name);
// helper function for printing peg header (e.g. Peg A, B, C)


static void print_disk_line(int disk);
// helper function for printing disk info


static void run_standard(int n);
// helper function logging number of moves as well as moves themselves


static void run_bicolor(int pairs);
// helper function for the bicolor version of the problem
// bicolor version: each disk has two colors, the disks must be stacked in same-size pairs and can be differing colors



// IGNORE BELOW FOR NOW
// static void run_monochrome(int pairs);
// THIS CAN BE FIGURED OUT LATER ONCE WE GET THE BASIC IMPLEMENTATION


static int parse_positive_int(const char *s, int *out);
// helper function for parsing positive integers from cli (e.g. number of disks/pairs)


static void std_collect(int n, int from, int aux, int to, Move *out, int *len, int cap) {
		if(n == 0) { // base case, assumes there's no disks left to move
			return;
		}
		std_collect(n - 1, from, to, aux, out, len, cap);
		out[(*len)++] = (Move){.disk = n, .from = from, .to = to};
		std_collect(n - 1, aux, from, to, out, len, cap);
}

static int solve_bicolor(int n, int from, int aux, int to, Move *out, int *len, int cap) {
		if(n == 0) { // assuming that there's no disks left to move
			return 0;
		}
}

// IGNORE BELOW FOR NOW
// static int solve_monochrome(/* args you need */);
// THIS CAN BE FIGURED OUT LATER ONCE WE GET THE BASIC IMPLEMENTATION!

int main(int argc, char *argv[])
{
		if (argc != 3) {
			print_usage();
			return 0;
}

/* parse mode and k */
/* dispatch to the correct mode */
/* reserved mode -> print_not_implemented(); */

		return 0;
}