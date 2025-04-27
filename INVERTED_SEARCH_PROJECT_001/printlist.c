#include "inverted_search.h"

void print_list(file_node *head)
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("INFO : List is empty\n");
    }
    else
    {
        // Traverse and print each node
        while (head)
        {
            printf("%s -> ", head->file_name);
            head = head->sub_link;
        }
        printf("NULL\n"); // End of list
    }
}
