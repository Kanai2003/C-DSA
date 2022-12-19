#include <stdio.h>

//function for swaping two int
// void swap(int *a, int *b) {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }


int partition(int array[], int low, int high) {
    int pivot = array[low];
    int i = low+1;
    int j = high;
    while(j>=i){
        while(array[i]<pivot){
            i++;
        }
        while(array[j]>pivot){
            j--;
        }
        if(j>i){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    return j;
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
        printf("Enter arr[%d] : ", i);
        scanf("%d",&data[i]);
    }
    
    
    printf("Unsorted Array\n");
    printArray(data, n);
    
    // perform quicksort on data
    quickSort(data, 0, n - 1);
    
    printf("Sorted array in ascending order: \n");
    printArray(data, n);

    return 0;
}