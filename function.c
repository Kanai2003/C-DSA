#include<stdio.h>
void fact();
int main(){
    // int x = 5;
    fact();
    // printf("%d",result);
}
void fact(){
    int x;
    scanf("%d",&x);
    int result = 1;
    for (int i = 1; i<=x; i++){
        result = result * i;
    }
    printf("%d",result);
    return ;

}