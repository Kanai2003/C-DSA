#include <stdio.h>

int arr[] = {10,30,50,20,35,15};
int size = sizeof(arr)/sizeof(arr[0]);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int lastIndex, int parent){
    int largest = parent, left = parent*2+1, right = parent*2+2;
    if(left <= lastIndex && arr[left]>arr[largest]){
   	    largest = left;
    }
    if(right <= lastIndex && arr[right] > arr[largest]){
   	    largest = right;
    }
    if(parent != largest){
        swap(&arr[parent],&arr[largest]);
        maxHeapify(lastIndex, largest);
    }

}

void heapSort(){
    int lastIndex = size-1;
    for(int i = (lastIndex-1)/2 ; i >= 0; i--){
   	    maxHeapify(lastIndex,i);
    }
    for(int i = lastIndex; i>0; i--){
        swap(&arr[0], &arr[i]);
        maxHeapify(i-1, 0);
    }
}

void printArray(){
    for( int i = 0; i<size; i++){
   	    printf("%d ",arr[i]);
    }
    printf("\n");
}

int main (){

    printf("Unsorted array :: \n");
    printArray();
    
    heapSort();
    
    printf("Sorted array :: \n");
    printArray();
    
    return 0;
}

