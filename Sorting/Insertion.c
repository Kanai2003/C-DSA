#include<stdio.h>
int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    
    //taking array input
    printf("Enter array value : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    //Insertion sorting
    // int temp;
    for(int i = 1; i < size ; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
    //printing sorted array
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}