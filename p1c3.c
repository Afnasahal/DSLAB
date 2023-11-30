#include <stdio.h>
#include <stdlib.h>

// Node structure for Binomial Heap
struct Node {
    int key;
    int degree;
    struct Node* parent;
    struct Node* child;
    struct Node* sibling;
};

// Function to create a new node with given key
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->degree = 0;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Function to merge two binomial heaps
struct Node* mergeHeaps(struct Node* h1, struct Node* h2) {
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    // Make sure h1 has the smaller root
    if (h1->key > h2->key) {
        struct Node* temp = h1;
        h1 = h2;
        h2 = temp;
    }

    // Make h2 the child of h1
    h2->parent = h1;
    h2->sibling = h1->child;
    h1->child = h2;
    h1->degree++;

    return h1;
}

// Function to merge two binomial heaps and return the result
struct Node* unionHeaps(struct Node* h1, struct Node* h2) {
    struct Node* head = NULL;
    struct Node* prev = NULL;
    struct Node* temp = NULL;

    while (h1 != NULL || h2 != NULL) {
        if (h1 != NULL && (h2 == NULL || h1->degree <= h2->degree)) {
            temp = h1;
            h1 = h1->sibling;
        } else {
            temp = h2;
            h2 = h2->sibling;
        }

        if (prev == NULL) {
            head = temp;
        } else {
            prev->sibling = temp;
        }

        prev = temp;
    }

    return head;
}

// Function to perform the binomial heap insertion
struct Node* insert(struct Node* head, int key) {
    struct Node* newNode = createNode(key);
    return unionHeaps(head, newNode);
}

// Function to find the minimum key node in the binomial heap
struct Node* findMin(struct Node* head) {
    struct Node* minNode = NULL;
    struct Node* current = head;

    while (current != NULL) {
        if (minNode == NULL || current->key < minNode->key) {
            minNode = current;
        }
        current = current->sibling;
    }

    return minNode;
}

// Function to delete the minimum key node from the binomial heap
struct Node* deleteMin(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* minNode = findMin(head);
    struct Node* prev = NULL;
    struct Node* current = head;

    while (current != NULL) {
        if (current == minNode) {
            if (prev == NULL) {
                head = current->sibling;
            } else {
                prev->sibling = current->sibling;
            }

            // Reverse the order of minNode's children and merge with the heap
            struct Node* child = minNode->child;
            struct Node* temp = NULL;
            while (child != NULL) {
                temp = child->sibling;
                child->sibling = head;
                head = child;
                child = temp;
            }

            free(minNode);
            return unionHeaps(head, head);
        }

        prev = current;
        current = current->sibling;
    }

    return head;
}

// Function to print the binomial heap
void printHeap(struct Node* head) {
    while (head != NULL) {
        printf("Degree %d: ", head->degree);
        struct Node* current = head->child;
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->sibling;
        }
        printf("\n");
        head = head->sibling;
    }
}

int main() {
    struct Node* binomialHeap = NULL;
    int choice, key;

    do {
        printf("\n1. Insert\n");
        printf("2. Delete Min\n");
        printf("3. Print Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                binomialHeap = insert(binomialHeap, key);
                break;
            case 2:
                binomialHeap = deleteMin(binomialHeap);
                break;
            case 3:
                printf("Binomial Heap:\n");
                printHeap(binomialHeap);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

