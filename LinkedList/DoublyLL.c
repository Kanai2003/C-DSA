#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

//creat a new node using a value and return 
Node * init(int val){
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = val;
    head->next=NULL;
    head->prev=NULL;
    return head;
}

//add a node at the first position of the linked list 
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

//add a new node at the last position of linked list
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

//add at position of a linked list
void addPosition(Node **head , int pos, int val){
    Node *p = *head;
    if(p == NULL){      //if list is empty
        *head = init(val);
        return ;
    }
    if(pos == 1){
        addFirst(head,val);
        return ;
    }
    while(pos-1 > 1 && p->next != NULL){
        p = p->next;
        pos--;
    }
    Node *newNode = init(val);
    newNode->next=p->next;
    if(p->next != NULL){    // if append to last node then No need to set previous of NULL as newNode 
        p->next->prev=newNode;
    }
    newNode->prev=p;
    p->next=newNode;
} 
//delete first node of the linked list 
void deleteFirst(Node **head){
    Node *p = *head;
    if(p == NULL){
        return ;
    }
    *head = p->next;    //move the head pointer to next pointer
    p->next->prev = NULL;   //break the link of current head node to previous node 
    free(p);
}
//delete last node of any linkded list 
void deleteLast(Node **head){
    Node *p = *head;
    if(p->next == NULL){
        printf("You lost the chain :( \n");
        *head = p->next;
        p->next->prev = NULL;
        free(p);
        return;
    }
    while(p->next != NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    p->prev = NULL;
    free(p);
}
//delete a value on a linked list 
void deleteValue(Node ** head,int val){     //incomplete function , if there is not the value then function is not working, fixed it 
    Node *p = *head;
    if(p->data == val){
        deleteFirst(head);
        return ;
    }
    while(p->data != val && p != NULL){
        p = p->next;
    }
    if(p == NULL){
        printf("%d is not in the list :) \n",val);
        return;
    }else {
        if(p->next==NULL){   //if last node containing value
            deleteLast(head);
        }else if(p!=NULL) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
        }
    }
}
//display the whole linked list
void display(Node *head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

//display the list reverse order without reversing it 
void displayRev(Node *head){
    while(head->next != NULL){
        head=head->next;
    }
    printf("REV : ");
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

int main(){
    Node *head = NULL;
    addLast(&head,12);
    addFirst(&head,39);
    display(head);
    deleteFirst(&head);
    display(head);
    displayRev(head);
    addPosition(&head,1,20);
    display(head);
    displayRev(head);
    addPosition(&head,3,142);
    display(head);
    displayRev(head);
    // deleteLast(&head);
    display(head);
    deleteValue(&head,42);
    display(head);
    displayRev(head);
    
}
