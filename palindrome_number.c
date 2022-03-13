#include<stdio.h>
int main(){
    printf("Enter a value to check is it a palindrome or not : ");
    int a , b,c=0;
    scanf("%d",&a);
    int d = a;
    while(a>0){
        b = a%10;
        c = c*10+b;
        a=a/10;
    }
  
    if (d==c){
        printf("This is a palindrome number :) ");
    }else printf("This is not a palindrome number :( ");

    return 0 ;
}