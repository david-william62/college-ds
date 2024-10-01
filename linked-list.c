#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node* link;
}*header, *p, *temp;

void insBeg() {
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter element to enter: \n");
  scanf("%d",&temp->data);
  if(temp == NULL) {
    printf("Temp is null, instertion is not possible \n");
    return;
  } else {
    temp -> link = header;
    header = temp;
  }
}

void insEnd() {
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter element to insert \n");
  scanf("%d",&temp->data);
  if(temp == NULL) {
    printf("instertion not possible \n");
    return;
  } else {
    p = header;
    while(p->link != NULL) p = p -> link;
    p->link = temp;
    temp->link = NULL;
  }
}

void insAny() {
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter element to insert \n");
  scanf("%d",&temp->data);
  // Read data value to add the node after
  int key;
  printf("Enter key");
  scanf("%d",&key);
  if(temp == NULL) {
    printf("Instertion not possible\n");
    return;
  } else {
    p = header;
    while((p->data != key) && (p->link != NULL)) {
      p = p->link;
    }
    if((p->link == NULL) && (p->data != key)) {
      printf("key not found or null\n");
      return;
    }
    else {
      temp->link = p->link;
      p->link = temp;
    }
  }
}

void delBeg() {
  p = header;
  if(p == NULL) {
    printf("List empty \n");
    return;
  } else {
    temp = p->link;
    header = temp;
    free(p);
  }
}

void delEnd() {
  p = header;
  if(p == NULL) {
    printf("List empty \n");
    return;
  } else {
    while(p->link !=NULL) {
      temp = p;
      p = p->link;
    }
    temp->link = NULL;
    free(p);
  }
}

void delAny() {
  p = header;
  if(p == NULL) {
    printf("List empty \n");
    return;
  } else {
    // Read key
    int key;
    printf("Enter key: \n");
    scanf("%d",&key);

    while((p->data != key) && (p->link != NULL))  {
      temp = p;
      p = p->link;
    }
    if((p->link == NULL) && (p->data != key)) {
      printf("Data not found or null");
      return;
    } else {
      if(header->data == key) {
        header = p->link;
        free(p);
      } else {
        temp->link = p->link;
        free(p);
      }
    }
  }
}

void display() {
  p = header;
  while(p != NULL) {
    printf("%d ,",p->data);
    p = p->link;
  }
  printf("\n");
}


void main() {
  int ch;
  while(1) {
    printf("1 For inster at beginning \n");
    printf("2 for insert at specific node \n");
    printf("3 for inster at end \n");
    printf("4 for delete at beginning \n");
    printf("5 for delete at specific node \n");
    printf("6 for detete at end \n");
    printf("7 for display \n");
    printf("8. exit \n");
    scanf("%d",&ch);
    switch(ch) {
      case 1: insBeg();
        break;
      case 2: insAny();
        break;
      case 3: insEnd();
        break;
      case 4: delBeg();
        break;
      case 5: delAny();
        break;
      case 6: delEnd();
        break;
      case 7: display();
        break;
      case 8: return;
      default: printf("Invalid choice");
    }
  }
}





