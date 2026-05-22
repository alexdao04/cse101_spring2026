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

    if(output_size == 0) {
        return false;
    }

    while(input != NULL && *input != '\0') { // stop at null terminator
        if(isalnum(*input)) { 
            // isalnum() should check whether all inputs present are ALPHANUMERIC.
            if(isupper(*input)) {
                *output = tolower(*input);
            
            } else {
                *output = *input;
            }

            output++;

            output_size--; // decrease output size by 1 when we add a char to output 
            
            if(output_size == 0) {
                break; // we have no chars left to add to output
            }
        }

        input++;
    }

    *output = '\0';

    return output_size < MAX_WORD_LENGTH;
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

    FILE *f_in = fopen(documents_filename, "r");
    
    if(f_in == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", documents_filename);
        return NULL;
    }
    
    int num_docs;
    
    fscanf(f_in, "%d\n", &num_docs);
    
    SearchEngine *engine = malloc(sizeof(SearchEngine)); // allocate memory for search engine itself
    // that way we can point to its associated documents and num_documents fields
    if(engine == NULL) {
        return NULL;
    }
    
    engine -> num_documents = num_docs;
    
    engine -> documents = malloc(num_docs * sizeof(Document)); // allocate memory for each document present in file
    
    for(int i = 0; i < num_docs; i++) {
        int doc_id; // doc_id will convert to its associated index in the documents array

        fscanf(f_in, "DOC %d\n", &doc_id);

        engine -> documents[i].doc_id = doc_id;

        engine -> documents[i].index = dictionary_create(DOCUMENT_BUCKETS);

        if(engine -> documents[i].index == NULL) {
            destroy_search_engine(&engine);

            return NULL;
        }

        build_document_index(&engine -> documents[i], f_in); // build index for current document
    }

    return engine;
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

    KVPair *kv = dictionary_find(doc->index, word);

    if(kv == NULL) {
        return dictionary_insert(doc->index, word, 1); // insert with frequency 1 (dictionary has no record of this word)
    
    } else {
        return dictionary_update(doc->index, word, kv->value + 1); // increment the frequency value by 1 if previously seen
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

    char line[MAX_LINE_LENGTH];

    while(fgets(line, MAX_LINE_LENGTH, in) != NULL) {
        // fgets reads a line from the file up to max length.
        // when we reach EOF or an error occurs fgets returns NULL
        if(strncmp(line, "END", 3) == 0) {
            break;
        }

        char *token = strtok(line, " \t\n");

        while(token != NULL) {
            char normalized[MAX_WORD_LENGTH];
            // normalize token and add to document index if not empty
            if(normalize_word(token, normalized, MAX_WORD_LENGTH)) {
                add_word_to_document(doc, normalized);
            }
            // skip to next token if you see space, tab, or newline
            token = strtok(NULL, " \t\n");
        }
    }

    return true;
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

    KVPair *kv = dictionary_find(doc->index, word);

    if(kv != NULL) {
        return kv->value;
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
    // array that holds a copy of the target query
    strncpy(query_copy, query_text, MAX_LINE_LENGTH); 
    // strtok will break down the words into individual character tokens
    // preserve the original text while tokenizing the copy to check for our matches
    query_copy[MAX_LINE_LENGTH - 1] = '\0'; // null terminator to prevent out of bounds

    char *token = strtok(query_copy, " \t\n");

    char query_words[MAX_QUERY_WORDS][MAX_WORD_LENGTH]; 
    // array + counter to hold normalized query words
    int num_query_words = 0; 

    while(token != NULL && num_query_words < MAX_QUERY_WORDS) { 
        // parse query text into tokens and normalize them
        if(normalize_word(token, query_words[num_query_words], MAX_WORD_LENGTH)) {
            // if token not empty after normalization, add to query_words count
            num_query_words++;
        }

        token = strtok(NULL, " \t\n");
    }

    int best_doc_id = -1; 
    // -1 because we're before the index (start at 0)
    int best_score = 0; 
    // best score is for the document with the highest frequency of query words
    // measures how well a document matches queries
    for(int i = 0; i < engine->num_documents; i++) {
        int score = score_document(&engine->documents[i], query_words, num_query_words);

        if(score > best_score || (score == best_score && (best_doc_id == -1 || i < best_doc_id))) {
            // if current document has a better score than the best score, or if it ties with the best score but has a smaller doc_id
            best_score = score; 
            // we update our best match
            best_doc_id = i;
            // current index becomes the new best document ID
        }
    }

    if(best_score > 0 && best_doc_id != -1) { 
        // we found a match somewhere
        printf("SEARCH %s: document %d score %d\n", query_text, engine->documents[best_doc_id].doc_id, best_score);

    } else {
        printf("SEARCH %s: no match\n", query_text);
    }
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

    if(dictionary_find(engine->documents[doc_id].index, word) == NULL) {
        printf("REMOVE %d %s: not found\n", doc_id, word);

    } else {
        dictionary_delete(engine->documents[doc_id].index, word);

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

    dictionary_print(stdout, engine->documents[doc_id].index);
    // find matching document and print its dictionary contents
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
    // this just does formatting for the command output and calls the corresponding helper
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
