#include<stdio.h>
int main (){
    int arr[]={1,4,7,9,2,3,6,8,12,16,13,18,16,26,24,58};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int flag;
    for (int i = 0; i<size-1 ; i++){
        for(int j =0; j<size-1-i ; j++){
            // flag = 0;                            //
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag = 1;
            }
        }
        // if(flag == 0){
        //     break;
        // }
    }
    for(int i =0; i<size-1; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}