/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

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
 
typedef struct node
{
    char w[LENGTH];
    struct node* next;
}node;    
 
bool load(const char* dictionary)
{
    // TODO
    //printf("%c",dictionary[1]);
    
    node* table[26];
    int i;   
      
    for(i=0; i<26; i++)
    {
        table[i]->next = NULL;  
    }
    //printf("Made..");
    //free(table);
  
    //char temp[LENGTH];
    int j=0; 
    //temp[i]=dictionary[0];
    while((dictionary[j] != EOF)||(dictionary[j] != '\0')) 
    {
          node *newnode = malloc(sizeof(node));
          newnode->next = NULL;
          i=0;
          while((j!='\n')||(j!=EOF))
          {
                newnode->w[i++] = dictionary[j++];
          }
          if (j=='\n')
            j++;
          newnode->w[i] = '\0';
          int k = (tolower(newnode->w[0])-97);
          node *p = table[k];
          while(p->next != NULL)
          {
                p = p->next;
          }
          p->next = newnode;
          //free(p);
          //free(newnode);
    }  
    if(dictionary[j] == EOF)
        return true;
    else
        return false;
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
