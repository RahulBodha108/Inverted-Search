#include "inverted_search.h"

int search(char *word, main_node **arr) {
    int index = tolower(word[0]) - 97;
    main_node *temp1 = arr[index];

    while (temp1 != NULL && strcmp(temp1->word, word) != 0) {
        temp1 = temp1->main_link;
    }

    if (temp1 == NULL) {
        return FAILURE;
    } else {
        sub_node *temp2 = temp1->sub_link;

        // Enhanced output view
        printf("\n--------------------------------------------------------\n");
        printf("Word: %s\n", temp1->word);
        printf("File Count: %d\n", temp1->file_count);
        printf("--------------------------------------------------------\n");

        while (temp2) {
            printf("File Name: %-30s Word Count: %d\n", temp2->file_name, temp2->word_count);
            temp2 = temp2->sub_link;
        }
        printf("--------------------------------------------------------\n");
    }

    return SUCCESS;
}

