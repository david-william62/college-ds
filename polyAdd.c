#include <stdio.h>
void main() {
 int s1,s2,i,j,k;
 printf("Enter number of terms in 1st and 2nd polynomial \n");
 scanf("%d %d",&s1,&s2);
 int c1[s1],d1[s1],c2[s2],d2[s2],sc[s1+s2],sd[s1+s2];
 printf("Enter the coefficient and degree of 1st polynomial \n");
 for(i=0;i<s1;i++) {
  scanf("%d %d",&c1[i],&d1[i]);
 }
 printf("Enter the coefficient and degree of 2nd  polynomial \n");
 for(i=0;i<s2;i++) {
  scanf("%d %d",&c2[i],&d2[i]);
 }
 printf("1st Polynomial is");
 for(i=0;i<s1;i++) {
  printf("(%dx^(%d)) +",c1[i],d1[i]);
 }
 printf("\n");
 printf("2nd Polynomial is");
 for(i=0;i<s2;i++) {
  printf("(%dx^(%d)) +",c2[i],d2[i]);
 }
 printf("\n");
 i=0;
 j=0;
 k=0;
 while(i<s1 && j<s2) {
  if(d1[i]==d2[j]) {
   sc[k] = c1[i]+c2[j];
   sd[k] = d1[i];
   i++;
   j++;
   k++;
  }
  else if(d1[i]>d2[j]) {
   sc[k] = c1[i];
   sd[k] = d1[i];
   i++;
   k++;
  }
  else if(d2[j]>d1[i]) {
   sc[k] = c2[j];
   sd[k] = d2[j];
   j++;
   k++;
  }
 }
 for(i=0;i<k;i++) {
  printf("(%dx^(%d)) +",sc[i],sd[i]);
 }
 printf("\n");
}
