#include<stdio.h>

int fact(int n);

int main(){
    int n,res;
    printf("Enter value to calculate factorial : ");
    scanf("%d",&n);
    res = fact(n);
    printf("Factorial value is = %d",res);
    
    return 0;
}

int fact(int n){            //to calculate (factorial) value of n! = n*(n-1)*...*1
    if(n==0){
        return 1;
    }else{
        return n*fact(n-1);
    }
}
