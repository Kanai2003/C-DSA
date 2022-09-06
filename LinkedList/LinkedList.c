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
    if(head->next == NULL){
        printf("You have only Element :) , you can't delete right now :)\n");
        return;
    }
    while(head->next->next != NULL){
        head = head->next;
    }
    head->next=NULL;
    free(head->next);
}

//delete a Node by its value
void deleteValue(Node **head,int val){
    Node *temp = *head;
    if(temp == NULL){
        printf("List is empty :)");
        return;
    }
    //if first node contain the data
    if(temp->data==val){
        *head = temp->next;
        free(temp);
        return ;
    }
    while(temp->next->data != val){
        temp=temp->next;
    }
    Node * extra = temp->next;
    temp->next = temp->next->next;
    extra = NULL;
    free(extra);
}

//concat 2nd list into 1st list, pass two head veriable and 
void concat(Node *head1,Node *head2){
    if(head1 == NULL && head2==NULL){
        printf("Both lists are empty list :) \n");
        return ;
    }
    while(head1->next != NULL){
        head1 = head1->next;
    }
    head1->next = head2;
}

//reverse a linked list, pass address of head node 
void reverse(Node **head){
    Node *prev=NULL;
    Node *curr = *head;
    Node *newNode;
    while(curr != NULL){
        newNode = curr->next;
        curr->next=prev;
        prev=curr;
        curr=newNode;
    }
    *head=prev;
//this function will arrange all the nodes wirh assending order, pass address of the head and value
void addToAssendingList(Node **head,int val ){
    if(*head == NULL){ //if list contain nothing
        *head = init(val);
        return;
    }
    Node *newNode = init(val);
    Node *temp=*head;
    if(temp->data > val){//add to first
        newNode->next=temp;
        *head=newNode;
        return;
    }
    //add last and middle
    while(temp->next != NULL && temp->next->data < val){
        temp=temp->next;
    }
    if(temp->next == NULL){
        temp->next=newNode;
        return ;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

//Bouble sort of any linked list 

int main(){
    
    Node *head1 = init(39);
    addFirst(&head1,12);
    addLast(head1,143);
    addLast(head1,114);
    addatpos(&head1,4,130);
    display(head1);
    
    Node *head2 = init(9);
    addLast(head2,8838);
    addLast(head2,38);
    addLast(head2,17775);
    display(head2);

    concat(head1,head2);
    display(head1);

    reverse(&head1);
    display(head1);
    reverse(&head1);
    display(head1);

    Node *head3=init(9);
    addToAssendingList(&head3,3);
    addToAssendingList(&head3,4);
    addToAssendingList(&head3,1);
    addToAssendingList(&head3,5);
    display(head3);
       
}