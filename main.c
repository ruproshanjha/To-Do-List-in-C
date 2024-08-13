
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the front of the list
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the front.\n", data);
}

// Function to insert at the back of the list
void insertAtBack(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the back.\n", data);
}

// Function to insert at a given position in the list
void insertAtPosition(Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at position %d.\n", data, position);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", data, position);
    }
}

// Function to delete a node from the front
void deleteFromFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    printf("Deleted %d from the front.\n", temp->data);
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the back
void deleteFromBack(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("Deleted %d from the back.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted %d from the back.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a given position
void deleteFromPosition(Node** head, int position) {
    if (*head == NULL || position < 0) {
        printf("List is empty or invalid position!\n");
        return;
    }
    if (position == 0) {
        Node* temp = *head;
        printf("Deleted %d from position %d.\n", temp->data, position);
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of range\n");
    } else {
        Node* toDelete = temp->next;
        printf("Deleted %d from position %d.\n", toDelete->data, position);
        temp->next = toDelete->next;
        free(toDelete);
    }
}

// Function to search for an element in the list
void searchElement(Node* head, int key) {
    int position = 0;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

// Function to display the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Current List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int mainChoice, subChoice, data, position;

    do {
        system("cls");  // Use "clear" for Unix-based systems
        printf("******************************\n");
        printf("*         Main Menu          *\n");
        printf("******************************\n");
        printf("* 1. Insert                  *\n");
        printf("* 2. Delete                  *\n");
        printf("* 3. Search                  *\n");
        printf("* 4. Display List            *\n");
        printf("* 5. Exit                    *\n");
        printf("******************************\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                do {
                    system("cls");
                    printf("******************************\n");
                    printf("*        Insert Menu         *\n");
                    printf("******************************\n");
                    printf("* 1. Insert at front         *\n");
                    printf("* 2. Insert at back          *\n");
                    printf("* 3. Insert at position      *\n");
                    printf("* 4. Back to main menu       *\n");
                    printf("******************************\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1:
                            printf("Enter the data to insert at front: ");
                            scanf("%d", &data);
                            insertAtFront(&head, data);
                            break;
                        case 2:
                            printf("Enter the data to insert at back: ");
                            scanf("%d", &data);
                            insertAtBack(&head, data);
                            break;
                        case 3:
                            printf("Enter the data to insert: ");
                            scanf("%d", &data);
                            printf("Enter the position: ");
                            scanf("%d", &position);
                            insertAtPosition(&head, data, position);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                    }
                    if (subChoice != 4) {
                        printf("\nPress Enter to continue...");
                        getchar();  // Wait for user to press Enter
                        getchar();  // Capture the newline character from previous input
                    }
                } while (subChoice != 4);
                break;

            case 2:
                do {
                    system("cls");
                    printf("******************************\n");
                    printf("*        Delete Menu         *\n");
                    printf("******************************\n");
                    printf("* 1. Delete from front       *\n");
                    printf("* 2. Delete from back        *\n");
                    printf("* 3. Delete from position    *\n");
                    printf("* 4. Back to main menu       *\n");
                    printf("******************************\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1:
                            deleteFromFront(&head);
                            break;
                        case 2:
                            deleteFromBack(&head);
                            break;
                        case 3:
                            printf("Enter the position to delete from: ");
                            scanf("%d", &position);
                            deleteFromPosition(&head, position);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");
                            break;
                    }
                    if (subChoice != 4) {
                        printf("\nPress Enter to continue...");
                        getchar();  // Wait for user to press Enter
                        getchar();  // Capture the newline character from previous input
                    }
                } while (subChoice != 4);
                break;

            case 3:
                system("cls");
                printf("Enter the element to search: ");
                scanf("%d", &data);
                searchElement(head, data);
                printf("\nPress Enter to continue...");
                getchar();  // Wait for user to press Enter
                getchar();  // Capture the newline character from previous input
                break;

            case 4:
                system("cls");
                displayList(head);
                printf("\nPress Enter to continue...");
                getchar();  // Wait for user to press Enter
                getchar();  // Capture the newline character from previous input
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                printf("\nPress Enter to continue...");
                getchar();  // Wait for user to press Enter
                getchar();  // Capture the newline character from previous input
                break;
        }

    } while (mainChoice != 5);

}