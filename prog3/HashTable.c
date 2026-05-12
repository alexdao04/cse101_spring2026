#include "HashTable.h"

/*
 * Prog 3 uses your Hwk 3 hash table implementation.
 * If you completed Hwk 3, you may replace this file with your completed
 * HashTable.c implementation.
 */

/*
 * ht_string2int
 * Converts a string into an unsigned integer hash code.
 *
 * Do not modify this function.
 */
unsigned long ht_string2int(const char *key) {
    unsigned long hash = 5381;
    int c;

    while ((c = (unsigned char)*key++) != '\0') {
        hash = ((hash << 5) + hash) + (unsigned long)c;  // hash * 33 + c
    }

    return hash;
}

/*
 * ht_hash
 * Returns the bucket index for key in a hash table with num_buckets buckets.
 *
 * TODO:
 * 1. Use ht_string2int(key) to compute the hash code.
 * 2. Convert that hash code into a valid bucket index.
 * 3. Return the bucket index.
 */
size_t ht_hash(const char *key, size_t num_buckets) {
    (void)key;
    (void)num_buckets;

    // TODO: Replace this placeholder return value.
    return 0;
}
