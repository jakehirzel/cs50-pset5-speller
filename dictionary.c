/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdbool.h>

#include "dictionary.h"


// define struct for trie to hold dictionary words
typedef struct dictionary_node
{
    bool is_word; // flag to say if a node is the end of a word
    struct dictionary_node* children[27]; // pointer to child node array
} dictionary_node;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open file and error check
    FILE* dictionary_ptr = fopen(dictionary, "r");
    if (dictionary_ptr == NULL)
    {
        return false;
    }
    else
    {
        // declare root instance of the struct
        // dictionary_node* root;
        
        // declare a temp variable to hold each word
        char dictionary_word[46] = {0};
        
        // loop through the dictionary
        while (fscanf(dictionary_ptr, "%s", dictionary_word) != EOF)
        {
            // TEST print the word
            printf("%s\n", dictionary_word);
        }
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
