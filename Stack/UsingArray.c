#include <stdio.h>
#define N 20

struct stack{
    int data[N];
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

void push (struct stack *s  ,int val){
    if(! isFull(s)){
        s->data[++(s->top)] = val;
    }else {
        printf("stack is full :(");
    }
}

int pop(struct stack *s ){
    return (s->data[(s->top)--]);
}

int peek(struct stack *s ){
    return (s->data[s->top]);
}

int main (){
    struct stack *s1 , *s2;
    s1->top = -1;
    push(s1,1);
    int res = peek(s1);
    printf("hello %d",res);
}
