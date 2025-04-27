#include "inverted_search.h"
#include <stdlib.h>
#include <string.h>

int create_database(file_node **head, main_node **arr) {
    file_node *temp = *head;
    FILE *fptr = NULL;
    char str[25];  // Buffer to store each word

    while (temp != NULL) {  // Traverse through all files in the list
        fptr = fopen(temp->file_name, "r");  // Open each file in read mode
        if (fptr == NULL) {  // Check if file opened successfully
            fprintf(stderr, "Error opening file: %s\n", temp->file_name);
            temp = temp->sub_link;  // Move to the next file if opening fails
            continue;
        }

        while (fscanf(fptr, "%24s", str) != EOF) {  // Read each word until the end of the file
            store_word(str, temp->file_name, arr);  // Store the word in the database
        }

        fclose(fptr);  // Close the file after processing
        temp = temp->sub_link;  // Move to the next file in the list
    }

    return 0;  // Return success
}

