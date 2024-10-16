#include <stdio.h>
void main() {
  int s;
  printf("Enter the size of array: \n");
  scanf("%d",&s);
  int a[s],i,j;
  printf("Enter elements of array: \n");
  for(i=0;i<s;i++) {
    scanf("%d",&a[i]);
  }
  for(i=0;i<s;i++) {
    printf("%d ",a[i]);
  }
  for(i=0;i<s-1;i++) {
    for(j=i+1;j<s;j++) {
      if(a[j]<a[i]) {
        a[i] = a[i] + a[j];
        a[j] = a[i] - a[j];
        a[i] = a[i] - a[j];
      }
    }
  }
  printf("\n");
  for(i=0;i<s;i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}
