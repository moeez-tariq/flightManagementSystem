# Flight Ticket Management System

## Description

This Flight Ticket Management System is an object-oriented programming (OOP) based application utilizing Hash Table as the primary data structure with separate chaining to handle collisions. The system allows users to manage flight tickets efficiently, identifying each ticket based on a key generated from the combination of the company name and flight number.

Flight ticket information can be inserted or read from the application interface or an input text file. The system supports various management features, including adding new flight tickets, deleting ticket records, finding ticket details, displaying all tickets in a day, printing tickets in ascending order, and more.

## How to Run

1. **Compilation**: Compile the program using the provided makefile.

    ```bash
    make
    ```

2. **Run the Program**:

    ```bash
    ./output
    ```
3. Use the command-line interface to interact with the Flight Ticket Management System.

## Commands

- `import <path>`: Import flight tickets from a CSV file.
- `export <path>`: Export flight tickets to a CSV file.
- `count_collisions`: Print the number of collisions.
- `add`: Add a new flight ticket.
- `delete <key>`: Delete a flight ticket.
- `find <key>`: Find a flight ticket's details.
- `allinday <date>`: Display all flight tickets in a day.
- `printASC <key>`: Print flight tickets in ascending order.
- `exit`: Exit the program.

## Usage

1. Enter commands as per the provided syntax.
2. Follow the prompts to input necessary details for adding new flight tickets.
3. Explore various features for managing flight tickets efficiently.

Feel free to explore and enhance the system as needed!

