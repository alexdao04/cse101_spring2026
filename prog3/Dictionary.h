#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/*
 * KVPair
 * Stores one key-value pair.
 *
 * The Dictionary owns the key string stored in this pair.
 */
typedef struct KVPair {
    char *key;
    int value;
} KVPair;

/*
 * Dictionary
 * Opaque reference type for the Dictionary ADT.
 */
typedef struct DictionaryObj *Dictionary;

/*
 * dictionary_create
 * Creates a new empty dictionary with num_buckets buckets.
 *
 * Return:
 * - pointer to a new Dictionary on success
 * - NULL if allocation fails or num_buckets is 0
 */
Dictionary dictionary_create(size_t num_buckets);

/*
 * dictionary_destroy
 * Frees all heap memory associated with *pD and sets *pD to NULL.
 *
 * This function frees:
 * - all nodes
 * - all copied key strings
 * - the bucket array
 * - the Dictionary object
 *
 * If pD is NULL or *pD is NULL, the function does nothing.
 */
void dictionary_destroy(Dictionary *pD);

/*
 * dictionary_insert
 * Inserts a new key-value pair into D.
 *
 * Required behavior:
 * - If key already exists, do not insert a duplicate and return false.
 * - If key does not exist, copy the key, store the value, and insert the
 *   new node at the end of the correct bucket chain.
 * - The Dictionary owns the copied key.
 *
 * Return:
 * - true if insertion succeeds
 * - false if key already exists or allocation fails
 */
bool dictionary_insert(Dictionary D, const char *key, int value);

/*
 * dictionary_update
 * Updates the value associated with an existing key.
 *
 * Required behavior:
 * - If key exists, update its value and return true.
 * - If key does not exist, leave the dictionary unchanged and return false.
 *
 * Return:
 * - true if an existing key was updated
 * - false if key was not found
 */
bool dictionary_update(Dictionary D, const char *key, int value);

/*
 * dictionary_delete
 * Deletes the key-value pair with the given key.
 *
 * Required behavior:
 * - If key exists, remove it from the dictionary and free its node/key.
 * - If key does not exist, leave the dictionary unchanged.
 *
 * Return:
 * - true if a key-value pair was deleted
 * - false if key was not found
 */
bool dictionary_delete(Dictionary D, const char *key);

/*
 * dictionary_find
 * Searches for key in D.
 *
 * Return:
 * - pointer to the matching KVPair if key exists
 * - NULL if key does not exist
 *
 * The returned pointer points to memory owned by the Dictionary.
 * Do not free it.
 */
KVPair *dictionary_find(Dictionary D, const char *key);

/*
 * dictionary_print
 * Prints all key-value pairs in D to out.
 *
 * Required format:
 * key: value
 *
 * Each pair must be printed on its own line.
 *
 * Pairs must be printed by bucket order from bucket 0 to bucket num_buckets - 1.
 * Within each bucket, pairs must be printed in linked-list order.
 */
void dictionary_print(FILE *out, Dictionary D);

#endif
