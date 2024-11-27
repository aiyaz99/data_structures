#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node *newNode(int value){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
};

struct node *InsertNode (struct node *node,int value){
    if(node == NULL){
        return newNode(value);
    }

    else if(value < node->data){
        node->left = InsertNode(node->left,value);
    }

    else if(value > node->data) {
        node->right = InsertNode(node->right,value);
    }
    return node;
};

void PostOrder (struct node *node) {
    if(node != NULL){
    PostOrder(node->left);
    PostOrder(node->right);
    printf("%d ", node->data);
}
}

void InOrder (struct node *node) {
    if(node != NULL){
    PostOrder(node->left);
    printf("%d ", node->data);
    PostOrder(node->right);
}
}

void PreOrder (struct node *node) {
    if(node != NULL){
    printf("%d ", node->data);
    PostOrder(node->left);
    PostOrder(node->right);
}
}




int main()
{
    struct node *root=NULL;
    root = InsertNode(root,50);
    InsertNode(root,80);
    InsertNode(root,60);
    InsertNode(root, 70);
    InsertNode(root,40);
    InsertNode(root,30);
    InsertNode(root,20);
    printf("PostOrder : \n");
    PostOrder( root );
    printf("\n");
    printf("Inorder : \n");
    InOrder( root );
     printf("\n");
    printf("PreOrder : \n");
    PreOrder( root );
    return 0;
}
