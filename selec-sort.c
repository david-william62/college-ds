#include <stdio.h>

void main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d",&n);
  int a[n];
  int i,j;
  printf("Enter values for array \n");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  printf("[");
  for(i=0;i<n;i++) {
    printf("%d,",a[i]);
  }
  printf("] \n");
  
  for(i=0;i<n-1;i++) {
    for(j=i+1;j<n;j++) {
      if(a[j] < a[i]) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  printf("[");
  for(i=0;i<n;i++) {
    printf("%d,",a[i]);
  }
  printf("] \n");
}
