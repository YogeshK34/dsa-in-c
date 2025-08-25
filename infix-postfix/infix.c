#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for strings
char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack[++top], str);
}

char* pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert Postfix → Infix
void postfixToInfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            char op[2] = {exp[i], '\0'};
            push(op);
        }
        else if (isOperator(exp[i])) {
            char op2[MAX], op1[MAX], temp[MAX];
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(temp, "(%s%c%s)", op1, exp[i], op2);
            push(temp);
        }
    }
    printf("Infix: %s\n", pop());
}

// Convert Prefix → Infix
void prefixToInfix(char* exp) {
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(exp[i])) {
            char op[2] = {exp[i], '\0'};
            push(op);
        }
        else if (isOperator(exp[i])) {
            char op1[MAX], op2[MAX], temp[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());
            sprintf(temp, "(%s%c%s)", op1, exp[i], op2);
            push(temp);
        }
    }
    printf("Infix: %s\n", pop());
}

int main() {
    char postfixExp[MAX], prefixExp[MAX];

    printf("Enter Postfix expression: ");
    scanf("%s", postfixExp);
    postfixToInfix(postfixExp);

    printf("Enter Prefix expression: ");
    scanf("%s", prefixExp);
    prefixToInfix(prefixExp);

    return 0;
}
