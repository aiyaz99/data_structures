#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s) {
    int len = strlen(s);
    char stack[len];  
    int top = -1;     

    for (int i = 0; i < len; i++) {
        char current = s[i];

        if (current == '(' || current == '[' || current == '{') {
            stack[++top] = current;
        } else {
            if (top == -1) {
                return false;
            }

            char topChar = stack[top--];

            if ((current == ')' && topChar != '(') ||
                (current == ']' && topChar != '[') ||
                (current == '}' && topChar != '{')) {
                return false;
            }
        }
    }

    return top == -1;
}
