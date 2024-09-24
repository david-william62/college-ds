#include <stdio.h>

int size,f=-1,r=-1,item;
void enqueue(int arr[]) {
 if((r+1)%size == f) {
  printf("Queue is full \n");
 }
 else {
  printf("Enter item to queue :");
  scanf("%d",&item);
  r = (r+1)%size;
  arr[r] = item;
  if(f == -1) f = 0;
 }
}

void dequeue(int arr[]) {
 if(f == -1) {
  printf("Queue Empty \n");
 } else {
  if(r==f) {
   printf("Removing %d \n",arr[f]);
   r=-1;
   f=-1;
  }
  else {
   printf("Removing %d \n",arr[f]);
   f = (f+1)%size;
  }
 }
}

void display(int arr[]) {
  if(f == -1 && r == -1) printf("Queue is empty");
  else {
    for(int i = f; i<=r; i++) printf("%d ,",arr[i])
  }
}

int main() {
  printf("Enter size of queue :");
  scanf("%d",&size);
  int q[size],ch;

oper:
  printf("Enter the operation to perform \n1 for enqueue \n2 for dequeue \n3 for display \n");
  scanf("%d",&ch);
  switch(ch) {
    case 1:
      enqueue(q);
      break;
    case 2:
      dequeue(q);
      break;
    case 3:
      display(q);
      break;
    default:
      printf("Invalid choice \n");
  }

  printf("Do you wish to perform operation again \n0 for no \n1 for yes \n");
  scanf("%d",&ch);
  if(ch == 0) return 1;
  else goto oper;
}
