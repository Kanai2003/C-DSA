#include<stdio.h>
int main(){
    printf("Enter a number to calculate sum of digit of number : ");
    int num,res=0,rem;
    scanf("%d",&num);
    while (num > 0)
    {
       rem =  num%10;
       res = res + rem;
       num = num/10;
    } 
    printf("Sum of digit of number is : %d",res);
    return 0;
}