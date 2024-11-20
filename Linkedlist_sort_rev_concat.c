#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
      printf("Memory allocation failed.\n");
      exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int data) {
     Node *newNode = createNode(data);
     newNode->next = head;
     return newNode;
}

Node *concatLists(Node *head1, Node *head2)
{
Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

Node* sortList(Node* head) {
    if (head == NULL) return NULL;

    Node* i = head;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return head;
}


Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


void displayList2(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void displayList1(Node* head1, Node* head2) {
    printf("List 1: ");
    displayList2(head1);
    printf("List 2: ");
    displayList2(head2);
}


int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;

    list1 = insertAtBeginning(list1, 3);
    list1 = insertAtBeginning(list1, 1);
    list1 = insertAtBeginning(list1, 2);

    list2 = insertAtBeginning(list2, 4);
    list2 = insertAtBeginning(list2, 5);

    printf("After Sorting:\n");
    list1 = sortList(list1);
    list2 = sortList(list2);
    displayList1(list1, list2);

    printf("After concatenation:\n");
    printf("List: ");
    list1 = concatLists(list1, list2);
    displayList2(list1);

    printf("After reversing:\n");
    printf("List: ");
    list1 = reverseList(list1);
    displayList2(list1);
    return 0;
}
