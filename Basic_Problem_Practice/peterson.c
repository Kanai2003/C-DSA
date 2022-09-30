#include<stdio.h>
int main(){
    int n , copy, sum=0,fact=1;
    printf("Enter a number : ");
    scanf("%d",&n);
    copy = n;
    while(copy>0){
        fact = 1;
        int digit = copy %10;
        for(digit;digit>1;digit--){
            fact *= digit;
        }
        sum +=fact;
        copy /= 10;
    }
    if(sum == n){
        printf("%d is Peterson number \n",n);
    }else 
        printf("%d is not Peterrson number \n");

    return 0;
}