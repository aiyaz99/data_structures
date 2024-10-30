#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("The previous node is null. Insertion failed.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createLinkedList(struct Node** head) {
    int n, data;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}


int main() {
    struct Node* head = NULL;


    createLinkedList(&head);

    printf("\nInitial linked list:\n");
    displayList(head);


    insertAtBeginning(&head, 36);
    printf("\nAfter inserting 36 at the beginning:\n");
    displayList(head);

    insertAtPosition(&head, 90, 3);
    printf("\nAfter inserting 90 at position 3:\n");
    displayList(head);

    insertAtEnd(&head, 10);
    printf("\nAfter inserting 10 at the end:\n");
    displayList(head);

    return 0;
}
