#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runway_scheduler.h"

/*
 * runway_scheduler.c
 *
 * Partial implementation of the runway scheduling simulation for Prog 2.
 *
 * You must implement all required functions.
 * You may add private helper functions in this file if needed.
 */

/* ==================== Private Helper Functions ==================== */

/*
 * op_rank(op)
 *
 * Returns a ranking value used for tie-breaking:
 * - LAND should come before TAKEOFF
 *
 * You may keep this helper, remove it, or replace it with equivalent logic.
 */
static int op_rank(Operation op) {
    // TODO:
    // Return a smaller value for LAND than for TAKEOFF
    return 0;
}

/*
 * is_snapshot_time(current_time, snapshot_times, snapshot_count)
 *
 * Returns 1 if current_time appears in snapshot_times, otherwise 0.
 */
static int is_snapshot_time(int current_time, int snapshot_times[], int snapshot_count) {
    // TODO:
    // Scan the snapshot_times array and return 1 if current_time is present
    return 0;
}

/*
 * all_flights_arrived(flights, n, current_time)
 *
 * Returns 1 if no flights remain with request_time > current_time.
 */
static int all_flights_arrived(Flight flights[], int n, int current_time) {
    // TODO:
    // Return 1 only if every flight has already arrived by current_time
    return 0;
}

/*
 * label_entry(dest, flight)
 *
 * Writes the correct chart label into dest.
 *
 * If flight is NULL, write:
 *   IDLE
 *
 * Otherwise write:
 *   F<flight_id>
 *
 * Example:
 *   F101
 */
static void label_entry(char *dest, Flight *flight) {
    // TODO:
    // Use snprintf() to write either "IDLE" or "F<id>" into dest
}

/* ==================== Required Functions ==================== */

int flight_comparator(void *A, void *B) {
    /*
     * TODO:
     * Cast A and B to Flight* and compare according to the required rules:
     *
     * 1. lower priority value comes first
     * 2. if equal, LAND comes before TAKEOFF
     * 3. if equal, earlier request_time comes first
     * 4. if equal, smaller flight_id comes first
     *
     * Return:
     *   < 0 if A should come before B
     *   = 0 if they are equal
     *   > 0 if B should come before A
     */
    return 0;
}

void print_waiting_queue(PriorityQueue *pq) {
    /*
     * Prints the heap contents in array order.
     *
     * Format:
     *   Waiting Queue: [F101 F205 F300]
     *
     * If pq is empty:
     *   Waiting Queue: []
     *
     * Notes:
     * - The queue stores Flight* items
     * - Print the flight IDs with the "F" prefix
     * - Entries must be separated by a single space
     * - No trailing spaces inside brackets
     */
    // TODO
}

void print_runway_chart(const char *label, char chart[][ENTRY_LEN], int length) {
    /*
     * Prints one runway chart in this format:
     *   Runway0: [F101 F101 IDLE F204]
     *
     * Notes:
     * - Entries must be separated by a single space
     * - No trailing spaces inside brackets
     * - If length == 0, print empty brackets
     */
    // TODO
}

void simulate_runway_scheduling(Flight flights[], int n,
                                int snapshot_times[], int snapshot_count) {
    /*
     * Suggested simulation variables:
     * - PriorityQueue pq;
     * - int current_time = 0;
     * - Flight *runway0 = NULL;
     * - Flight *runway1 = NULL;
     * - char runway0_chart[MAX_TIME][ENTRY_LEN];
     * - char runway1_chart[MAX_TIME][ENTRY_LEN];
     *
     * Overall strategy:
     *
     * 1. Initialize the priority queue with flight_comparator
     * 2. Set current_time = 0
     * 3. Repeatedly simulate one discrete time step using the exact order below until the end condition is met
     *
     * At each time step, perform the following steps in order:
     *   a. Insert all flights whose request_time == current_time
     *   b. If runway0 is free, assign the highest-priority waiting flight
     *   c. If runway1 is free, assign the next highest-priority waiting flight
     *   d. Record labels for both runways at index current_time
     *   e. Decrement remaining_time for any active runway flights
     *   f. If a flight reaches remaining_time == 0, it finishes at the end
     *      of this time step and the runway becomes free for the NEXT time step
     *   g. If current_time is a snapshot time, print:
     *        Snapshot at time <current_time>
     *        Waiting Queue: [...]
     *        Runway0: [...]
     *        Runway1: [...]
     *
     * 4. After the loop ends, print:
     *      Final Schedule
     *      Runway0: [...]
     *      Runway1: [...]
     *
     * Important:
     * - Both runways are identical
     * - Scheduling is non-preemptive
     * - Highest-priority waiting flight goes to RUNWAY0 first,
     *   then next highest goes to RUNWAY1
     * - Use the Priority Queue ADT from HW2
     * - Stop only when:
     *      all flights have arrived,
     *      pq is empty,
     *      runway0 is idle,
     *      runway1 is idle
     */

    PriorityQueue pq;
    int current_time = 0;
    Flight *runway0 = NULL;
    Flight *runway1 = NULL;
    char runway0_chart[MAX_TIME][ENTRY_LEN];
    char runway1_chart[MAX_TIME][ENTRY_LEN];

    // Optional: initialize chart entries to empty strings
    for (int i = 0; i < MAX_TIME; i++) {
        runway0_chart[i][0] = '\0';
        runway1_chart[i][0] = '\0';
    }

    // TODO:
    // 1. initialize pq
    // 2. implement the simulation loop described above
    // 3. print snapshots at requested times
    // 4. print final schedule
    // 5. destroy pq before returning
}