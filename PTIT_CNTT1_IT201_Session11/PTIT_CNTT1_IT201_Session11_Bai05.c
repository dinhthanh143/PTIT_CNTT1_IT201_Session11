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
Node *insertHead(Node *head, int data) {
   Node *newNode = createNode(data);
   if (head==NULL) {
      newNode->next = head;
      return newNode;
   }
   newNode->next = head;
   head->prev = newNode;
   return newNode;
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
   int value;
   printf("\nMoi nhap gia tri muon them: ");
   scanf("%d", &value);
   head = insertHead(head, value);
   printList(head);
   return 0;
}
