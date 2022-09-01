#include <stdio.h>
#define N 5
typedef struct queue{
    int data[N];
    int rear;
}queue;
int isEmpty(queue *q){
    if(q->rear == -1){
        return 1;
    }
    return 0;
}
int isFull(queue *q){
    return (q->rear+1)==N;
}
void push(queue *q, int val){
    if( isFull(q)){
        printf("Queue is Full :(  , %d is not pushed to Queue\n",val);
        return;
    }
        //assending
    if(val >= q->data[q->rear]){
        q->rear++;
        q->data[q->rear] = val;
    }else{
        int i =q->rear;
        while(q->data[i]>val){
            q->data[i+1] = q->data[i];
            i--;
        }
        q->data[i+1] = val;
        q->rear++;
    }  
}
int pop(queue *q ){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return -1;
    }
    int val = q->data[0];
    for(int i = 0 ; i < q->rear; i++){
        q->data[i] = q->data[i+1];
    }
    q->rear--;
    return val;
}
int peek(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return -1;
    }
    return q->data[0];
}
int size(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return -1;
    }
    return q->rear+1;
}
void display(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return ;
    }
    printf("Your Queue is :  ");
    for(int i = 0 ; i<=q->rear; i++){
        printf("%d ",q->data[i]);
    }
}
int main(){
    queue q1;
    q1.rear = -1;
    int exit = 0;
    printf("Queue is Empty, Capacity is %d, now modify it :)\n",N);
    while(exit == 0){
        int func;
        printf("\n\t1.push \n\t2.pop \n\t3.peek \n\t4.size \n\t5.display \n\t6.exit  \nEnter Your Choice : ");
        scanf("%d",&func);
        switch(func){
            case 1:
                printf("Enter a value : ");
                int val;
                scanf("%d",&val);
                push(&q1,val);
                break;
            case 2:
                printf("Poped element is : %d\n",pop(&q1));
                break;
            case 3:
                printf("Peeked element is : %d\n",peek(&q1));
                break;
            case 4:
                printf("Size of the Queue is : %d\n",size(&q1));
                break;
            case 5:
                display(&q1);
                break;
            case 6:
                exit = 1;
                break;
            default:
                printf("Enter a valid input :( \n");
        }
    }
    return 0;
}