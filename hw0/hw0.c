#include <stdio.h>

int main(void) {
    FILE *f = fopen("output", "w");
    if (!f) return 1;

    fprintf(f, "Hello HW0\n");
    fclose(f);

    return 0;
}