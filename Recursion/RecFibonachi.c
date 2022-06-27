#include<stdio.h>

int fibo(int n );

int main(){
    int n , res;
    printf("Enter a number \n");
    scanf("%d",&n);
    res = fibo(n);
    printf("Value = %d",res);
    return 0;
}

int fibo(int n){                //to calculate fibonachi number

    if(n<2){
        return n;
    }else {
        return ( fibo(n-1)+fibo(n-2) );
    }
}