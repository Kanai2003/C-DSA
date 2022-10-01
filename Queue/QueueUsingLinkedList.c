#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data ;
    struct Node * next;
}Node;
Node * init(int val ){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void insert(Node ** head,int data){
    Node *newNode = *head;
    if(newNode == NULL){
        *head = init(data);
        return;
    }
    while(newNode->next != NULL){
        newNode = newNode->next;
    }
    newNode->next=init(data);
}
int delete(Node**head){
    Node *newNode = *head;
    if(newNode == NULL){
        printf("Empty Queue :) ");
        return -1;
    }
    int data = newNode->data;
    *head = newNode->next;
    return data;
}
void display(Node *head){
    if(head == NULL){
    printf("Empty Queue :) ");
    return ;
    }
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}
int main (){
    
}