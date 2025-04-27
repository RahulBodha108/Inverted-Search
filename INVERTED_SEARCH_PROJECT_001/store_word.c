#include "inverted_search.h"

void store_word(char *str, char *filename, main_node **arr) {
    main_node *mainnode, *temp1 = NULL, *prev1 = NULL;
    sub_node *subnode, *temp2 = NULL, *prev2 = NULL;
    int index;

    // Determine index based on the first character of the word
    if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
        index = tolower(str[0]) - 97;
    else
        index = 26;

    // If index is empty, initialize new main node and sub node
    if (arr[index] == NULL) {
        mainnode = malloc(sizeof(main_node));
        if (mainnode == NULL) {
            printf("Memory allocation failure\n");
            return;
        }
        strcpy(mainnode->word, str);
        mainnode->file_count = 1;
        mainnode->main_link = NULL;

        subnode = malloc(sizeof(sub_node));
        if (subnode == NULL) {
            printf("Memory allocation failure\n");
            free(mainnode);
            return;
        }
        subnode->word_count = 1;
        strcpy(subnode->file_name, filename);
        subnode->sub_link = NULL;

        mainnode->sub_link = subnode;
        arr[index] = mainnode;
    } else {
        temp1 = arr[index];
        prev1 = NULL;

        // Traverse main nodes to find or add the word
        while (temp1 != NULL) {
            if (strcmp(temp1->word, str) == 0)
                break;

            prev1 = temp1;
            temp1 = temp1->main_link;
        }

        // If word is not found, create a new main node
        if (temp1 == NULL) {
            mainnode = malloc(sizeof(main_node));
            if (mainnode == NULL) {
                printf("Memory allocation failure\n");
                return;
            }
            strcpy(mainnode->word, str);
            mainnode->file_count = 1;
            mainnode->main_link = NULL;

            subnode = malloc(sizeof(sub_node));
            if (subnode == NULL) {
                printf("Memory allocation failure\n");
                free(mainnode);
                return;
            }
            subnode->word_count = 1;
            strcpy(subnode->file_name, filename);
            subnode->sub_link = NULL;

            mainnode->sub_link = subnode;
            prev1->main_link = mainnode;
        } else {
            temp2 = temp1->sub_link;
            prev2 = NULL;

            // Traverse sub nodes to update or add file entry
            while (temp2 != NULL) {
                if (strcmp(temp2->file_name, filename) == 0) {
                    temp2->word_count++;
                    return;
                }

                prev2 = temp2;
                temp2 = temp2->sub_link;
            }

            // If file entry does not exist, add a new sub node
            if (temp2 == NULL) {
                temp1->file_count++;
                subnode = malloc(sizeof(sub_node));
                if (subnode == NULL) {
                    printf("Memory allocation failure\n");
                    return;
                }
                subnode->word_count = 1;
                strcpy(subnode->file_name, filename);
                subnode->sub_link = NULL;

                prev2->sub_link = subnode;
            }
        }
    }
}

