#include<stdio.h>
int main(){
    int arr[] = {1,54,2,5,7,9,2,8};
    int  max , size = sizeof(arr)/sizeof(arr[0]);
    // for(int i = size-1 ; i>0;i--){
    //     max = i;
    //     for(int j = 0; j<i; j++){
    //         if(arr[max] < arr[j]){
    //             max = j;
    //         }
    //     }
    //     int temp = arr[max];
    //     arr[max] = arr[i];
    //     arr[i] = temp;
    // }
    for(int i = 0; i<size; i++){
        int max = i;
        for(int j = i+1;j<size ; j++){
            if(arr[j]<arr[max]){
                max = j;
            }
        }
        int temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
    }
    for(int i = 0; i<size;i++){
        printf("%d ",arr[i]);
    }
}