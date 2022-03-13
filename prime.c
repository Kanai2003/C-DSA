#include<stdio.h>
int main(){
    int a ;
    int b=0;
    printf("Enter a integer value : ");
    scanf("%d",&a);
    if (a<=2){
        printf("Enter a value which is greater than 2 ");
        return 0;
    }
    for(int i = 2 ; i<a; i++){
        if (a%i == 0){
            b=1;
            break;
        }
    }
    if(b == 1){
        printf("Input Number is not a prine number :( ");
    }else printf("Input number is a prime number :) ");

}