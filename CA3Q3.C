#include <stdio.h>
int main(){
    int arr[10];
    printf("Enter values of array :-- \n");
    for(int i = 0; i<10; i++){              //array input
        printf("Enter value of array[%d] : ", i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the pass number to print array of that pass : \n");
    int pass;
    scanf("%d",& pass);

    for(int i =0; i<10; i++){           
        int flag = 0;
        for (int j =0 ; j < 10-i-1; j++){           // sorting by swaping the array
            if(arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag =1;
            }
        }
        if (flag == 0){
            break;
        }
        if(i+1 == pass){                      //printing pass 
            printf("%d pass array  is : ",pass);
            for(int j =0; j<10 ; j++){      
                printf("%d ",arr[j]);
            }
        }
    }
    
    printf("\nSorted array is : ");

    for(int i =0;i<10;i++ ){
        printf("%d  ",arr[i]);
    }


    return 0;
}