#include "inverted_search.h"

int read_datafile(main_node **arr, char *filename)
{
    main_node *mainnode = NULL, *temp1 = NULL, *prev1 = NULL;
    sub_node *subnode = NULL, *temp2 = NULL, *prev2 = NULL;
    int index;
    char str[80];

    /* Ensure filename has .txt extension */
    if (strstr(filename, ".txt") == NULL)
    {
        printf("Error: Please provide .txt extension file\n");
        return FAILURE;
    }

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("%s file is not present\n", filename);
        return FAILURE;
    }

    /* Check if file is empty */
    if (fscanf(fptr, "%*c") == EOF)
    {
        printf("%s file is empty\n", filename);
        return FAILURE;
    }
    fseek(fptr, 0, SEEK_SET);

    /* Process each line */
    while (fscanf(fptr, "%s", str) != EOF)
    {
        if (str[0] == '#')
        {
            index = atoi(&str[1]);
        }
        else
        {
            temp1 = arr[index];
            mainnode = malloc(sizeof(main_node));
            mainnode->main_link = NULL;
            mainnode->sub_link = NULL;

            char *token;
            token = strtok(str, ",");

            if (token != NULL)
                strcpy(mainnode->word, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                mainnode->file_count = atoi(token);

            /* Insert mainnode in linked list */
            if (arr[index] == NULL)
            {
                arr[index] = mainnode;
            }
            else
            {
                while (temp1)
                {
                    prev1 = temp1;
                    temp1 = temp1->main_link;
                }
                prev1->main_link = mainnode;
            }

            /* Process subnodes */
            for (int i = 0; i < mainnode->file_count; i++)
            {
                subnode = malloc(sizeof(sub_node));
                subnode->sub_link = NULL;

                token = strtok(NULL, ",");
                if (token != NULL)
                    strcpy(subnode->file_name, token);

                token = strtok(NULL, ",");
                if (token != NULL)
                    subnode->word_count = atoi(token);

                /* Insert subnode in linked list */
                if (mainnode->sub_link == NULL)
                {
                    mainnode->sub_link = subnode;
                }
                else
                {
                    temp2 = mainnode->sub_link;
                    while (temp2)
                    {
                        prev2 = temp2;
                        temp2 = temp2->sub_link;
                    }
                    prev2->sub_link = subnode;
                }
            }
        }
    }
    return SUCCESS;
}

