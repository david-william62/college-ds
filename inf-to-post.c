#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX], inf[MAX], post[MAX];
int top = -1;

//Function to push to stack from infix
void push(char item) {
  if(top == MAX-1) printf("Stack Overflow")
  else stack[++top] = item;
}

//Function to pop from stack to postfix
char pop() {
  if(top == -1) printf("Stack Underflow");
  else return stack[top--];
}

// Function to check operations
int isOper(char ch) {
  return (ch == "+" || ch == "-" || ch == "*" || ch == "/");
}

//Function to check precedence
int preced(char ch) {
  switch(ch) {
    case '+':
    case '-':
      return 1
    case '*':
    case '/':
      return 2
    default:
      return 0;
  }
}

void main() {
  printf("Enter infix expression");
  gets(inf);

  int len = strlen(inf);
  int i = len;

  // infix to postfix operation
  inf[++i] = '\0';
  
}
