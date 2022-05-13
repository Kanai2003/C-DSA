#include <stdio.h>

int pow(int x,int y);           
int main(){

    int x,y,res;
    printf("Enter number \n");
    scanf("%d",&x);
    printf("Enter power \n");
    scanf("%d",&y);
    res = pow(x,y);
    return 0;
}

int pow(int x,int y){               // to calculate (power of a number) value of x^y

    if(y ==0){
        return 1;
    }else {
        return x*pow(x,y-1);
    }
}