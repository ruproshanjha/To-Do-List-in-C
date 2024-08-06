# To-Do List in C

This is a simple console-based To-Do List application written in C. It allows users to add and remove tasks, and view the current list of tasks. The program uses an array to store tasks and provides a basic menu for interacting with the tasks.

## Features

- **Add Task**: Add a new task to the list.
- **Remove Task**: Remove an existing task from the list.
- **Display Home Screen**: The home screen shows the current tasks on the left and the menu on the right.

## Prerequisites

To compile and run this program, you'll need:

- A C compiler (e.g., GCC, MSVC)
- A terminal or command prompt

## How to Use

1. **Clone or Download the Repository**:
   ```bash
   git clone https://github.com/your-username/todo-list-c.git
   or download the ZIP file and extract it.
2. **Compile the Program**:
   ```bash
   gcc -o todo todo.c
3. **Run the Program**:
   ```bash
   ./todo  (on Unix-like systems)
   todo.exe (on Windows)
5. ## Using the Program

Upon starting the program, you will see the current task list and the menu.

- **Enter `1`** to add a task. You'll be prompted to enter the task description.
- **Enter `2`** to remove a task. You'll need to enter the task number to remove it.
- **Enter `3`** to exit the program.

## Code Overview

- **`ToDoList` Struct**: Holds an array of tasks and a count of the number of tasks.
- **`addTask` Function**: Adds a new task to the list.
- **`removeTask` Function**: Removes a task from the list by its index.
- **`displayHome` Function**: Displays the home screen with the task list and menu.
- **`loadingAnimation` Function**: Shows a simple loading animation while adding or removing tasks.

## Additional Notes

- The program limits the task list to a maximum of 100 tasks.
- The console text is cleared and refreshed after each operation.
- The program features a basic loading animation when adding or removing tasks.
