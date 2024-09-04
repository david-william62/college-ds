#include <stdio.h>

void main() {
 int sz,key,i,j,l,h,m,flag=0;
 printf("Enter size of Array: ");
 scanf("%d",&sz);
 int a[sz];
 printf("Enter values of array: \n");
 for(i=0;i<sz;i++) {
  scanf("%d",&a[i]);
 }
 int temp;
 for(i=0;i<sz-1;i++) {
  for(j=0;j<sz-i-1;j++) {
   if(a[j]>a[j+1]) {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 printf("Sorted array is \n");
 for(i=0 ; i<sz ; i++) {
  printf("%d ",a[i]);
 }
 printf("Enter value to search: ");
 scanf("%d",&key);
 l = 0;
 h = sz-1;
 while(l<=h) {
  temp=l+h;
  m=temp/2;
  if(a[m]==key) {
   flag = 1;
   break;
  }
  else if(a[m]>key) h=m-1;
  else l=m+1;
 }
 if(flag==1) printf("Element found at %d \n",m+1);
 else printf("Element not found in list \n");
}
