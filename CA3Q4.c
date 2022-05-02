#include <stdio.h>
int main(){
    int x , y;
    printf("Enter rent of double sharing room : \n");
    scanf("%d",&x);
    printf("Enter rent of triple sharing room : \n");
    scanf("%d",&y);
    if(x*3 < y*2){
        printf("Booked double sharing room and total rent is  %d",x*3);
    }else {
        printf("Booked triple sharing room and total rent is  %d",y*2);
    }


    return 0;
}