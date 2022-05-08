#include<stdio.h>
int main(){
    int arr[] = {1,54,2,5,7,9,2,8};
    int max , idx , size = sizeof(arr)/sizeof(arr[0]);
    for(int i = size-1 ; i>0;i--){
        max = arr[i];
        idx = i;
        for(int j = i; j<i; j++){
            if(arr[j]>max){
                max=arr[j];
                idx=j;
            }
            arr[idx]=arr[i];
            arr[i]=max;
        }
    }
    for(int i = 0; i<size;i++){
        printf("%d ",arr[i]);
    }
}