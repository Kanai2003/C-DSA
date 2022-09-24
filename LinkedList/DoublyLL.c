#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;
Node * init(int val){
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = val;
    head->next=NULL;
    head->prev=NULL;
    return head;
}
void addFirst(Node **head,int val){
    Node *p =*head;
    if(p == NULL){
        *head = init(val);
        return ;
    }
    Node *newNode = init(val);
    newNode->next= p;
    p->prev = newNode;
    *head=newNode;
}
void addLast(Node ** head , int val){
    Node *p = *head;
    if(p == NULL){
        *head = init(val);
        return ;
    }
    while(p->next != NULL){
        p = p->next;
    }
    Node *newNode = init(val);
    p->next=newNode;
    newNode->prev = p;
}
void display(Node *head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main(){
    Node *head = NULL;
    addLast(&head,12);
    addFirst(&head,39);
    display(head);
}
