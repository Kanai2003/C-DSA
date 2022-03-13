#include <stdio.h>
int main(){
    int BS,GS;
    printf ("Enter your basic salery to calculate gross salery : ");
    scanf("%d",&BS);
    if(BS<=10000){
        GS = BS + BS*.2+BS*.8;
    }else if (BS<=20000)
    {
        GS = BS + BS*.25 + BS*.9;
    }else{
        GS = BS + BS*.3 + BS*.95;
    }
    printf("Your Gross salery is : %d",GS);
    
}