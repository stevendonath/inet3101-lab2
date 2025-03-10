# inet3101-lab2
Repository for INET 3101 Lab 2

# Lab 2: Memory and Structures - In-Memory Database

This project implements an in-memory database for storing and managing records of parts using C. The program uses dynamic memory allocation to store part records in memory, and allows users to add and delete records interactively. The program follows the Agile approach of manipulating dynamic memory without the use of arrays or linked lists.

## Features
- **Add a record**: Add a new part record with the part number, name, size, metric, and cost.
- **Delete a record**: Delete the last record in the database.
- **Print all records**: Display all the records in the database.
- **Print number of records**: Display the total number of records in the database.
- **Print database size**: Show the size of the database in memory.
- **Exit**: Exit the program, freeing all dynamically allocated memory.

## Part Structure
The part record is stored in a structure with the following fields:
- `part_number`: Integer representing the part number.
- `part_name`: String (character array) representing the part name.
- `part_size`: Float representing the part size.
- `part_size_metric`: String representing the metric of the part size (e.g., "mm").
- `part_cost`: Float representing the cost of the part.

## Functions

### `printRecords()`
Prints all records stored in the database. If there are no records, it informs the user that there are no records available.

### `printStats()`
Prints the number of records and the size of the database in memory (in bytes).

### `addRecord()`
Prompts the user to enter the details of a new part and adds it to the database. Memory is reallocated to accommodate the new record.

### `deleteRecord()`
Deletes the last record in the database. The program frees memory used by the part name and size metric before shrinking the database.

### `printMenu()`
Displays the program’s main menu, allowing the user to choose actions like printing records, adding or deleting a record, or exiting the program.


## Compilation

To compile the program, run the following command in the terminal:
- gcc -o lab2 lab2.c
Then run:
- ./lab2

## Known Issues
- When deleting records, only the last record is removed. There is no way to search for and delete a specific record.

## Authors

- Steven Donath
