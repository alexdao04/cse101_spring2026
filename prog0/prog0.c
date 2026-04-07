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

static void print_usage(void);

static void print_not_implemented(void);

static void print_move_line(int disk, int from, int to);

static void print_total_moves(int total);

static void print_peg_header(char peg_name);

static void print_disk_line(int disk);

static void run_standard(int n);

static void run_bicolor(int pairs);

static void run_monochrome(int pairs);

static int parse_positive_int(const char *s, int *out);

static void std_collect(int n, int from, int aux, int to, Move *out, int *len, int cap) {
		if(n == 0) {
			return;
		}
		std_collect(n - 1, from, to, aux, out, len, cap);
		out[(*len)++] = (Move){.disk = n, .from = from, .to = to};
		std_collect(n - 1, aux, from, to, out, len, cap);
}

static int solve_bicolor(/* args you need */);

static int solve_monochrome(/* args you need */);

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