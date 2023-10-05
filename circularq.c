#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 && rear == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to insert an element into the queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d.\n", data);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
    printf("%d inserted into the queue.\n", data);
}

// Function to delete an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to display the front value of the queue
void displayFront() {
    if (isEmpty()) {
        printf("Queue is empty. Front value cannot be displayed.\n");
        return;
    }
    printf("Front value: %d\n", queue[front]);
}

// Function to display the rear value of the queue
void displayRear() {
    if (isEmpty()) {
        printf("Queue is empty. Rear value cannot be displayed.\n");
        return;
    }
    printf("Rear value: %d\n", queue[rear]);
}

int main() {
    int choice, data;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n 2. Dequeue\n 3. Display Front\n 4. Display Rear\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayFront();
                break;
            case 4:
                displayRear();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
