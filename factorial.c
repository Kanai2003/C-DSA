#include<stdio.h>
int main(){

    // factorial-------
    // int a;
    // int result = 1;
    // printf("Enter a integer value : ");
    // scanf("%d",&a);
    // for(int i = 1;i<=a;i++){
    //     result = i*result;
    // }
    // printf("Factorial value is : %d",result);


    //nCr n!/{(n-r)!r!} -------
    int n,r,result1 = 1,result2 = 1,result3 = 1;
    printf("Enter first value for n and enter second value for r in the form of nCr : ");
    scanf("%d %d",&n,&r);
    for(int i = 1;i<=n;i++){
         result1 = i*result1;
    }
    for(int i = 1;i<=n-r;i++){
         result2 = i*result2;
    }
    for(int i = 1;i<=r;i++){
         result3 = i*result3;
    }
    int result = result1/(result2*result3);
    printf("%d",result);


}