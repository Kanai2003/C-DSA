#include<stdio.h>
int withOutUsing3rdVeriable(int a,int  b);
int main(){
    int a,b;
    printf("Enter two integer value : ");
    scanf("%d %d",&a,&b);

    //with out using third veriable ------------
    // a = a+ b;        // a= 20 b=30   a=50 b=50-30=20 a=a-b=50-20=30
    // b = a-b;
    // a = a-b;

    //with using third verible----------
    int c;
    c=a;
    a=b;
    b=c;

    printf("after swap a=%d b=%d",a,b);
    return 0;
}
