// #include<stdio.h>
// int main(){
    // int N;
    // printf("Enter number of days : ");
    // scanf("%d",&N);
    // int k;
    // printf("Enter number of workers : ");
    // scanf("%d",&k);
    // int n;
    // printf("After how many days workers has left the work : ");
    // scanf("%d",&n);
    // int k1;
    // printf("How many workers left the work : ");
    // scanf("%d",&k1);
    // int exday = k*(N-n)/(k-k1) -(N-n);
    // printf("Extra days required to complete the house is = %d",exday);

    // int a =2 , b=4,x;
    // if(a>5 && b>6);
    // printf("%d",a+b);
    
    // int a,b,x;
    // x=(a=2,b=5,a+b);
    // printf("%d %d %d",a,b,x);
    
    // return 0;
// }





#include <stdio.h>

#define MAX 5

int front = -1;
int rear = -1;

int arr[MAX];

void insert (int ele) {
    if (rear == MAX - 1) {
        printf("\tOverflow !!!\n");
    } else {
        rear = rear + 1;
        arr[rear] = ele;
        if (rear == 0) {
            front = 0;
        }
    }
}

void delete () {
    int ele;
    if (front > rear) {
        printf("\tUnderflow !!!\n");
    } else {
        ele = arr[front];
        front = front + 1;
        printf("%d is deleted\n", ele);
    }
}

void display () {
    if (front == - 1 && rear == -1) {
        printf("\tUnderflow !!!\n");
        return;
    }
    for(int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {
    int ch, ele;
    while(1) {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1 : 
                printf("Enter Element: ");
                scanf("%d", &ele);
                insert(ele);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;     
            case 4: 
                return 0;
            default: 
                printf("\nInvalid Input !!! \n");
        }
    }
    return 0;
}
