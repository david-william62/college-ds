#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX], inf[MAX], post[MAX];
int top = -1;

// Function to push to stack from infix
void push(char item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

// Function to pop from stack to postfix
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return a default value if underflow
    } else {
        return stack[top--];
    }
}

// Function to check if character is an operator
int isOper(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to check precedence
int preced(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int main() {
    printf("Enter infix expression: ");
    fgets(inf, MAX, stdin);
    inf[strcspn(inf, "\n")] = '\0'; // Remove newline character from input

    int i = 0, j = 0;
    while (inf[i] != '\0') {
        if (isalnum(inf[i])) {
            post[j++] = inf[i];
        } else if (inf[i] == '(') {
            push(inf[i]);
        } else if (inf[i] == ')') { 
            while (top != -1 && stack[top] != '(') {
                post[j++] = pop();
            }
            pop();
        } else if (isOper(inf[i])) { 
            while (top != -1 && preced(stack[top]) >= preced(inf[i])) {
                post[j++] = pop();
            }
            push(inf[i]);
        }
        i++;
    }

    // Pop the remaining operators in the stack
    while (top != -1) {
        post[j++] = pop();
    }
    post[j] = '\0'; // Null-terminate the postfix expression

    printf("\nInfix Expression: %s", inf);
    printf("\nPostfix Expression: %s\n", post);

    return 0;
}

