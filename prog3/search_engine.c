#include "search_engine.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
 * normalize_word
 *
 * TODO:
 * - Convert uppercase letters to lowercase.
 * - Copy only alphanumeric characters into output.
 * - Skip punctuation and other non-alphanumeric characters.
 * - Always null-terminate output when output_size > 0.
 * - Return true if output is non-empty; otherwise return false.
 */
bool normalize_word(const char *input, char *output, size_t output_size) {
    (void)input;
    (void)output;
    (void)output_size;

    // TODO: Implement word normalization.
    return false;
}

/*
 * create_search_engine
 *
 * TODO:
 * - Open documents_filename.
 * - Read the number of documents.
 * - Allocate a SearchEngine.
 * - Allocate the Document array.
 * - For each document:
 *     - read the DOC <doc_id> line
 *     - store the document in engine->documents[doc_id]
 *     - set engine->documents[doc_id].doc_id to doc_id
 *     - create a Dictionary using DOCUMENT_BUCKETS
 *     - store that Dictionary in engine->documents[doc_id].index
 *     - call build_document_index to read until END
 * - Close the file.
 * - Return the created SearchEngine.
 *
 * The starter tests use valid document input files.
 */
SearchEngine *create_search_engine(const char *documents_filename) {
    (void)documents_filename;

    // TODO: Implement search engine creation and document indexing.
    FILE *f_in = fopen(documents_filename, "r");
    if(f_in == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", documents_filename);
        return NULL;
    }
    

}

/*
 * destroy_search_engine
 *
 * TODO:
 * - Destroy each document dictionary.
 * - Free the document array.
 * - Free the SearchEngine.
 * - Set *pEngine to NULL.
 */
void destroy_search_engine(SearchEngine **pEngine) {
    (void)pEngine;

    for(int i = 0; i < (*pEngine)->num_documents; i++) {
        dictionary_destroy(&(*pEngine)->documents[i].index);
    }

    free((*pEngine)->documents);

    free(*pEngine);

    *pEngine = NULL;
}

/*
 * add_word_to_document
 *
 * TODO:
 * - Use dictionary_find to check whether word exists.
 * - If missing, use dictionary_insert(word, 1).
 * - If present, use dictionary_update(word, old_value + 1).
 */
bool add_word_to_document(Document *doc, const char *word) {
    (void)doc;
    (void)word;

    dictionary_find(doc->index, word, NULL);

    if(dictionary_find(doc->index, word, NULL) == NULL) {
        dictionary_insert(doc->index, word, 1);

    } else {
        int old_value;

        dictionary_find(doc->index, word, &old_value);

        dictionary_update(doc->index, word, &old_value + 1);
    }

    return true;
}

/*
 * build_document_index
 *
 * TODO:
 * - Read lines from in until the line "END".
 * - Split each text line into whitespace-separated tokens.
 * - Normalize each token.
 * - Ignore empty normalized tokens.
 * - Add each normalized word to doc.
 */
bool build_document_index(Document *doc, FILE *in) {
    (void)doc;
    (void)in;

    // TODO: Implement document indexing.
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, in) != NULL) {
        if(strcmp(line, "END\n") == 0) {
            break;
        }
        char *token = strtok(line, " \t\n");
        while(token != NULL) {
            char normalized[MAX_WORD_LENGTH];
            if(normalize_word(token, normalized, MAX_WORD_LENGTH)) {
                add_word_to_document(doc, normalized);
            }
            token = strtok(NULL, " \t\n");
        }
    }
}

/*
 * get_word_count
 *
 * TODO:
 * - Use dictionary_find.
 * - Return the stored frequency if found.
 * - Return 0 otherwise.
 */
int get_word_count(Document *doc, const char *word) {
    (void)doc;
    (void)word;

    // TODO: Implement lookup.
    dictionary_find(doc->index, word, NULL);

    for(int i = 0; i < doc->index->num_buckets; i++) {
        KVPair *kv = doc->index->buckets[i];

        while(kv != NULL) {
            if(strcmp(kv->key, word) == 0) {

                return kv->value;
            }

            kv = kv->next;
        }
    }

    return 0;
}

