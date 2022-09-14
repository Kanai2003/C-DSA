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
    Node *queue = NULL;
    int exit=0;
    while(exit == 0){
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your choice : ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter a integer value to insert : ");
                int val ;
                scanf("%d",&val);
                insert(&queue,val);
                break;
            case 2:
                printf("Deleted element is : %d",delete(&queue));   
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit++;
                break;
            default:
                printf("Enter valid input :) \n");

        }
    }
}