#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the list
struct Node* insertAtHead(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

// Function to insert a node at the tail of the list
struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert a node at a specified position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1)
        position = 1;

    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL)
        return head;

    newNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to delete a node at the head of the list
struct Node* deleteAtHead(struct Node* head) {
    if (head == NULL)
        return head;

    struct Node* newHead = head->next;
    free(head);
    if (newHead != NULL)
        newHead->prev = NULL;
    return newHead;
}

// Function to delete a node at the tail of the list
struct Node* deleteAtTail(struct Node* head) {
    if (head == NULL)
        return head;

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

// Function to delete a node at a specified position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL)
        return head;

    if (position < 1)
        position = 1;

    if (position == 1) {
        struct Node* newHead = head->next;
        free(head);
        if (newHead != NULL)
            newHead->prev = NULL;
        return newHead;
    }

    struct Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL)
        return head;

    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
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

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory and delete the entire list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, element, searchResult;

    while (1) {
        printf("Doubly Linked List Operations:\n");
        printf("1. Insert at the head\n");
        printf("2. Insert at the tail\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at the head\n");
        printf("5. Delete at the tail\n");
        printf("6. Delete at a position\n");
        printf("7. Search for an element\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
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
                printf("Enter element to search for: ");
                scanf("%d", &element);
                searchResult = searchElement(head, element);
                if (searchResult != -1)
                    printf("%d found at position %d\n", element, searchResult);
                else
                    printf("%d not found in the list\n", element);
                break;
            case 8:
                printf("Doubly Linked List: ");
                displayList(head);
                break;
            case 9:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

