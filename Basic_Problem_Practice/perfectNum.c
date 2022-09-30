#include<stdio.h>
int main (){
    int n,m=1;
    printf("Enter a number : ");
    scanf("%d",&n);
    for(int i = 2 ; i <= n/2 ; i++){
        if(n%i == 0){
            m+=i;
        }
    }
    
    if(n == m){
        printf("%d is a perect number :)",n);
    }else{
        printf("%d is not a perfect number :(")
    }
    return 0;
}