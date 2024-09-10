#include <stdio.h>

int size,f=-1,r=-1,item;
void enqueue(int arr[]) {
 if((r+1)%size == f) {
  printf("Queue is full");
 }
 else {
  r = (r+1)%size;
  arr[r] = item;
  if(f == -1) f = 0;
 }
}

void dequeue(int arr[]) {
 if(f == -1) {
  printf("Queue Empty");
 } else {
  if(r==f) {
   arr[f] = 0;
   r=-1;
   f=-1;
  }
  else {
   arr[f] = 0;
   f = (f+1)%size;
  }
 }
}

void main() {
 printf("Enter size of queue");
 scanf("%d",&size);
}
