


#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the circular linked list
struct Node* insertAtHead(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

// Function to insert a node at the tail of the circular linked list
struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return newNode;
}

// Function to insert a node at a specific position in the circular linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        if (position == 1) {
            newNode->next = newNode;
            return newNode;
        } else {
            printf("Invalid position\n");
            return head;
        }
    }
    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Invalid position\n");
            return head;
        }
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node at the head of the circular linked list
struct Node* deleteAtHead(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    return head;
}

// Function to delete a node at the tail of the circular linked list
struct Node* deleteAtTail(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = head;
    free(temp);
    return head;
}

// Function to delete a node from a specific position in the circular linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return head;
    }
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position == 1) {
        return deleteAtHead(head);
    }
    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Invalid position\n");
            return head;
        }
    }
    if (current->next == head) {
        printf("Invalid position\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to search for an element in the circular linked list
int searchElement(struct Node* head, int key) {
    if (head == NULL) {
        return 0;
    }
    struct Node* current = head;
    do {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    } while (current != head);
    return 0;
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at the head\n2. Insert at the tail\n3. Insert at a position\n4. Delete at the head\n5. Delete at the tail\n6. Delete from a position\n7. Search for an element\n8. Display the list\n9. Exit\n");
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
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                if (searchElement(head, key)) {
                    printf("Element found in the list.\n");
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 8:
                printf("Circular Linked List: ");
                displayList(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


