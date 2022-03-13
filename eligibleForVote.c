#include<stdio.h>
int main(){
    printf("Enter your age to check your voting eligibility : ");
    int a;
    scanf("%d",&a);
    if(a>=18){
        printf("You are eligible for voting :) ");
    }else printf("You are not eligible for voting :( ");
}