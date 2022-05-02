#include <stdio.h>
int main(){
    int n ;
    printf("Enter number of lines : \n");
    scanf("%d", &n);

    for(int i = 1 ; i <= (n/2)+1 ; i++){
        for(int j =1 ; j <= (n/2)+1-i ; j++){
            printf(" ");
        }
        for(int j = i ; j>0 ; j--){
            printf("%c",'A'+j-1);
        }
        for(int j =2 ; j <= i ; j++){
            printf("%c",'A'+j-1);
        }
        printf("\n");
    }
    for(int i =1; i <= (n/2) ; i++){
        for(int j =1 ; j <= i ; j++){
            printf(" ");
        }
        for(int j = n/2+1-i ; j> 0 ; j--){
            printf("%c",'A'+j-1);
        }
        for(int j = 2; j<= n/2+1-i ; j++){
            printf("%c",'A'-1+j);
        }
        printf("\n");
    }
    return 0;    
}