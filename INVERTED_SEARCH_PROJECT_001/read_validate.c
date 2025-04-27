#include "inverted_search.h"

int read_validate(int argc, char *argv[], file_node **head)
{
    int i;
    if (argc < 2)
    {
        printf("ERROR : Invalid usage\n");
        printf("Usage : ./a.out file1.txt file2.txt ...");
        return FAILURE;
    }

    FILE *fptr = NULL;
    char ch;
    for (i = 1; i < argc; i++)
    {
        fptr = fopen(argv[i], "r");
        if (fptr != NULL)
        {
            /* Check if file is empty before adding to list */
            if (fscanf(fptr, "%c", &ch) != EOF)
            {
                insert_at_last(head, argv[i]);
            }
            else
            {
                printf("file %s is empty\n", argv[i]);
            }
            fclose(fptr);
        }
        else
        {
            printf("File %s is not found\n", argv[i]);
        }
    }
    return SUCCESS;
}

