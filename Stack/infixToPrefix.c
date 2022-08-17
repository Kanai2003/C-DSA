#include<stdio.h>
#include<string.h>
#define N 20

struct stack{
    char data[N];
    int top ;
};
int isFull(struct stack *s){
    if(s->top == N-1){
        return 1;
    }else {
        return 0;
    }
}

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void push (struct stack *s  ,char val){
    if(! isFull(s)){
        s->data[++(s->top)] = val;
    }else {
        printf("stack is full :(");
    }
}

char pop(struct stack *s ){
    return (s->data[(s->top)--]);
}


int main (){
    struct stack s;
    
    
}