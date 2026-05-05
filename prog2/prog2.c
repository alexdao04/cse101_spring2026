#include <stdio.h>
#include "runway_scheduler.h"

/*
 * prog2.c
 *
 * Simple client program for testing the runway scheduling simulation.
 *
 * You are encouraged to add more test cases, especially edge cases involving:
 * - multiple arrivals at the same time
 * - ties in priority
 * - LAND vs TAKEOFF tie-breaking
 * - idle runway periods
 * - different completion times
 */

int main(void) {
    Flight flights[] = {
        {201, 0, TAKEOFF, 3, 3, 3},
        {202, 0, LAND,    1, 4, 4},
        {203, 1, TAKEOFF, 4, 1, 1},  // arrives earlier, lower priority
        {204, 2, LAND,    0, 1, 1}   // arrives later, higher priority
    };

    int n = sizeof(flights) / sizeof(flights[0]);

    int snapshot_times[] = {1, 2, 3, 4};
    int snapshot_count = sizeof(snapshot_times) / sizeof(snapshot_times[0]);

    simulate_runway_scheduling(flights, n, snapshot_times, snapshot_count);
    return 0;
}