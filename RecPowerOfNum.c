#include <stdio.h>

int power(int x,int y);           
int main(){

    int x,y,res;
    printf("Enter number \n");
    scanf("%d",&x);
    printf("Enter power \n");
    scanf("%d",&y);
    res = power(x,y);
    printf("Result  =  %d",res);
    return 0;
}

int power(int x,int y){               // to calculate (power of a number) value of x^y

    if(y ==0){
        return 1;
    }else {
        return x*power(x,y-1);
    }
}