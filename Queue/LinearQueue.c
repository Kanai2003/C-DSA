#include<stdio.h>
#define size 5
typedef struct queue{
    int data[size];
    int front ;
    int rear;
}queue;
void insert(queue *q,int val){
    if(q->rear == size-1){
        printf("Queue is full :) ");
        return ;
    }
    if(q->rear == -1 && q->front == -1){
        q->front++;
        q->rear++;
    }else {
        q->rear++;
    }
    q->data[q->rear] = val;
}
int delete(queue *q){
    if(q->front == -1 || q->front>q->rear){
        printf("Queue is empty :) ");
        return -1;
    }
    return q->data[(q->front)++];
}
void display(queue *q){
    if(q->front == -1 || q->front>q->rear){
        printf("Queue is empty :) ");
        return;
    }
    printf("Queue : ");
    for(int i = q->front; i<=q->rear;i++){
        printf("%d ",q->data[i]);
    }
}

int main (){
    queue q;
    q.front=-1;
    q.rear=-1;
    int exit=0;
    while(exit == 0){
        printf("\n1.Insert\t2.Delete\t3.Display\4.Exit\nEnter your choice : ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter a integer value to insert : ");
                int val ;
                scanf("%d",&val);
                insert(&q,val);
                break;
            case 2:
                printf("Deleted element is : %d",delete(&q));   
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit ++;
                break;
            default:
                printf("Enter valid input :) \n");

        }
    }
    return 0;
}