#include <stdio.h>

// stack variables
int top=-1;
int size,item;

void pop(int stack[]) {
 if(top == -1) printf("Stack is empty");
 else if(top==0) {
  printf("popped %d \n",stack[top]);
  top = -1;
 }
 else if(top < size-1) {
  printf("popped %d \n",stack[top]);
  top--;
 }
}

void push(int stack[]) {
 printf("Enter item to push: ");
 scanf("%d",&item);
 if(top == -1) {
  top = 0;
  stack[top] = item;
 }
 else if(top < size-1) {
  top++;
  stack[top];
 }
 else if(top == size-1) {
  printf("stack is full");
 }
}

void main() {
 printf("Enter the size of stack: ");
 scanf("%d",&size);
 int choice,stack[size];
 oper:
 printf("\n ENTER THE OPERATION TO PERFORM ON STACK \n");
 printf("1. Push \n");
 printf("2. Pop \n");
 scanf("%d",&choice);
 
 switch(choice) {
  case 1:
   push(stack);
   break;
  case 2:
   pop(stack);
   break;
  default:
   printf("Invalid choice");
 }
 
 int repeat;
 printf("Do you wish to repeat this \n0 for yes \n 1 for no \n");
 scanf("%d",&repeat);
 if(repeat == 1) goto oper;
}

