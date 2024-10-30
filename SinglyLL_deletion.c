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


void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}


void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position does not exist. Deletion failed.\n");
            return;
        }
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    if (toDelete == NULL) {
        printf("Position does not exist. Deletion failed.\n");
        return;
    }
    temp->next = toDelete->next;
    free(toDelete);
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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


    deleteAtBeginning(&head);
    printf("\nAfter deleting at the beginning:\n");
    displayList(head);

    deleteAtEnd(&head);
    printf("\nAfter deleting at the end:\n");
    displayList(head);

    deleteAtPosition(&head, 3);
    printf("\nAfter deleting at position 3:\n");
    displayList(head);

    return 0;
}
