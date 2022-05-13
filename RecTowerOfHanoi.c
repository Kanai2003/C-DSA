#include<stdio.h>

void tow(int n, char s , char a , char d);   //n=number of dice , s = source , a = additional tower , d = destination

int main(){
    int n;
    printf("Enter number of dice \n");
    scanf("%d",&n);
    tow(n,'s','a','d');
    return 0;
}

void tow(int n , char s , char a , char d){     //Tower of Hanoi
    if(n==1){
        printf("Move to %c to %c \n",s,d);
        return;
    }else{
        tow(n-1,s,d,a);
        printf("Move to %c to %c \n",s,d);
        tow(n-1,a,s,d);
    }
    return;
}