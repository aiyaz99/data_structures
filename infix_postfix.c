#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100


int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}


int isOperand(char c) {
    return isalpha(c);  
}


char pop(char* stack, int* top) {
    if (*top == -1) {
        return '\0';  
    }
    return stack[(*top)--];
}


void push(char* stack, int* top, char value) {
    stack[++(*top)] = value;
}

char peek(char* stack, int top) {
    if (top == -1) {
        return '\0';  
    }
    return stack[top];
}

void infixToPostfix(char* infix) {
    char stack[MAX];
    int top = -1;
    char ch;
    while ((ch = *infix++) != '\0') {
        if (isOperand(ch)) {
            printf("%c", ch);  
        } else if (ch == '(') {
            push(stack, &top, ch); 
        } else if (ch == ')') {
            while (top != -1 && peek(stack, top) != '(') {
                printf("%c", pop(stack, &top)); 
            }
            pop(stack, &top);  
        } else {  
            while (top != -1 && precedence(peek(stack, top)) >= precedence(ch)) {
                printf("%c", pop(stack, &top)); 
            }
            push(stack, &top, ch);  
        }
    }

    while (top != -1) {
        printf("%c", pop(stack, &top));
    }
}

int main() {
    char infix[MAX];
    
    printf("Enter a valid infix expression: ");
    gets(infix);  

    printf("Postfix expression: ");
    infixToPostfix(infix);
    
    return 0;
}

