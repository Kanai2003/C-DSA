#include<stdio.h>
int main(){
    printf("Enter a integer valur to check if it is a perfect square : ");
    int a,b;
    scanf("%d",&a);
    for (int i =1; i<=a;i++){
        if(i*i == a){
            printf("%d is perfect square of %d",a,i);
            return 0;
        }
    }
    printf("%d is not a perfect square numbrr :(",a);
}