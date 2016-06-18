/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
        // create empty root instance of the struct, error check
        dictionary_node* root = malloc(sizeof(dictionary_node));
        if (root == NULL)
        {
            printf("Out of memory.\n");
            return 99;
        }
        else
        {
            root->is_word = false;
            root->children[27] = {0};
        }
        
        // declare a temp variable to hold each word and each letter of each
        char dictionary_word[46] = {0};
        int index = 0;
        
        // loop through the dictionary
        while (fscanf(dictionary_ptr, "%s", dictionary_word) != EOF)
        {
            // create a temporary crawler and assign root to crawler
            dictionary_node* crawler;
            crawler = root;
            
            // loop through letters in each word
            for (int i = 0; i < strlen(dictionary_word); i++)
            {
                // change case, get numerical value of letter, assign to index
                index = tolower(dictionary_word[i]) - 'a';
                
                // traverse if there's an appropriate pointer
                while (crawler->children[index] != 0)
                {
                    crawler = crawler->children[index];
                }
                
                // otherwise made a new node
                crawler->children[index] = malloc(sizeof(dictionary_node));
                if (crawler->children[index] == NULL)
                {
                    printf("Out of memory.\n");
                    return 99;
                }
                else
                {
                    crawler->is_word = false;
                    crawler->children[27] = {0};
                }
            }
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
