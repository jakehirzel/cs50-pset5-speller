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

// declare root instance of the struct
dictionary_node* root;

// declare word counter
int word_counter = 0;

// define function to malloc and initialize new node to 0 and return a pointer
dictionary_node* new_node()
{
    dictionary_node* new_node = calloc(1, sizeof(dictionary_node));
    if (new_node == NULL)
    {
        printf("Out of memory.\n");
        return 0;
    }
    else
    {
        return new_node;
    }
}

// define function to free malloc'd memory from nodes
void free_node(dictionary_node* free_me)
{
    for (int i = 0; i < 27; i++)
    {
        if (free_me->children[i] != NULL)
        {
            free_node(free_me->children[i]);
        }
    }
    free(free_me);
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // create temp variable to hold numerical letter value of word
    int index = 0;
    
    // create temporary crawler and assign root as value
    dictionary_node* crawler;
    crawler = root;
    
    // loop through the letters in word
    for (int i = 0; i < strlen(word); i++)
    {
        // convert letters to index 0 - 25, apostrophes to 26
        if ((int)word[i] == 39)
        {
            index = 26;
        }
        else
        {
            index = tolower(word[i]) - 'a';
        }

        // if there's a pointer traverse
        if (crawler->children[index] != NULL)
        {
            crawler = crawler->children[index];
            
            // if last letter, check is_word is true
            if (i == strlen(word) - 1)
            {
                if(crawler->is_word == true)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        
        // else (i.e. pointer NULL)
        else
        {
            return false;
        }
    }
    // if all fails
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
        // initialize empty root instance of the struct
        root = new_node();

        // declare a temp variable to hold each word and each letter of each
        char dictionary_word[LENGTH + 1];
        int index;
        
        // loop through the dictionary
        while (fscanf(dictionary_ptr, "%s", dictionary_word) != EOF)
        {
            // create a temporary crawler and assign root to crawler
            dictionary_node* crawler;
            crawler = root;
            
            // loop through letters in each word
            for (int i = 0; i < strlen(dictionary_word); i++)
            {
                // convert letters to index 0 - 25, apostrophes to 26
                if (dictionary_word[i] == 39)
                {
                    index = 26;
                }
                else
                {
                    index = tolower(dictionary_word[i]) - 'a';
                }
                
                // if there's a pointer, traverse
                if (crawler->children[index] != 0)
                {
                    crawler = crawler->children[index];
                    
                    // if last letter, set is_word
                    if (i == strlen(dictionary_word) - 1)
                    {
                        crawler->is_word = true;
                        word_counter++;
                    }
                    
                }
            
                // else make a new node and traverse
                else
                {
                    crawler->children[index] = new_node();
                    crawler = crawler->children[index];
                    
                    // if last letter, set is_word
                    if (i == strlen(dictionary_word) - 1)
                    {
                        crawler->is_word = true;
                        word_counter++;
                    }
                }
            }
        }
    }
    
    // close dictionary file
    fclose(dictionary_ptr);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // free malloc'd memory
    free_node(root);
    return true;
}
