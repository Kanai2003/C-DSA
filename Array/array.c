#include<stdio.h>
int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size] , rem , num ;
    printf("Enter number (<%d) of vallue to give as input : ",size);
    scanf("%d",&num);
    for(int i=0; i<num ; i++){
        printf("Enter Array[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    rem = size - num;
    printf("No. of element present = %d \nRemaining %d\nDo you want to take input ? (y/n) : ",num,rem);
    char per;
    scanf("%c",&per);
    scanf("%c",&per);
    switch(per){
        case 'n':
        case 'N':
            for(int i =0; i<num; i++){
                printf("%d ",arr[i]);
            }
            break;
        
        case 'Y':
        case 'y':
            printf("Remaining only %d\nHow much ? :",rem);
            scanf("%d",&num);
            if(num<=rem){
                for(int i = size-rem;i<size;i++){
                    printf("Array[%d] : ",i);
                    scanf("%d",&arr[i]);
                }
                rem -= num ;
            }else printf("Invalid input \n");
            for(int i =0; i<size-rem;i++){
                printf("%d ",arr[i]);
            }
            break;
    }

    return 0;
}