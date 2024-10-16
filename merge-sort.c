#include <stdio.h>
#define MAX 10

int arr[MAX];
int temp[MAX];

void merge(int low, int mid, int high) {
  int i = low, x = low, y = mid + 1;
  while (x <= mid && y <= high) {
    if (arr[x] <= arr[y]) {
      temp[i++] = arr[x++];
    } else {
      temp[i++] = arr[y++];
    }
  }
  while (x <= mid) {
    temp[i++] = arr[x++];
  }
  while (y <= high) {
    temp[i++] = arr[y++];
  }
  for (i = low; i <= high; i++) {
    arr[i] = temp[i];
  }
}

void mrgSort(int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mrgSort(low, mid);
    mrgSort(mid + 1, high);
    merge(low, mid, high);
  }
}

int main() {
  int n;
  printf("Enter size of array: \n");
  scanf("%d", &n);
  
  if (n > MAX) {
    printf("Size exceeds maximum limit of %d\n", MAX);
    return 1;
  }

  printf("Enter values of array: \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  mrgSort(0, n - 1);
  
  printf("\nSorted Array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}

