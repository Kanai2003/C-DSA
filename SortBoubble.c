#include<stdio.h>
int main (){
    int size;
    printf("Enter size of array :");
    scanf("%d",&size);
    int arr[size];
    
    //taking array input
    printf("Enter array value : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    //boubble sorting
    int flag;
    for (int i = 0; i<size-1 ; i++){
        for(int j =0; j<size-1-i ; j++){
            flag = 0;                            
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag = 1;
            }
            
        }
        if(flag == 0){
                break;
            }
        
    }

    //printing array
    for(int i =0; i<size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}