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
Node *reverseList(Node *head) {
    if (head==NULL) { return NULL; }
    if (getLength(head) == 1){ return head;}
    Node *current = head;
    Node *temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
        if (temp != NULL) {
            head = temp->prev;
        }
    }
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
    printf("\n");
    head = reverseList(head);
    printList(head);
    return 0;
}
