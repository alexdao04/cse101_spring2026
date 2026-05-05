#ifndef RUNWAY_SCHEDULER_H
#define RUNWAY_SCHEDULER_H

/*
 * runway_scheduler.h
 *
 * Interface for the runway scheduling simulation used in Prog 2.
 *
 * This program simulates two identical runways using the Priority Queue ADT
 * from HW2. Flights arrive over time and are assigned to available runways
 * according to a deterministic priority ordering.
 *
 * Do not modify function signatures in this file.
 */

#include "priority_queue.h"

#define MAX_TIME 1000
#define ENTRY_LEN 16

/*
 * Operation types.
 *
 * LAND and TAKEOFF are used as the operation field in each Flight.
 */
typedef enum {
    LAND,
    TAKEOFF
} Operation;

/*
 * Flight
 *
 * flight_id      : unique identifier for the flight
 * request_time   : time when the flight enters the system
 * operation      : LAND or TAKEOFF
 * priority       : lower value means higher priority
 * duration       : total runway time required
 * remaining_time : time left before the flight completes runway usage
 */
typedef struct {
    int flight_id;
    int request_time;
    Operation operation;
    int priority;
    int duration;
    int remaining_time;
} Flight;

/*
 * flight_comparator(A, B)
 *
 * Comparator used by the Priority Queue to order Flight objects.
 *
 * Ordering rules:
 * 1. lower priority value comes first
 * 2. if equal, LAND comes before TAKEOFF
 * 3. if equal, earlier request_time comes first
 * 4. if equal, smaller flight_id comes first
 *
 * Returns:
 *   < 0 if A has higher priority than B
 *   = 0 if A and B are equal in priority
 *   > 0 if A has lower priority than B
 */
int flight_comparator(void *A, void *B);

/*
 * simulate_runway_scheduling(flights, n, snapshot_times, snapshot_count)
 *
 * Simulates runway usage over discrete time steps starting at time 0.
 *
 * At each time step, perform the following steps in order:
 * 1. Insert all flights whose request_time == current_time into the priority queue.
 * 2. If RUNWAY0 is free, assign it the highest-priority waiting flight.
 * 3. If RUNWAY1 is free, assign it the next highest-priority waiting flight.
 * 4. Record the runway activity for the current time step.
 * 5. Decrement remaining_time for all active flights.
 * 6. If a flight reaches remaining_time == 0, it finishes at the end of this
 *    time step and its runway becomes free for the next time step.
 * 7. If current_time matches a snapshot time, print the snapshot for this time step.
 *
 * The simulation ends when:
 * - all flights have arrived
 * - the priority queue is empty
 * - both runways are idle
 *
 * Precondition:
 * - flights is an array of n valid Flight objects
 * - each flight's remaining_time has been initialized to duration
 */
void simulate_runway_scheduling(Flight flights[], int n,
                                int snapshot_times[], int snapshot_count);

/*
 * print_waiting_queue(pq)
 *
 * Prints the current waiting queue in heap-array order.
 *
 * Format:
 *   Waiting Queue: [F101 F205 F300]
 *
 * If empty:
 *   Waiting Queue: []
 */
void print_waiting_queue(PriorityQueue *pq);

/*
 * print_runway_chart(label, chart, length)
 *
 * Prints one runway's timeline from time 0 through length-1.
 *
 * Example:
 *   Runway0: [F101 F101 IDLE F204]
 */
void print_runway_chart(const char *label, char chart[][ENTRY_LEN], int length);

#endif