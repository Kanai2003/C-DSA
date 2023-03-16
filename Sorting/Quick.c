#include <stdio.h>
#include <stdlib.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// int partition(int array[], int low, int high) {
//     int pivot = array[low];
//     int i = low+1;
//     int j = high;
//     while(j>=i){
//         while(array[i]<pivot){
//             i++;
//         }
//         while(array[j]>pivot){
//             j--;
//         }
//         if(j>i){
//             int temp = array[i];
//             array[i] = array[j];
//             array[j] = temp;
//         }
//     }
//     int temp = array[low];
//     array[low] = array[j];
//     array[j] = temp;

//     return j;
// }


int partition(int arr[], int start , int end){
    int i = start-1, pivot = arr[end];
    for (int j = start; j<end; j++){
        if(arr[j] <=  pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return (i+1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
            int pi = partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
    }
}

// function to print array elements
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// main function
int main() {
  
  
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int data[n];
    for (int  i = 0; i < n; i++)
    {
        data[i] = rand()%100;
    }
    
    
    printf("Unsorted Array\n");
    printArray(data, n);
    
    // perform quicksort on data
    quickSort(data, 0, n - 1);
    
    printf("Sorted array in ascending order: \n");
    printArray(data, n);

    return 0;
}