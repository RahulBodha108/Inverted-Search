#include "inverted_search.h"

int interlock;

int main(int argc, char *argv[]) {
    file_node *head = NULL;
    main_node *arr[28] = {NULL};  // Array of main nodes
    int option;

    // Validate input files
    if (read_validate(argc, argv, &head) == SUCCESS) {
        print_list(head);

        do {
            printf("Select your choice among the following options:\n");
            printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\n6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    // Create the database
                    if (create_database(&head, arr) == SUCCESS) {
                        interlock = 1;
                        printf("Database Created...\n");
                    } else {
                        printf("Failed to Create Database...\n");
                    }
                    break;

                case 2:
                    // Display database
                    display_output(arr);
                    break;

                case 3:
                    // Update database from additional file
                    if (interlock != 1) {
                        char str[50];
                        printf("Enter the file name: ");
                        scanf("%s", str);

                        if (read_datafile(arr, str) == SUCCESS) {
                            printf("Database Updated...\n");
                        } else {
                            printf("Update Fail...\n");
                        }
                    } else {
                        printf("Error: Database already created, cannot update Database now\n");
                    }
                    break;

                case 4:
                    // Search for a word in the database
                    char str2[50];
                    printf("Enter the word you want to search: ");
                    scanf("%s", str2);

                    if (search(str2, arr) == SUCCESS) {
                        printf("Word found in the database\n");
                    } else {
                        printf("Word not found in the database\n");
                    }
                    break;

                case 5:
                    // Save database to file
                    char str1[50];
                    printf("Enter the file name: ");
                    scanf("%s", str1);

                    if (write_databasefile(arr, str1) == SUCCESS) {
                        printf("Database successfully saved to file\n");
                    } else {
                        printf("Saving Database to file failed\n");
                    }
                    break;

                case 6:
                    printf("Exiting...\n");
                    break;

                default:
                    printf("Invalid option\n");
                    break;
            }

        } while (option != 6);
    }
    
    return 0;
}

