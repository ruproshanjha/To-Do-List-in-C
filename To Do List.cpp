#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 100

typedef struct {
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int count;
} ToDoList;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void wait(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);  // Sleep takes milliseconds
#else
    sleep(seconds);  // sleep takes seconds
#endif
}

void loadingAnimation(const char* message) {
    printf("%s", message);
    fflush(stdout); // Ensure the message is printed before the animation
    for (int i = 0; i < 3; i++) { // Display 3 dots
        printf(".");
        fflush(stdout);
        wait(1);
    }
    printf("\n");
}

void addTask(ToDoList* list, const char* task) {
    if (list->count < MAX_TASKS) {
        strcpy(list->tasks[list->count], task);
        list->count++;
        loadingAnimation("Adding task"); // Display loading animation
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void removeTask(ToDoList* list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid task number!\n");
        return;
    }
    for (int i = index; i < list->count - 1; i++) {
        strcpy(list->tasks[i], list->tasks[i + 1]);
    }
    list->count--;
    loadingAnimation("Removing task"); // Display loading animation
    printf("Task removed successfully!\n");
}

void displayHome(ToDoList* list) {
    clearScreen(); // Clear the screen before displaying the home screen
    printf("---------------------------------------------------------\n");
    printf("|                      To-Do List                       |\n");
    printf("---------------------------------------------------------\n");
    printf("|          Task List              |        Menu         |\n");
    printf("------------------------------------------------------\n");

    // Display tasks on the left side
    for (int i = 0; i < list->count || i < 7; i++) { // Display a fixed number of lines for alignment
        if (i < list->count) {
            printf("| %3d. %-27s", i + 1, list->tasks[i]);
        } else {
            printf("| %3d. %-27s", i + 1, " "); // Fill empty space for alignment
        }

        // Display menu on the right side for the first 7 lines
        if (i == 0) printf("| 1. Add Task         |\n");
        else if (i == 1) printf("| 2. Remove Task      |\n");
        else if (i == 2) printf("| 3. Exit             |\n");
        else if (i == 3) printf("|                     |\n");
        else if (i == 4) printf("|                     |\n");
        else if (i == 5) printf("|                     |\n");
        else printf("|                     |\n");
    }
    printf("---------------------------------------------------------\n");
}

int main() {
    ToDoList list;
    list.count = 0;

    int choice;
    char task[MAX_TASK_LENGTH];
    int taskNumber;

    do {
        displayHome(&list);

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter the task: ");
                fgets(task, MAX_TASK_LENGTH, stdin);
                task[strcspn(task, "\n")] = 0; // Remove newline character
                addTask(&list, task);
                wait(1); // Wait for 1 second before refreshing the screen
                break;
            case 2:
                printf("Enter the task number to remove: ");
                scanf("%d", &taskNumber);
                removeTask(&list, taskNumber - 1);
                wait(1); // Wait for 1 second before refreshing the screen
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                wait(1); // Wait for 1 second before refreshing the screen
                break;
        }
    } while (choice != 3);

    return 0;
}