/*
 * score_document
 *
 * TODO:
 * - For each normalized query word, add its frequency in doc.
 * - Repeated query words count each time they appear.
 */
int score_document(Document *doc, char query_words[][MAX_WORD_LENGTH], int num_words) {
    (void)doc;
    (void)query_words;
    (void)num_words;

    // TODO: Implement scoring.
    int freq_score = 0;

    for(int i = 0; i < num_words; i++) {
        freq_score += get_word_count(doc, query_words[i]);
    }

    return freq_score;
}

/*
 * process_count_command
 *
 * Output format:
 * COUNT <doc_id> <word>: <frequency>
 */
void process_count_command(SearchEngine *engine, int doc_id, const char *word) {
    (void)engine;
    (void)doc_id;
    (void)word;

    // TODO: Normalize word, compute frequency, and print the required output.
    char normalized[MAX_WORD_LENGTH];
    if(normalize_word(word, normalized, MAX_WORD_LENGTH)) {
        int freq = get_word_count(&engine->documents[doc_id], normalized);

        printf("COUNT %d %s: %d\n", doc_id, word, freq);

    } else {
        printf("COUNT %d %s: 0\n", doc_id, word);

    }
}

/*
 * process_search_command
 *
 * Output format if there is a match:
 * SEARCH <query>: document <doc_id> score <score>
 *
 * Output format if all scores are 0:
 * SEARCH <query>: no match
 *
 * Tie-breaking:
 * - If multiple documents have the same score, choose the smaller document ID.
 */
void process_search_command(SearchEngine *engine, const char *query_text) {
    (void)engine;
    (void)query_text;

    char query_copy[MAX_LINE_LENGTH];

    strncpy(query_copy, query_text, MAX_LINE_LENGTH);

    query_copy[MAX_LINE_LENGTH - 1] = "\0";
}

/*
 * process_remove_command
 *
 * Output if removed:
 * REMOVE <doc_id> <word>: removed
 *
 * Output if missing:
 * REMOVE <doc_id> <word>: not found
 */
void process_remove_command(SearchEngine *engine, int doc_id, const char *word) {
    (void)engine;
    (void)doc_id;
    (void)word;

    if(dictionary_find(engine->documents[doc_id].index, word, NULL) == NULL) {
        printf("REMOVE %d %s: not found\n", doc_id, word);

    } else {
        dictionary_remove(engine->documents[doc_id].index, word);

        printf("REMOVE %d %s: removed\n", doc_id, word);
    }
}

/*
 * process_print_command
 *
 * Output format:
 * PRINT <doc_id>:
 * <dictionary contents>
 */
void process_print_command(SearchEngine *engine, int doc_id) {
    (void)engine;
    (void)doc_id;

    printf("PRINT %d:\n", doc_id);
    dictionary_print(engine->documents[doc_id].index);
}

/*
 * process_command
 *
 * TODO:
 * - Parse the command name.
 * - Dispatch to the matching command handler.
 *
 * Supported commands:
 * - COUNT <doc_id> <word>
 * - SEARCH <word1> <word2> ...
 * - REMOVE <doc_id> <word>
 * - PRINT <doc_id>
 *
 * The starter tests use valid commands.
 */
void process_command(SearchEngine *engine, char *line) {
    (void)engine;
    (void)line;

    if(strncmp(line, "COUNT", 5) == 0) {
        int doc_id;
        char word[MAX_WORD_LENGTH];

        sscanf(line, "COUNT %d %s", &doc_id, word);

        process_count_command(engine, doc_id, word);

    } else if(strncmp(line, "SEARCH", 6) == 0) {
        char query_text[MAX_LINE_LENGTH];

        sscanf(line, "SEARCH %[^\n]", query_text);

        process_search_command(engine, query_text);

    } else if(strncmp(line, "REMOVE", 6) == 0) {
        int doc_id;
        char word[MAX_WORD_LENGTH];

        sscanf(line, "REMOVE %d %s", &doc_id, word);

        process_remove_command(engine, doc_id, word);

    } else if(strncmp(line, "PRINT", 5) == 0) {
        int doc_id;

        sscanf(line, "PRINT %d", &doc_id);

        process_print_command(engine, doc_id);

    } else {
        fprintf(stderr, "Error: Unknown command\n");
    }
}
