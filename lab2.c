#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int part_number;
    char *part_name;
    float part_size;
    char *part_size_metric;
    float part_cost;
} Part;

Part *database = NULL; 
int *record_count = NULL;

void printRecords() {
    if (*record_count == 0) {
        printf("No records available.\n");
        return;
    }
    printf("\nPART RECORDS:\n");
    for (int i = 0; i < *record_count; i++) {
        printf("Part Number: %d\n", (database + i)->part_number);
        printf("Part Name: %s\n", (database + i)->part_name);
        printf("Part Size: %.2f %s\n", (database + i)->part_size, (database + i)->part_size_metric);
        printf("Part Cost: $%.2f\n", (database + i)->part_cost);
        printf("--------------------------\n");
    }
}

void printStats() {
    printf("Number of records: %d\n", *record_count);
    printf("Size of database: %lu bytes\n", (*record_count) * sizeof(Part));
}

void addRecord() {
    int *new_record_count = (int *)malloc(sizeof(int));
    *new_record_count = *record_count + 1;

    Part *new_db = (Part *)malloc((*new_record_count) * sizeof(Part));
    if (!new_db) {
        printf("Memory allocation failed.\n");
        free(new_record_count);
        return;
    }

    for (int i = 0; i < *record_count; i++) {
        *(new_db + i) = *(database + i);
    }

    (new_db + *record_count)->part_name = (char *)malloc(50 * sizeof(char));
    (new_db + *record_count)->part_size_metric = (char *)malloc(10 * sizeof(char));

    printf("Enter part number: ");
    scanf("%d", &(new_db + *record_count)->part_number);
    printf("Enter part name: ");
    getchar();
    fgets((new_db + *record_count)->part_name, 50, stdin);
    (new_db + *record_count)->part_name[strcspn((new_db + *record_count)->part_name, "\n")] = 0;

    printf("Enter part size: ");
    scanf("%f", &(new_db + *record_count)->part_size);
    printf("Enter size metric: ");
    (new_db + *record_count)->part_size_metric = (char *)malloc(10 * sizeof(char));
    scanf("%9s", (new_db + *record_count)->part_size_metric);
    printf("Enter part cost: ");
    scanf("%f", &(new_db + *record_count)->part_cost);

    free(database);
    free(record_count);
    database = new_db;
    record_count = new_record_count;

    printf("Record added successfully!\n");
}

void deleteRecord() {
    if (*record_count == 0) {
        printf("No records to delete.\n");
        return;
    }

    free((database + *record_count - 1)->part_name);
    free((database + *record_count - 1)->part_size_metric);

    int *new_record_count = (int *)malloc(sizeof(int));
    *new_record_count = *record_count - 1;
    Part *new_db = NULL;
    if (*new_record_count > 0) {
        new_db = (Part *)malloc((*new_record_count) * sizeof(Part));
        if (!new_db) {
            printf("Memory allocation failed.\n");
            free(new_record_count);
            return;
        }

        for (int i = 0; i < *new_record_count; i++) {
            *(new_db + i) = *(database + i);
        }
    }

    free(database);
    free(record_count);
    database = new_db;
    record_count = new_record_count;

    printf("Last record deleted successfully!\n");
}

void printMenu() {
    printf("\nMENU\n");
    printf("=======\n");
    printf("1. Print all records\n");
    printf("2. Print number of records\n");
    printf("3. Print size of database\n");
    printf("4. Add record\n");
    printf("5. Delete record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    record_count = (int *)malloc(sizeof(int));
    *record_count = 0;

    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printRecords();
                break;
            case 2:
            case 3:
                printStats();
                break;
            case 4:
                addRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                for (int i = 0; i < *record_count; i++) {
                    free((database + i)->part_name);
                    free((database + i)->part_size_metric);
                }
                free(database);
                free(record_count);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
