#include <stdio.h>
void main() {
 int r,c,i,j;
 printf("Enter row and column size: \n");
 scanf("%d %d",&r,&c);
 int a[r][c],k=0,z=0,nz=0,s[r][c];
 printf("Enter elements of matrix: \n");
 for(i=0;i<r;i++) {
  for(j=0;j<c;j++) {
   scanf("%d",&a[i][j]);
  }
 }
 for(i=0;i<r;i++) {
  for(j=0;j<c;j++) {
   if(a[i][j]!=0) nz++;
   else z++;
  }
 }
 if(z>nz) {
  s[k][0]=r;
  s[k][1]=c;
  s[k][2]=nz;
  k++;
  for(i=0;i<r;i++) {
   for(j=0;j<c;j++) {
    if(a[i][j]!=0) {
     s[k][0]=i;
     s[k][1]=j;
     s[k][2]=a[i][j];
     k++;
    }
   }
  }
  printf("Result is \n");
  for(i=0;i<k;i++) {
   for(j=0;j<3;j++) {
    printf("%d \t",s[i][j]);
   }
   printf("\n");
  }
 }
 else {
  printf("Not a sparse \n");
 }
}
