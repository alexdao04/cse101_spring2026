#include "Dictionary.h"
#include "HashTable.h"

#include <stdlib.h>
#include <string.h>

/*
 * NodeObj
 * Private linked-list node used for separate chaining.
 */
typedef struct NodeObj {
    KVPair pair;
    struct NodeObj *next;
} NodeObj;

typedef NodeObj *Node;

/*
 * DictionaryObj
 * Private Dictionary representation.
 *
 * buckets:
 *   Array of linked-list heads. Each bucket stores a chain of Nodes.
 *
 * num_buckets:
 *   Number of buckets in the hash table.
 *
 * size:
 *   Number of key-value pairs currently stored.
 */
struct DictionaryObj {
    Node *buckets;
    size_t num_buckets;
    size_t size;
};

/*
 * copy_string
 * Returns a heap-allocated copy of s.
 *
 * TODO:
 * - Allocate strlen(s) + 1 bytes.
 * - Copy s into the allocated memory.
 * - Return the copy.
 * - Return NULL if allocation fails.
 */
static char *copy_string(const char *s) {
    (void)s;

    // TODO: Replace this placeholder return value.
    size_t string_length = strlen(s);

    char *str_copy = malloc(string_length + 1);

    if(str_copy == NULL) {
        return NULL;
    }

    strcpy(str_copy, s);

    return str_copy;
}

/*
 * create_node
 * Creates a new node containing a copied key and the given value.
 *
 * TODO:
 * - Allocate a NodeObj.
 * - Copy key using copy_string.
 * - Store key/value in the node's KVPair.
 * - Initialize next to NULL.
 */
static Node create_node(const char *key, int value) {
    (void)key;
    (void)value;

    // TODO: Replace this placeholder return value.
    Node new_node = malloc(sizeof(NodeObj)); // create new node to store KV entry

    if(new_node == NULL) {
        return NULL;
    }

    new_node->pair.key = copy_string(key); // copy key value pair into node

    if(new_node->pair.key == NULL) {
        free(new_node); // dangling pointer = bad, free if copy_string fails
        return NULL; 
    }

    new_node->pair.value = value; // store pair values in the node

    new_node->next = NULL; // chaining

    return new_node;

}

/*
 * destroy_node
 * Frees one node and its copied key.
 *
 * TODO:
 * - Free the copied key.
 * - Free the node.
 */
static void destroy_node(Node node) {
    (void)node;

    // TODO: Implement this helper.
    if(node != NULL) {

        free(node->pair.key);

        free(node);

    }
}

/*
 * find_node
 * Searches for key in D and returns the matching node.
 *
 * TODO:
 * - Compute the bucket index with ht_hash.
 * - Traverse the linked list at that bucket.
 * - Compare keys using strcmp.
 */
static Node find_node(Dictionary D, const char *key) {
    (void)D;
    (void)key;

    // TODO: Replace this placeholder return value.
    if(D == NULL || key == NULL) {
        return NULL;
    }

    size_t bucket_index = ht_hash(key, D->num_buckets); // use hash function to get index

    Node current = D->buckets[bucket_index]; // start at head of bucket

    while(current != NULL) {

        if(strcmp(current->pair.key, key) == 0) { // strcmp returns 0 for equal strings
            return current;
        }

    current = current->next; // move to next node in chain

    }
}


/*
 * dictionary_create
 * Creates a new empty dictionary with num_buckets buckets.
 */
Dictionary dictionary_create(size_t num_buckets) {
    (void)num_buckets;

    // TODO: Allocate and initialize a DictionaryObj.
    // TODO: Allocate and initialize the bucket array.

    // TODO: Replace this placeholder return value.
    Dictionary new_dict = malloc(sizeof(struct DictionaryObj));
    Node *buckets = malloc(num_buckets * sizeof(Node));

    if(new_dict == NULL || buckets == NULL) { // NO DANGLING POINTERS PLEASE
        free(new_dict);
        
        free(buckets);

        return NULL;
    }

    new_dict -> buckets = buckets; // assign bucket array to dictionary

    new_dict -> num_buckets = num_buckets; // assign number of buckets to dictionary

    new_dict -> size = 0;

    for(size_t i = 0; i < num_buckets; i++) {
        buckets[i] = NULL; // all buckets in the array start as NULL until otherwise

    }
}

/*
 * dictionary_destroy
 * Frees all memory owned by the dictionary and sets *pD to NULL.
 */
void dictionary_destroy(Dictionary *pD) {
    (void)pD;

    // TODO: Free every node in every bucket.
    // TODO: Free the bucket array.
    // TODO: Free the DictionaryObj.
    // TODO: Set *pD to NULL.
}

/*
 * dictionary_insert
 * Inserts a new key-value pair.
 */
bool dictionary_insert(Dictionary D, const char *key, int value) {
    (void)D;
    (void)key;
    (void)value;

    // TODO: Reject duplicate keys.
    // TODO: Create a new node.
    // TODO: Insert the new node at the end of the correct bucket chain.
    // TODO: Update dictionary size.

    // TODO: Replace this placeholder return value.
    return false;
}

/*
 * dictionary_update
 * Updates the value for an existing key.
 */
bool dictionary_update(Dictionary D, const char *key, int value) {
    (void)D;
    (void)key;
    (void)value;

    // TODO: Find the node with the given key.
    // TODO: If found, update its value and return true.
    // TODO: If not found, return false.

    // TODO: Replace this placeholder return value.
    return false;
}

/*
 * dictionary_delete
 * Deletes a key-value pair by key.
 */
bool dictionary_delete(Dictionary D, const char *key) {
    (void)D;
    (void)key;

    // TODO: Compute the bucket index.
    // TODO: Find the node to delete while tracking the previous node.
    // TODO: Relink the chain correctly.
    // TODO: Free the deleted node.
    // TODO: Update dictionary size.

    // TODO: Replace this placeholder return value.
    return false;
}

/*
 * dictionary_find
 * Returns the KVPair associated with key, or NULL if key is missing.
 */
KVPair *dictionary_find(Dictionary D, const char *key) {
    (void)D;
    (void)key;

    // TODO: Use find_node.
    // TODO: Return a pointer to the node's KVPair if found.

    // TODO: Replace this placeholder return value.
    return NULL;
}

/*
 * dictionary_print
 * Prints all key-value pairs by bucket order, then linked-list order.
 */
void dictionary_print(FILE *out, Dictionary D) {
    (void)out;
    (void)D;

    // TODO: Traverse buckets from index 0 to num_buckets - 1.
    // TODO: For each bucket, traverse the chain in order.
    // TODO: Print each pair using the required format:
    //       key: value
}
