#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void conqure(int arr[], int start, int end){
    int mid = start + (end - start + 1)/2;
    while(start < mid && mid <= end ){
        if (arr[start] > arr[mid]){
            for (int i = mid -1; i>= start ; i--){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
            start++;
            mid++;
        }else{
            start++;
        }
    }
}


void divide(int arr[], int start , int end ){
    if(start >= end){
        return;
    }   
    int mid  = start + (end - start +1)/2;
    divide(arr,start,mid-1);
    divide(arr,mid,end);
    conqure(arr,start,end);
}


void display(int arr[], int size){
    for (int i = 0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    clock_t begin = clock();
    //taking array as input 
    int size ;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    for (int i = 0 ; i< size; i++){
        arr[i] = rand() % 100 ; 
    }
    printf("Given Array : \n");
    display(arr,size);

    //sorting
    divide(arr,0,size-1);
    
    //printing the sorted array
    printf("Sorted Array : \n");
    display(arr,size);
    
    clock_t end = clock();
    double timespent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("\n Execution Time : %lf sec\n",timespent);
    return 0;
}

