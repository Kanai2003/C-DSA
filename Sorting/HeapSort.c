#include <stdio.h>

void swap(int  *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int lastIdx, int parent){
    int largest = parent, left = 2*parent+1, right = 2*parent+2;
    if(left <= lastIdx && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= lastIdx && arr[largest] < arr[right]){
        largest = right;
    }
    if(parent != largest){
        swap(&arr[parent],&arr[largest]);
        maxHeapify(arr,lastIdx,largest);
    }
}

void heapSort(int arr[], int size){
    int lastIdx = size-1;
    //build heap--- 
    for(int i =(lastIdx-1)/2 ; i>= 0; i--){ //last non-leaf node index = (lastIndex -1)/2
        maxHeapify(arr,lastIdx,i);
    }
    //delete heap
    for(int i = lastIdx; i>0; i--){
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i-1,0);
    }

}
void print(int arr[],int size){
    for(int i = 0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main (){
    int arr[] = {10,30,50,20,35,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    heapSort(arr,size);
    print(arr,size);
    return 0;
}







// this is same code but using global array (just for college assignment stuff)
// #include<stdio.h>
// int arr[] = {10,30,50,20,35,15};
// int size = sizeof(arr)/sizeof(arr[0]);

// void swap(int  *a , int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void maxHeapify( int lastIdx, int parent){
//     int largest = parent, left = 2*parent+1, right = 2*parent+2;
//     if(left <= lastIdx && arr[largest] < arr[left]){
//         largest = left;
//     }
//     if(right <= lastIdx && arr[largest] < arr[right]){
//         largest = right;
//     }
//     if(parent != largest){
//         swap(&arr[parent],&arr[largest]);
//         maxHeapify(lastIdx,largest);
//     }
// }

// void heapSort(){
//     int lastIdx = size-1;
//     //build heap--- 
//     for(int i =(lastIdx-1)/2 ; i>= 0; i--){ //last non-leaf node index = (lastIndex -1)/2
//         maxHeapify(lastIdx,i);
//     }
//     //delete heap
//     for(int i = lastIdx; i>0; i--){
//         swap(&arr[0],&arr[i]);
//         maxHeapify(i-1,0);
//     }

// }
// //to print the array
// void print(){
//     for(int i = 0; i<size; i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }
// int main (){
//     print();
//     heapSort();
//     print();
//     return 0;
// }