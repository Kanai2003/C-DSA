#include<stdio.h>

int main (){
    int arr[] = {1, 2, 3, 4, 5, 6, 7 , 8};
    int low = 0;
    int high = sizeof(arr)/sizeof(arr[0]);
    int target = 5;

    while (low<=high){

        int mid  = (low + high)/2;
        
        if(arr[mid] == target){
            printf("Found at index %d\n",mid);
            break;
        }else{
            if(arr[mid]>target){
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
    } 
    return 0;
}