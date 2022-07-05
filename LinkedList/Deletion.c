#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to print the whole list---------------
void printList(struct Node * head){
    while(head != NULL) {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//Function to delete the first node in the list--------------------
struct Node * deleteFirst(struct Node * head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;

    }
    struct Node * next = head->next;
    free(head);
    return next;
}


// Function to delete the last node in the list--------------------
void deleteLast(struct Node * head){
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
void deleteNode(struct Node * head , int index){
    int count = 0;
    while(count != index -1){
        head = head->next;
        count++;
    }
    struct Node * nextNode = head->next;
    head->next = head->next->next;
    free(nextNode);
}

int main (){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

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