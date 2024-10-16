#include <stdio.h>
#define MAX 10

int arr[MAX];
int temp[MAX];


void merge(int low, int mid, int high) {
  int i=low, x=low, y=mid+1;
  int k;
  while(x <= mid && y <= high) {
    if(arr[x] <= arr[y]) temp[i] = arr[x++];
    else temp[i] = arr[y++];
  }
  if(x <= mid) {
    for(k=x;k<=mid;k++) temp[i++] = arr[k];
  }
  else {
    for(k=y;k<=high;k++) temp[i++] = arr[k];
    for(k=low;k<=high;k++) arr[k] = temp[k];
  }
}
void mrgSort(int low, int high) {
  int mid = (low+high)/2;
  mrgSort(low, mid);
  mrgSort(mid+1,high);
  merge(low, mid, high);
}

void main() {
  int n;
  printf("Enter size of array: \n");
  scanf("%d",&n);
  printf("Enter values of array: \n");
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  int low = 0;
  int high = n-1;
  mrgSort(low,high);
  
  printf("\n Unsorted array: \n");
  for(int i=0;i<n;i++) printf("%d",arr[i]);
  printf("\n Sorted Array: \n");
  for(int i=0;i<n;i++) printf("%d",arr[i]);
  printf("\n");
}
