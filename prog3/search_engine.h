#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include "Dictionary.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/*
 * Constants used by the search engine.
 *
 * Do not change DOCUMENT_BUCKETS. The expected PRINT output depends on
 * deterministic dictionary bucket order.
 */
#define DOCUMENT_BUCKETS 17
#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 128
#define MAX_QUERY_WORDS 64

/*
 * Document
 * Stores one document ID and one word-frequency Dictionary.
 */
typedef struct Document {
    int doc_id;
    Dictionary index;
} Document;

/*
 * SearchEngine
 * Stores all document indices.
 *
 * documents is an array indexed by document ID.
 * For example:
 * - documents[0] stores document 0
 * - documents[1] stores document 1
 * - documents[i].index stores the Dictionary for document i
 */
typedef struct SearchEngine {
    int num_documents;
    Document *documents;
} SearchEngine;

/*
 * normalize_word
 * Normalizes input according to the Prog 3 specification.
 *
 * Rules:
 * - convert uppercase letters to lowercase
 * - keep only alphanumeric characters
 * - remove punctuation and other non-alphanumeric characters
 *
 * Parameters:
 * - input: original token
 * - output: destination buffer
 * - output_size: size of destination buffer
 *
 * Return:
 * - true if the normalized word is non-empty
 * - false if the normalized word is empty
 */
bool normalize_word(const char *input, char *output, size_t output_size);

/*
 * create_search_engine
 * Opens the document input file, creates a SearchEngine, creates one Dictionary
 * per document, and builds all document indexes.
 *
 * Return:
 * - pointer to a new SearchEngine on success
 * - NULL on failure
 */
SearchEngine *create_search_engine(const char *documents_filename);

/*
 * destroy_search_engine
 * Frees all memory associated with *pEngine and sets *pEngine to NULL.
 */
void destroy_search_engine(SearchEngine **pEngine);

/*
 * add_word_to_document
 * Adds one normalized word to doc's dictionary.
 *
 * Required behavior:
 * - If the word is not found, insert it with frequency 1.
 * - If the word is found, update its frequency by adding 1.
 *
 * Return:
 * - true on success
 * - false on failure
 */
bool add_word_to_document(Document *doc, const char *word);

/*
 * build_document_index
 * Reads document text lines from in until END and builds doc's dictionary.
 *
 * Each whitespace-separated token should be normalized before insertion.
 *
 * Return:
 * - true on success
 * - false on failure
 */
bool build_document_index(Document *doc, FILE *in);

/*
 * get_word_count
 * Returns the frequency of word in doc's dictionary.
 *
 * Return:
 * - stored frequency if word exists
 * - 0 if word does not exist
 */
int get_word_count(Document *doc, const char *word);

/*
 * score_document
 * Computes the sum of frequencies for the normalized query words.
 */
int score_document(Document *doc, char query_words[][MAX_WORD_LENGTH], int num_words);

/*
 * Command handlers.
 *
 * Each handler prints the exact output required by the Prog 3 specification.
 */
void process_count_command(SearchEngine *engine, int doc_id, const char *word);
void process_search_command(SearchEngine *engine, const char *query_text);
void process_remove_command(SearchEngine *engine, int doc_id, const char *word);
void process_print_command(SearchEngine *engine, int doc_id);

/*
 * process_command
 * Parses one command line and dispatches to the correct command handler.
 */
void process_command(SearchEngine *engine, char *line);

#endif
