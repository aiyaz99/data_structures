#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Stack Operations
void push(Node **top, int val) {
    Node* newnode = malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory location failed for push operation\n");
        return;
    }
    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

void pop(Node **top) {
    if (*top == NULL) {
        printf("Stack is empty (underflow!!).\n");
        return;
    }
    Node* temp = *top;
    *top = temp->next;
    printf("Popped value: %d\n", temp->data);
    free(temp);
}

// Queue Operations
void enqueue(Node **front, Node **rear, int val) {
    Node* newnode = malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory location failed for enqueue operation\n");
        return;
    }
    newnode->data = val;
    newnode->next = NULL;
    if (*front == NULL) {
        *front = *rear = newnode;
    }
    else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

void dequeue(Node **front, Node **rear) {
    if (*front == NULL) {
        printf("Queue is empty (underflow!).\n");
        return;
    }
    Node* temp = *front;
    *front = temp->next;
    printf("Dequeued value: %d\n", temp->data);
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

void display(Node *front) {
    Node *temp = front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void) {
    printf("\nStack Operation:\n\n");
    Node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    display(top);

    pop(&top);
    pop(&top);
    display(top);

    printf("\n\nQueue Operation:\n\n");
    Node *front = NULL;
    Node *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    display(front);

    dequeue(&front, &rear);
    dequeue(&front, &rear);
    display(front);

    return 0;
}
