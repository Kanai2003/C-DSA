#include <stdio.h>
#define N 5
typedef struct queue{
    int data[N];
    int front ;
    int rear;
}queue;
int isEmpty(queue *q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }
    return 0;
}
int isFull(queue *q){
    return (((q->rear+1)%N) == q->front);
}
void push(queue *q , int val){
    if( isFull(q)){
        printf("Queue is Full :(  , %d is not pushed to Queue\n",val);
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear+1)%N;
    q->data[q->rear] = val;
}
int pop(queue *q ){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return -1;
    }
    int res = q->data[q->front];
    if(q->front == q->rear){
        q->front = -1;   //only one element is present
        q->rear = -1;
    }else{
        q->front  = (q->front+1)%N;
    }
    return res;
}
int peek(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return -1;
    }
    return (q->data[q->front]);
}
int size(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return -1;
    }
    if(q->front <= q->rear){
        return (q->rear - q->front + 1);
    }else{
        return ((N-q->front) + q->rear +1);
    }
}
void display(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue :( \n");
        return ;
    }
    printf("Your Queue is :  ");
    if(q->front <= q->rear){
        for(int i = q->front ; i <= q->rear ;i++){
            printf("%d ",q->data[i]);
        }
        printf("\n");
    }else{
        for(int i = 0 ; i<=q->rear; i++){
            printf("%d ",q->data[i]);
        }
        if (q->front - q->rear != 1){
            printf("{%d to %d index is Empty} ",q->rear+1,q->front-1);
        }
        for(int i =q->front ; i < N;i++){
            printf("%d ",q->data[i]);
        }
        printf("\n");
    }
}
int main(){
    queue q1;
    q1.front = -1;
    q1.rear = -1;
    int exit = 0;
    printf("Queue is Empty, Capacity is %d, now modify it :)\n",N);
    while(exit == 0){
        int func;
        printf("\n\t1.push \n\t2.pop \n\t3.peek \n\t4.size \n\t5.display \n\t6.exit : \nEnter Your Choice : ");
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