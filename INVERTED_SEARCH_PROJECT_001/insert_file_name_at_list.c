#include "inverted_search.h"

int insert_at_last(file_node **head, char *file_name) {
    // Allocate memory for new node
    file_node *new_node = malloc(sizeof(file_node));
    if (new_node == NULL) {
        return FAILURE;  // Return FAILURE if memory not allocated
    }

    // Initialize new node
    new_node->file_name = file_name;
    new_node->sub_link = NULL;
    
    // If list is empty, set new node as head
    if (*head == NULL) {
        *head = new_node;
        return SUCCESS;
    }
    
    // Traverse to the end of the list
    file_node *temp = *head;
    while (temp->sub_link != NULL) {
        temp = temp->sub_link;
    }
    
    // Link last node to new node
    temp->sub_link = new_node;
    return SUCCESS;
}

