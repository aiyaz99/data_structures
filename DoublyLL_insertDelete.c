#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void createList();
void insertAtFront();
void deleteAtPos();
void display();

void createList() {
    struct node *newNode;
    int choice = 1;
    while (choice) {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert: ");
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printf("Enter 1 to add more nodes, or 0 to stop: ");
        scanf("%d", &choice);
    }
}

void insertAtFront() {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
}

void deleteAtPos() {
    int pos, i = 1;
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);


    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        free(temp);
        printf("Node at position %d deleted.\n", pos);
        return;
    }


    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }


    if (temp->next == NULL) {
        tail = temp->prev;
        tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

void display() {
    struct node *temp = head;
    int count = 0;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total nodes: %d\n", count);
}

int main() {
    int UserChoice;
    while (1) {
        printf("\nselect choice :\n");
        printf("1. Create List\n");
        printf("2. Insert At Front\n");
        printf("3. Delete At Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &UserChoice);

        switch (UserChoice) {
            case 1:
                createList();
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                deleteAtPos();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting!\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
