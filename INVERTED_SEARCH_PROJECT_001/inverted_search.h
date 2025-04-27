#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -3

/* Structure for storing word count and file name */
typedef struct sub
{
    unsigned int word_count;
    char file_name[25];
    struct sub *sub_link;
} sub_node;

/* Structure for storing a word and linked list of files */
typedef struct main
{
    char word[20];
    unsigned int file_count;
    struct sub *sub_link;
    struct main *main_link;
} main_node;

/* Structure for a file list node */
typedef struct file
{
    char *file_name;
    struct file *sub_link;
} file_node;


/* Function declarations */

int insert_at_last(file_node **head, char *file_name);
int read_validate(int argc, char *argv[], file_node **head);
void print_list(file_node *head);
int create_database(file_node **head, main_node **arr);
void store_word(char *str, char *filename, main_node **arr);
void display_output(main_node **arr);
int write_databasefile(main_node **arr, char *filename);
int myatoi(char *str);
int read_datafile(main_node **arr, char *filename);
int search(char *word, main_node **arr);
#endif
