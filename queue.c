#include <stdio.h>

int s,item,f=-1,r=-1;

void enqueue(int q[]) {
 printf("Enetr item to queue \n");
 scanf("%d",&item);
 if(r==-1 && f==-1) {
  f=r=0;
  q[r] = item;
 }
 else if(r < s-1) {
  r++;
  q[r] = item;
 }
 else if(r == s-1) {
  printf("Queue is full");
 }
}

void dequeue(int q[]) {
 if(f==r && f != -1) {
  printf("Removing %d and clearing stack\n",q[f]);
  f = -1;
  r = -1;
 }
 else if(f < s-1 && f != -1) {
  printf("Removing %d\n",q[f]);
  f++;
 }
 else if(f==-1) printf("Queue is empty");
}

void display(int q[]) {
 if(f==-1 && r==-1) printf("Queue Empty \n");
 else for(int i=f;i<=r;i++) printf("%d ,",q[i]);
}

void main() {
 printf("Enter the size of queue \n");
 scanf("%d",&s);
 int queue[s],ch;
 oper:
 printf("\nEnter the operation to perform on queue \n1 for Enqueue \n2 for dequeue \n3 for display \n");
 scanf("%d",&ch);

 switch(ch) {
  case 1:
   enqueue(queue);
   break;
  case 2:
   dequeue(queue);
   break;
  case 3:
   display(queue);
   break;
  deafult:
   printf("Invalid choice");
 }

 int r;
 printf("\nDo you wish to perform the opertaion again \n0 for no \n1for yes\n");
 scanf("%d",&r);
 if(r!=0) goto oper;
}
