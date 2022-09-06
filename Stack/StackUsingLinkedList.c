#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

// Initialize a Node only using a value, pass only head variable
Node * init(int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

//print the Linked list, pass only head veriable
void display(Node *head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//return size or no of element of the linked list, pass only head veriable
int size(Node *head){
    int count=0;
    if(head == NULL){
        return count;
    }
    while(head != NULL){
        head = head->next;
        count++;
    }
    return count;
}
//at the time of calling this function , pass address of head node
void push(Node **head,int val){
    Node *newNode = init(val);
    newNode->next = *head;
    *head = newNode;
}
// return top element value
int pop(Node **head){
    Node *temp = *head;
    int data = temp->data;
    *head = temp->next;
    return data ;
}
//pass only head veriable 
int peek(Node *head ){
    return head->data;
}

int main (){
    Node *head = init(6);
    push(&head,39);
    push(&head,12);
    push(&head, 114);
    display(head);
    printf("\t%d\n",peek(head));
    printf("%d\n",pop(&head));
    printf("%d\n",pop(&head));
    printf("%d\n",pop(&head));
    printf("\t%d\n",peek(head));
    printf("%d\n",pop(&head));
    display(head);
    return 0;
}
