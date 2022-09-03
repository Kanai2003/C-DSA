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
void addFirst(Node **head,int val){
    Node *newNode = init(val);
    newNode->next = *head;
    *head = newNode;
}

//add a node at the end of the list, pass only head variable
void addLast(Node *head ,int val){
    Node *newNode = init(val);
    newNode->data = val;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
}

//add a node at any position of the list(first/last/middle),pass address of the head
void addatpos(Node** head,int pos,int val){
    if(*head == NULL){ //when list is null
        *head = init(val);
    }else if(pos == 1){ // add at begining
        Node *newNode = init(val);
        newNode->next = *head;
        *head = newNode;
        return;
    }else{ //add any point
        Node *temp = *head;
        for(int i = 1;i<pos-1;i++){   //moving the temp variable upto (pos - 1)
            temp = temp->next;
            if (temp == NULL){
                printf("Your List is not enough to reach at position %d :( \n%d is not added to list :) please enter valis position \n",pos,val);
                return ;
            }
        }
        Node *newNode = init(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//delete first element, pass address of the head 
void deleteFirst(Node **head){
    if (*head == NULL){
        printf("The list has no element :) ");
        return ;
    }
    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

//delete last element, pass only head veriable
void deleteLast(Node *head){
    if(head == NULL){
        printf("The list has no element :) \n");
        return;
    }
    if(head->next=NULL){
        free(head);
        return;
    }
    while(head->next->next != NULL){
        head = head->next;
    }
    head->next=NULL;
    free(head->next);
}
int main(){
    
    Node *head = init(39);
    display(head);
    addatpos(&head,1,114);
    display(head);
    deleteFirst(&head);
    // deleteLast(head);
    display(head);
    addatpos(&head,2,130);
    // deleteLast(head);
    display(head);
    addFirst(&head,12);
    display(head);
    addLast(head,114);
    display(head);
    addatpos(&head,3,128);
    display(head);
    printf("Size : %d\n",size(head));
    deleteFirst(&head);
    display(head);
    // deleteLast(head);
    display(head);
    
}