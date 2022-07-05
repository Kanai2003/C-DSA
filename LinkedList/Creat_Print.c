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

    return 0;
}