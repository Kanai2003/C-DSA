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
        printf("stack is full :( ");
    }
}

char pop(struct stack *s ){
    return (s->data[(s->top)--]);
}
char peek(struct stack *s ){
    return (s->data[(s->top)]);
}


int main(){
    struct stack s1 , s2;
    s1.top = -1;
    s2.top = -1;
    char line[100] ;
    printf("Enter a line to reverse wordwise :\n");
    scanf("%[^\n]s",&line);
    for(int i = 0 ; line[i] != '\0' ; i++){
        push(&s1 , line[i]);
    }
    while( ! isEmpty(&s1)){
        while(peek(&s1) != ' ' && !isFull(&s2) && !isEmpty(&s1)){    
            push(&s2,pop(&s1));
        }
        while(! isEmpty(&s2)){
            printf("%c",pop(&s2));
        }
        if(peek(&s1) == ' '){
            printf("%c",pop(&s1));
        }
    }
    
    
}