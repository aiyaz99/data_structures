#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5

void push(int stack[], int *top, int item) {
    if (*top == STACK_SIZE - 1) {
        printf("Stack Overflow! Cannot push: %d\n", item);
    } else {
        stack[++(*top)] = item;
        printf("Pushed: %d\n", item);
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        int item = stack[(*top)--];
        printf("Popped: %d\n", item);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main() {
    int stack[STACK_SIZE];
    int top = -1;
    int choice, item;

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(stack, &top, item);
                break;

            case 2:  // Pop
                pop(stack, &top);
                break;

            case 3:  // Display
                display(stack, top);
                break;

            case 4:  // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }
}