#include "inverted_search.h"

void display_output(main_node **arr) {
    main_node *temp1 = NULL;
    sub_node *temp2 = NULL;

    printf("---------------------------------------------------------------------------------\n");
    printf("| Index |        Word        | File Count |        Filename        | Word Count |\n");
    printf("---------------------------------------------------------------------------------\n");

    // Loop through the main array to display each word and its file details
    for (int i = 0; i < 27; i++) {
        if (arr[i] != NULL) {
            printf("  %2d   \n", i);
            temp1 = arr[i];

            while (temp1) {
                temp2 = temp1->sub_link;
                printf("         %-18s   %10d  ", temp1->word, temp1->file_count);

                // Display file details for the word
                while (temp2) {
                    printf(" %-20s   %10d  \n", temp2->file_name, temp2->word_count);
                    printf("                                          ");
                    temp2 = temp2->sub_link;
                }
                printf("\n");
                temp1 = temp1->main_link;
            }
            printf("---------------------------------------------------------------------------------\n");
        }
    }
}

