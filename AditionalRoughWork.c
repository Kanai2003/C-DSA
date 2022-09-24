// #include <stdio.h>  
// #include <ctype.h>  
// #define N 50  

// struct stack{
//     char data[N];
//     int top ;
// };
// int isFull(struct stack *s){
//     if(s->top == N-1){
//         return 1;
//     }else {
//         return 0;
//     }
// }

// int isEmpty(struct stack *s){
//     if(s->top == -1){
//         return 1;
//     }else{
//         return 0;
//     }
// }

// void push (struct stack *s  ,char val){
//     if(! isFull(s)){
//         s->data[++(s->top)] = val;
//     }else {
//         printf("stack is full :( ");
//     }
// }

// char pop(struct stack *s ){
//     return (s->data[(s->top)--]);
// }
// char peek(struct stack *s ){
//     return (s->data[(s->top)]);
// }
   
// int pr(char symbol) {                   
//     if(symbol == '^')  {  
//         return(3);  
//     }else if(symbol == '*' || symbol == '/')  {  
//         return(2);  
//     }else if(symbol == '+' || symbol == '-'){  
//         return(1);  
//     }else{  
//         return(0);  
//     }  
// }  

//   /* Main Program */  
// void main() {    
//     struct stack s;  
//     s.top=-1; 
//     char infix[50] , postfix[50],ch,elem;
//     printf("Enter infix exp :");
//     scanf("%s",&infix);
//     int i =0,k=0;
//     push(&s,'#');
//     while( (ch=infix[i++]) != '\0'){
//         if(ch == '('){
//             push(&s,ch);
//         }else{
//             if(isalnum(ch)){
//                 postfix[k++] = ch ; 
//             }else{
//                 if(ch == ')'){
//                     while(s.data[s.top] != '('){   
//                         postfix[k++] = pop(&s);
//                     }
//                     elem = pop(&s);   
//                 }else{
//                     while(pr(s.data[s.top]) >= pr(ch)){
//                         postfix[k++] = pop(&s);
//                     }
//                     push(&s,ch);
//                 }
//             }
//         }
//     }  
//     while( s.data[s.top] != '#')       
//         postfix[k++]=pop(&s);  
//     postfix[k]='\0';            
//     printf("\nPostfix Expression =  %s\n",postfix); 
     
    
// }





#include <stdio.h>
int main (){
    for(int i =0; i<4;i++){
        int name ;
        printf("\n1.Adrija\t2.Subidita\t3.Ritam\t\t4.Kanai\nEnter your choice : ");
        scanf("%d",&name);
        switch(name){
            case 1:
                printf("Vogoban + Talent Overflow");
                break;
            case 2:
                printf("Vogoban + Talent Overflow");
                break;
            case 3:
                printf("Vogoban + Talent Overflow");
                break;
            case 4:
                printf("Talent nahi hay to keya bataun :'( ");
                break;
            default:
                printf("Doya kore nijer name er number din :)");
        }
    }
    printf("\ndhonyobad vogoban gon amar vul sudhre dewar janno :) ");


    return 0;
}