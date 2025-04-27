#include "inverted_search.h"

int write_databasefile(main_node **arr, char *filename)
{
    main_node *temp1 = NULL;
    sub_node *temp2 = NULL;

    /* Check if filename has .txt extension */
    char *file = strstr(filename, ".txt");
    if (file == NULL)
    {
        printf("Error: Please provide .txt extension file\n");
        return FAILURE;
    }

    /* Open the file in write mode */
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf("%s file not opened\n",filename);
        return FAILURE;
    }

    /* Write sorted words and file details to DatabaseFile */
    for (int i = 0; i < 27; i++)
    {
        if (arr[i] != NULL)
        {
            temp1 = arr[i];
            fprintf(fptr, "#%d#\n", i);  // Index header for each character

            while (temp1)
            {
                temp2 = temp1->sub_link;
                fprintf(fptr, "%s,%d", temp1->word, temp1->file_count);  // Write word and file count

                while (temp2)
                {
                    fprintf(fptr, ",%s,%d", temp2->file_name, temp2->word_count);  // Write file details
                    temp2 = temp2->sub_link;
                }

                temp1 = temp1->main_link;
                fprintf(fptr, "\n");
            }
        }
    }
    fclose(fptr);
    return SUCCESS;
}

