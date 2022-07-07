#include<stdio.h>    //holandric butterfly pattern
int main(){
    int n ;
    printf("Enter a number : ");
    scanf("%d",&n);

    //upper part
    for(int i =1 ; i<n ; i++){
        for(int j =1 ; j<=i ; j++){
            if(j==1){
                printf("*");
            }
            if(j>1 && j<i){
                printf(" ");
            }
            if(j==i && i != 1){
                printf("*");
            }
        }
        for(int j =0 ; j< 2*(n-i) ; j++){
            printf(" ");
        }
        for(int j =1 ; j<=i ; j++){
            if(j==1){
                printf("*");
            }
            if(j>1 && j<i){
                printf(" ");
            }
            if(j==i && i != 1){
                printf("*");
            }
        }
        printf("\n");
    }

    //middle line
    for(int i = 1; i<=2*n ; i++){
        printf("*");
    }
    printf("\n");

    //lowert part
    for(int i =n-1 ; i>0 ; i--){
        for(int j =1 ; j<=i ; j++){
            if(j==1){
                printf("*");
            }
            if(j>1 && j<i){
                printf(" ");
            }
            if(j==i && i != 1){
                printf("*");
            }
        }
        for(int j =0 ; j< 2*(n-i) ; j++){
            printf(" ");
        }
        for(int j =1 ; j<=i ; j++){
            if(j==1){
                printf("*");
            }
            if(j>1 && j<i){
                printf(" ");
            }
            if(j==i && i != 1){
                printf("*");
            }
        }
        printf("\n");
    }
}