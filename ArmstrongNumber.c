#include<stdio.h>
#include<Math.h>
int main (){
    int n ,sum=0;
    printf("Enter a number :");
    scanf("%d",&n);
    int m = 0;
    int copy = n;
    while(copy>0){
        m++;
        copy/=10;
    }
    copy=n;
    while(copy > 0){
        sum += pow(copy%10,m);
        copy/=10;
    }
    
    if(sum == n){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}