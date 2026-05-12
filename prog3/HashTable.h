#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>

/*
 * ht_string2int
 * Converts a string key into an unsigned integer hash code.
 *
 * This helper is provided so that all students use the same deterministic
 * string-to-integer conversion.
 */
unsigned long ht_string2int(const char *key);

/*
 * ht_hash
 * Returns the bucket index for key in a hash table with num_buckets buckets.
 *
 * Required behavior:
 * - key is a null-terminated string
 * - num_buckets is greater than 0
 * - return value must be in the range 0 <= index < num_buckets
 */
size_t ht_hash(const char *key, size_t num_buckets);

#endif
