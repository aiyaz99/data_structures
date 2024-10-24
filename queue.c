#include <stdio.h>
#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;

void insert(int element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow: Unable to insert %d. The queue is full.\n", element);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("%d inserted into the queue.\n", element);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow: The queue is empty. Cannot delete an element.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1; 
        }
    }
}

void display() {
    if (front == -1) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice, element;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
