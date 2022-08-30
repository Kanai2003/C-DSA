#include <stdio.h>

#define N 5

typedef struct stack{
    int data[N];
    int top ;
}stack;

int isFull( stack *s){
    if(s->top == N-1){
        return 1;
    }else {
        return 0;
    }
}

int isEmpty( stack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push ( stack *s  ,int val){
    s->data[++(s->top)] = val;
}

int pop( stack *s ){
    return (s->data[(s->top)--]);
}

void display(stack *s){
    if (! isEmpty(s)){
        printf("The Stack is : ");
        for(int i = 0;i<=s->top;i++){
            printf("%d ",s->data[i]);
        }
    }else{
        printf("Empty stack :) nothing to display :)");
    }
}

int peek( stack *s ){
    return (s->data[s->top]);
}


int main(){
    stack s;
    s.top = -1;
    int exit = 0;
    while(exit == 0){
        printf("\n1.Push\t2.Pop\t3.Peek\t4.Display\t5.Exit\nEnter your Choice : ");
        int cho;
        scanf("%d",&cho);
        switch(cho){
            case 1:
                if(! isFull(&s)){
                    printf("Enter value to push : ");
                    int val ;
                    scanf("%d",&val);
                    push(&s,val);
                }else{
                    printf("The Stack is full :) ");
                }
                break;
            case 2:
                if (! isEmpty(&s)){
                    printf("Poped element is : %d",pop(&s));
                }else{
                    printf("The Stack is Empty :) ");
                }
                break;
            case 3:
                if (! isEmpty(&s)){
                    printf("Peeked element is : %d",peek(&s));
                }else{
                    printf("The Stack is Empty :) ");
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit = 1;
                break;
            default:
                printf("Enter valid input :) ");
        }
       
    }
    display(&s);
    printf("\nThank You :)");
    return 0;

}