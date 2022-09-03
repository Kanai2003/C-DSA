#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

// Function to print the whole list---------------
void printList(Node * head){
    while(head != NULL) {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//Function to delete the first node in the list--------------------
Node * deleteFirst(Node * head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    Node * next = head->next;
    free(head);
    return next;
}


// Function to delete the last node in the list--------------------
void deleteLast(Node * head){
    if(head == NULL){
        return ;
    }
    if(head->next == NULL){
        free(head);
        return ;
    }
    while(head->next->next != NULL){
        head = head->next;
    }
    head->next = NULL;
    free(head->next);
}


//Function to delete the node from the list--------------------
void deleteNode(Node * head , int index){
    int count = 0;
    while(count != index -1){
        head = head->next;
        count++;
    }
    Node * nextNode = head->next;
    head->next = head->next->next;
    free(nextNode);
}

int main (){

    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
    
    head = (Node *)malloc(sizeof( Node));
    second = ( Node *)malloc(sizeof( Node));
    third = ( Node *)malloc(sizeof(Node));
    fourth = ( Node *)malloc(sizeof( Node));

    head->data = 19;
    head->next = second;

    second->data = 29;
    second->next = third;

    third->data = 39;
    third->next = fourth;

    fourth->data = 130;
    fourth->next = NULL;

    printList(head);

    deleteNode(head , 1);

    printList(head);
    head = deleteFirst(head);
    
    printList(head);

    deleteLast(head);
    printList(head);

    return 0;
}