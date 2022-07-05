#include<stdio.h>
int main (){

    int size;
    printf("Enter size :");

    scanf("%d",&size);
    int arr1[size][size] , arr2[size][size] , arr[size][size];

    for(int i = 0; i < size; i++){
        printf("Enter row [%d] :", i);
        for(int j = 0 ; j < size; j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i = 0; i < size; i++){
        printf("Enter row [%d] :", i);
        for(int j = 0 ; j < size; j++){
            scanf("%d",&arr2[i][j]);
        }
    }
        
    for(int i = 0; i < size; i++){             
        for(int j = 0 ; j < size; j++){
            arr[i][j] = 0;            
            for(int k = 0 ; k < size; k++){ 
                arr[i][j] += arr1[i][j] * arr2[j][k];
            }
            
        }
    }
     for(int i = 0; i < size; i++){
        
        for(int j = 0 ; j < size; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }



    return 0;
}