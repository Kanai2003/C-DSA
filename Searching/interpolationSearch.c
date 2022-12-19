//Interpolation search is more efficient than Binary search
#include<stdio.h>
int interpolationSearch(int arr[],int high,int key){
    int low = 0;
    while(low<high){
        int mid = low + (high-low)*(key-arr[low])/(arr[high]-arr[low]);
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}
int main (){
    //the arry has to be sorted
    int size ;
    printf("Please enter no of elements : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter sorted values : ");
    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the key value to search : ");
    int key ;
    scanf("%d",&key);
    int result = interpolationSearch(arr,size-1,key);
    if(result == -1){
        printf("%d is not in the array :(",key);
    }else{
        printf("%d has been found at index %d :)",key,result);
    }
}