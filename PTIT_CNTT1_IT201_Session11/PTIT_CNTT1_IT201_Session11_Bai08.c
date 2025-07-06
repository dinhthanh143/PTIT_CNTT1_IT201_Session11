#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
   int data;
   struct Node *next;
   struct Node *prev;
}Node;
Node *createNode(int data) {
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   newNode->prev = NULL;
   return newNode;
}
void printList(Node *head) {
   if (head==NULL) { return;}
   Node *current = head;
   int i=1;
   printf("NULL ->");
   while (current != NULL) {
      if (current->next == NULL) {
         printf(" %d -> NULL", current->data);
         break;
      }
      printf("%d <->", current->data);
      i++;
      current = current->next;
   }
}
int getLength(Node *head) {
   if (head==NULL) { return 0; }
   Node *current = head;
   int length = 0;
   while (current != NULL) {
      length++;
      current = current->next;
   }
   return length;
}
Node *deleteHead(Node *head) {
   if (head == NULL) { return NULL; }
   Node *temp = head;
   head = head->next;
   free(temp);
   return head;
}
Node *deleteTail(Node *head) {
   if (head==NULL) { return NULL; }
   Node *current = head;
   while (current->next != NULL) {
      current = current->next;
   }
   Node *temp = current;
   current = current->prev;
   current->next = NULL;
   free(temp);
   return head;
}
Node *deleteAt(Node *head, int index) {
   index--;
   if (index<0 || index>getLength(head)-1) {
      printf("\nVi tri khong hop le");
      return head;
   }
   if (index == 0) {
      return deleteHead(head);
   }
   if (index == getLength(head) - 1) {
      return deleteTail(head);
   }
   Node *current = head;
   for (int i=0; i<index; i++) {
      current = current->next;
   }
   Node *temp = current;
   Node *prev = current->prev;
   Node *next = current->next;
   prev->next = next;
   next->prev = prev;
   free(temp);
   return head;
}
int main(){
   Node *head = NULL;
   Node *tail = NULL;
   for (int i = 1; i <= 5; i++) {
      Node *node = createNode(i);
      if (head==NULL) {
         head = tail = node;
      }else {
         tail->next = node;
         node->prev = tail;
         tail = node;
      }
   }
   printList(head);
   int pos;
   printf("\nMoi nhap vi tri muon xoa: ");
   scanf("%d", &pos);
   head = deleteAt(head, pos);
   printf("\n");
   printList(head);
   return 0;
}
