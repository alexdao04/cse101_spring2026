#include "Dictionary.h"

#include <stdbool.h>
#include <stdio.h>

static const char *bool_string(bool value) {
    return value ? "true" : "false";
}

static void print_find_result(Dictionary D, const char *key) {
    KVPair *pair = dictionary_find(D, key);

    if (pair == NULL) {
        printf("Find %s: not found\n", key);
    } else {
        printf("Find %s: %s -> %d\n", key, pair->key, pair->value);
    }
}

int main(void) {
    Dictionary D = dictionary_create(3);

    printf("Insert apple: %s\n", bool_string(dictionary_insert(D, "apple", 3)));
    printf("Insert banana: %s\n", bool_string(dictionary_insert(D, "banana", 5)));
    printf("Insert grape: %s\n", bool_string(dictionary_insert(D, "grape", 2)));
    printf("Insert melon: %s\n", bool_string(dictionary_insert(D, "melon", 7)));
    printf("Insert pear: %s\n", bool_string(dictionary_insert(D, "pear", 4)));
    printf("Insert apple again: %s\n", bool_string(dictionary_insert(D, "apple", 99)));

    printf("\nDictionary after inserts:\n");
    dictionary_print(stdout, D);

    printf("\nUpdate grape: %s\n", bool_string(dictionary_update(D, "grape", 9)));
    printf("Update kiwi: %s\n", bool_string(dictionary_update(D, "kiwi", 1)));

    printf("\nDictionary after updates:\n");
    dictionary_print(stdout, D);

    printf("\n");
    print_find_result(D, "melon");
    print_find_result(D, "kiwi");

    printf("\nDelete apple: %s\n", bool_string(dictionary_delete(D, "apple")));
    printf("Delete melon: %s\n", bool_string(dictionary_delete(D, "melon")));
    printf("Delete kiwi: %s\n", bool_string(dictionary_delete(D, "kiwi")));

    printf("\nDictionary after deletes:\n");
    dictionary_print(stdout, D);

    dictionary_destroy(&D);

    return 0;
}
