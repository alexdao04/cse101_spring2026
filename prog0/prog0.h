#ifndef PROG0_H
#define PROG0_H

// header file in case i want to split my code
// might make stuff a bit cleaner for organizational purposes
typedef struct {
    int disk;
    int from;
    int to;
} Move;

void print_usage(void);
void print_not_implemented(void);
void print_move_line(int disk, char from, char to);
int solve_standard(int n, char from, char aux, char to);
void run_standard(int n);
int solve_bicolor(int p, char from, char aux, char to);
void run_bicolor(int p);
int parse_positive_int(const char *s, int *out);

#endif 