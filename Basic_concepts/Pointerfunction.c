#include <stdio.h>

void sum(int a, int b){
    printf("%d\n",a+b);
}

void product(int a , int b){
    printf("%d\n",a*b);
}

void substract(int a , int b){
    printf("%d\n",a-b);
}



void main(){
    void(*tint[3])(int,int) = {sum,product,substract};
    printf("Enter 0 for sum , 1 for product and 2 for substract : ");
    int  n ; 
    scanf("%d",&n);
    if(n <3 && n>=0){
        tint[n](100,20);
    }else{
        printf("Invalid Input \nPlease enter only 0 or 1 or 2 ");
    }

}


// void display(void (*tint)(int,int)){
//     tint(100,20);
// }

// void main (){
//     display(sum);
//     display(product);
//     display(substract);
// }