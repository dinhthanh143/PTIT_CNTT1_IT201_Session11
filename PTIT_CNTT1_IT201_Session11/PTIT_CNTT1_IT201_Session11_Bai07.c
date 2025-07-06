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
Node *insertHead(Node *head, int data) {
   Node *newNode = createNode(data);
   newNode->next = head;
   if (head != NULL) {
      head->prev = newNode;
   }
   return newNode;
}
Node *insertTail(Node *head, int data) {
   Node *newNode = createNode(data);
   Node *current = head;
   while (current->next != NULL) {
      current = current->next;
   }
   current->next = newNode;
   newNode->prev = current;
   return head;
}
Node *insertAt(Node *head, int value, int pos) {
   pos--;
   if (pos<0 || pos>getLength(head)) {
      return head;
   }
   if (pos==0) {
      return insertHead(head, value);
   }
   if (pos == getLength(head)) {
      return insertTail(head, value);
   }
   Node *newNode = createNode(value);
   Node *current = head;
   for (int i=0; i<pos; i++) {
      current = current->next;
   }
   Node *prev = current->prev;
   newNode->next = current;
   current->prev = newNode;
   prev->next = newNode;
   newNode->prev = prev;
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
   int value;
   printf("\nMoi nhap gia tri muon them:");
   scanf("%d", &value);
   int pos;
   printf("Moi nhap vi tri muon them: ");
   scanf("%d", &pos);
   printf("\n");
   head = insertAt(head, value, pos);
   printList(head);
   return 0;
}
