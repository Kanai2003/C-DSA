#include<stdio.h>
int main(){
    int a = 5,i,j;
    for( i = 1; i <= a; i++){
       for(j = 1 ; j <= i; j++){
           printf("%d",j);
       }
       printf("\n");
    }
}