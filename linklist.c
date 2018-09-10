#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
   struct node *prev;
};

//display the list
void printList(struct node *head) {

   struct node *ptr = head;

   //printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" Current= %d\n  ",ptr->data);
      if(ptr->next != NULL)
          printf(" Next= %d\n  ",ptr->next->data);
      else
          printf(" Next is null\n  ");

      if(ptr->prev != NULL)
          printf(" Prev= %d\n  ",ptr->prev->data);
      else
          printf(" Prev is null \n  ");
      printf("*****************************\n");
      ptr = ptr->next;
   }

   //printf(" [null]\n");
}

//insert link at the first location
int insert(int data, struct node *h) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));

   //link->key = key;
   link->data = data;
   
   //assign prev
   link->prev =NULL;

   //assign next->prev
   if(h != NULL){
      h->prev = link;
   }   

   //point it to old first node
   link->next = h;

   //point first to new first node
   h = link;
   
   //printf("%d",data);
   return h;
   
}

void freeList(struct node *h)
{
   struct node *l;

   while (h != NULL)
    {
       l= h;
       h = h->next;
       printf("\nFreeing address at location: %p, which is currently saving the value of %d\n", l, l->data);
       free(l);
    }
   printf("\nHead now equals NULL.\n");
}

int main() {
   struct node *head = NULL;
   head=insert(1, head);
   //printf("%d",head);
   head=insert(2, head);
   head=insert(3, head);
   head=insert(4, head);
   head=insert(5, head);
   printList(head);
   freeList(head);
   return 0;
}
