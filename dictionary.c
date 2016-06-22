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

// put one zeroed out node on the stack for initialization
dictionary_node zero_node = {0};

// define function to malloc and initialize new node to 0 and return a pointer
dictionary_node* new_node()
{
    dictionary_node* new_node = malloc(sizeof(dictionary_node));
    if (new_node == NULL)
    {
        printf("Out of memory.\n");
        return 0;
    }
    else
    {
        *new_node = zero_node;
        return new_node;
    }
}


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
        // create empty root instance of the struct
        dictionary_node* root;
        root = new_node();

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
                
                // if there's a pointer, traverse
                if (crawler->children[index] != 0)
                {
                    crawler = crawler->children[index];
                    
                    // if last letter, set is_word
                    if (i == strlen(dictionary_word) - 1)
                    {
                        crawler->is_word = true;
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
                    }
                }
            }
        }
        
        // TEST: print cat and caterpillar from the trie
        printf("is_word: %i\n", root->is_word);
        printf("0: %p\n", root->children[0]);
        printf("1: %p\n", root->children[1]);
        printf("2: %p\n", root->children[2]);
        printf("3: %p\n", root->children[3]);
        printf("4: %p\n", root->children[4]);
        printf("5: %p\n", root->children[5]);
        printf("6: %p\n", root->children[6]);
        printf("7: %p\n", root->children[7]);
        printf("8: %p\n", root->children[8]);
        printf("9: %p\n", root->children[9]);
        printf("10: %p\n", root->children[10]);
        printf("11: %p\n", root->children[11]);
        printf("12: %p\n", root->children[12]);
        printf("13: %p\n", root->children[13]);
        printf("14: %p\n", root->children[14]);
        printf("15: %p\n", root->children[15]);
        printf("16: %p\n", root->children[16]);
        printf("17: %p\n", root->children[17]);
        printf("18: %p\n", root->children[18]);
        printf("19: %p\n", root->children[19]);
        printf("20: %p\n", root->children[20]);
        printf("21: %p\n", root->children[21]);
        printf("22: %p\n", root->children[22]);
        printf("23: %p\n", root->children[23]);
        printf("24: %p\n", root->children[24]);
        printf("25: %p\n", root->children[25]);
        printf("26: %p\n", root->children[26]);
        
        printf("is_word: %i\n", root->children[2]->is_word);
        printf("0: %p\n", root->children[2]->children[0]);
        printf("1: %p\n", root->children[2]->children[1]);
        printf("2: %p\n", root->children[2]->children[2]);
        printf("3: %p\n", root->children[2]->children[3]);
        printf("4: %p\n", root->children[2]->children[4]);
        printf("5: %p\n", root->children[2]->children[5]);
        printf("6: %p\n", root->children[2]->children[6]);
        printf("7: %p\n", root->children[2]->children[7]);
        printf("8: %p\n", root->children[2]->children[8]);
        printf("9: %p\n", root->children[2]->children[9]);
        printf("10: %p\n", root->children[2]->children[10]);
        printf("11: %p\n", root->children[2]->children[11]);
        printf("12: %p\n", root->children[2]->children[12]);
        printf("13: %p\n", root->children[2]->children[13]);
        printf("14: %p\n", root->children[2]->children[14]);
        printf("15: %p\n", root->children[2]->children[15]);
        printf("16: %p\n", root->children[2]->children[16]);
        printf("17: %p\n", root->children[2]->children[17]);
        printf("18: %p\n", root->children[2]->children[18]);
        printf("19: %p\n", root->children[2]->children[19]);
        printf("20: %p\n", root->children[2]->children[20]);
        printf("21: %p\n", root->children[2]->children[21]);
        printf("22: %p\n", root->children[2]->children[22]);
        printf("23: %p\n", root->children[2]->children[23]);
        printf("24: %p\n", root->children[2]->children[24]);
        printf("25: %p\n", root->children[2]->children[25]);
        printf("26: %p\n", root->children[2]->children[26]);    
        
        printf("is_word: %i\n", root->children[2]->children[0]->is_word);
        printf("0: %p\n", root->children[2]->children[0]->children[0]);
        printf("1: %p\n", root->children[2]->children[0]->children[1]);
        printf("2: %p\n", root->children[2]->children[0]->children[2]);
        printf("3: %p\n", root->children[2]->children[0]->children[3]);
        printf("4: %p\n", root->children[2]->children[0]->children[4]);
        printf("5: %p\n", root->children[2]->children[0]->children[5]);
        printf("6: %p\n", root->children[2]->children[0]->children[6]);
        printf("7: %p\n", root->children[2]->children[0]->children[7]);
        printf("8: %p\n", root->children[2]->children[0]->children[8]);
        printf("9: %p\n", root->children[2]->children[0]->children[9]);
        printf("10: %p\n", root->children[2]->children[0]->children[10]);
        printf("11: %p\n", root->children[2]->children[0]->children[11]);
        printf("12: %p\n", root->children[2]->children[0]->children[12]);
        printf("13: %p\n", root->children[2]->children[0]->children[13]);
        printf("14: %p\n", root->children[2]->children[0]->children[14]);
        printf("15: %p\n", root->children[2]->children[0]->children[15]);
        printf("16: %p\n", root->children[2]->children[0]->children[16]);
        printf("17: %p\n", root->children[2]->children[0]->children[17]);
        printf("18: %p\n", root->children[2]->children[0]->children[18]);
        printf("19: %p\n", root->children[2]->children[0]->children[19]);
        printf("20: %p\n", root->children[2]->children[0]->children[20]);
        printf("21: %p\n", root->children[2]->children[0]->children[21]);
        printf("22: %p\n", root->children[2]->children[0]->children[22]);
        printf("23: %p\n", root->children[2]->children[0]->children[23]);
        printf("24: %p\n", root->children[2]->children[0]->children[24]);
        printf("25: %p\n", root->children[2]->children[0]->children[25]);
        printf("26: %p\n", root->children[2]->children[0]->children[26]);    

        printf("is_word: %i\n", root->children[2]->children[0]->children[19]->is_word);
        printf("0: %p\n", root->children[2]->children[0]->children[19]->children[0]);
        printf("1: %p\n", root->children[2]->children[0]->children[19]->children[1]);
        printf("2: %p\n", root->children[2]->children[0]->children[19]->children[2]);
        printf("3: %p\n", root->children[2]->children[0]->children[19]->children[3]);
        printf("4: %p\n", root->children[2]->children[0]->children[19]->children[4]);
        printf("5: %p\n", root->children[2]->children[0]->children[19]->children[5]);
        printf("6: %p\n", root->children[2]->children[0]->children[19]->children[6]);
        printf("7: %p\n", root->children[2]->children[0]->children[19]->children[7]);
        printf("8: %p\n", root->children[2]->children[0]->children[19]->children[8]);
        printf("9: %p\n", root->children[2]->children[0]->children[19]->children[9]);
        printf("10: %p\n", root->children[2]->children[0]->children[19]->children[10]);
        printf("11: %p\n", root->children[2]->children[0]->children[19]->children[11]);
        printf("12: %p\n", root->children[2]->children[0]->children[19]->children[12]);
        printf("13: %p\n", root->children[2]->children[0]->children[19]->children[13]);
        printf("14: %p\n", root->children[2]->children[0]->children[19]->children[14]);
        printf("15: %p\n", root->children[2]->children[0]->children[19]->children[15]);
        printf("16: %p\n", root->children[2]->children[0]->children[19]->children[16]);
        printf("17: %p\n", root->children[2]->children[0]->children[19]->children[17]);
        printf("18: %p\n", root->children[2]->children[0]->children[19]->children[18]);
        printf("19: %p\n", root->children[2]->children[0]->children[19]->children[19]);
        printf("20: %p\n", root->children[2]->children[0]->children[19]->children[20]);
        printf("21: %p\n", root->children[2]->children[0]->children[19]->children[21]);
        printf("22: %p\n", root->children[2]->children[0]->children[19]->children[22]);
        printf("23: %p\n", root->children[2]->children[0]->children[19]->children[23]);
        printf("24: %p\n", root->children[2]->children[0]->children[19]->children[24]);
        printf("25: %p\n", root->children[2]->children[0]->children[19]->children[25]);
        printf("26: %p\n", root->children[2]->children[0]->children[19]->children[26]);
        
        printf("is_word: %i\n", root->children[2]->children[0]->children[19]->children[4]->children[17]->children[15]->children[8]->children[11]->children[11]->children[0]->children[17]->is_word);

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
