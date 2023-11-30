#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the list
struct Node* insertAtHead(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the tail of the list
struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node at a specified position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be 1 or greater.\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            return head;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node at the head of the list
struct Node* deleteAtHead(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the tail of the list
struct Node* deleteAtTail(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node from a specified position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be 1 or greater.\n");
        return head;
    }
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return head;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            return head;
        }
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to search for an element in the list
int searchElement(struct Node* head, int element) {
    int position = 1;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == element) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, searchElementResult;

    while (1) {
        printf("\n1. Insert at head\n2. Insert at tail\n3. Insert at position\n4. Delete at head\n5. Delete at tail\n6. Delete at position\n7. Search for an element\n8. Display List\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the head: ");
                scanf("%d", &data);
                head = insertAtHead(head, data);
                break;
            case 2:
                printf("Enter data to insert at the tail: ");
                scanf("%d", &data);
                head = insertAtTail(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteAtHead(head);
                break;
            case 5:
                head = deleteAtTail(head);
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElementResult = searchElement(head, data);
                if (searchElementResult == -1) {
                    printf("Element not found in the list.\n");
                } else {
                    printf("Element found at position %d.\n", searchElementResult);
                }
                break;
            case 8:
                printf("Current Linked List: ");
                displayList(head);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please maake another choice");
                  }
    }

    return 0;
}

