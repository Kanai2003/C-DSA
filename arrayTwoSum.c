#include<stdio.h>
int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int target, arr[size];
    printf("Enter values of Array : \n");
    for(int i =0 ; i < size ; i++){
        printf("Value of Array[%d] : ", i);
        scanf("%d",&arr[i]);
    }
    printf("Enter Target : ");
    scanf("%d",&target);
    int flag = 0;
    for(int i = 0; i <size ; i++){
        for(int j = i ; j < size ; j++){
            if(arr[i]+arr[j] == target ){
                flag = 1;
                printf("Index of the array value is : %d & %d \n", i , j);
            }
        }
    }
    if(flag == 0){
        printf("Array value Mismatch"); 
    }
    return 0;
}