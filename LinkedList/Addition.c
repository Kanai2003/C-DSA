#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;  
};

// Function to print the whole list ---------------------
void printList(struct Node * head){
    while(head != NULL) {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}


// Function to add a node at the first position in the list--------------------
struct Node * addFirst(struct Node * head , int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = head;

    return newNode;
}

// Function to add a node at the end of the list-----------------------
void addLast(struct Node * head , int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if(head == NULL){
        head = newNode;
        newNode->next= NULL;
        return ;
    }
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
    newNode->next = NULL;
}

// Function to add a node after a node  of the list-----------------------
void addAtIndex(struct Node * head ,int index, int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    int count = 0;
    while(count != index-1){
        head = head->next;
        count++;
    }
    newNode->next = head->next;
    head->next = newNode;
}

int main(){

    struct Node *head;
    struct Node *second;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 29;
    second->next = NULL;

    printList(head);

   

    addLast(head, 39);
    addLast(head , 130);
    printList(head);

    
    head = addFirst(head,143);
    printList(head);    


    addAtIndex(head , 3, 12);
    printList(head);

    return 0;
}



