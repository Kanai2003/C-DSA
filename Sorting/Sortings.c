#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int size){
    for(int i = 0; i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Bubble sort--------------------------------------
void BubbleSort(int arr[], int size){
    for(int i = 0; i< size;i++){
        for(int j = 0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
//selection sort------------------------------------
void selectionSort(int arr[],int size){
    for(int i = 0; i< size; i++){
        int min = i;
        for(int j = i; j<size;j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}
//insertion sort------------------------------------
void insertionSort(int arr[], int size){
    for(int i = 1;i<size;i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


// quick sort-------------------------------------------------
int split(int arr[], int low, int high){
    int pivot = arr[high], i = low-1;
    for(int j= low ; j<=high-1; j++){
        if(arr[j] <= pivot){
            swap(&arr[++i],&arr[j]);
        }
    }
    swap(&arr[++i],&arr[high]);
    return i;
}
//please pass higher and lower index
void quickSort(int arr[],int low , int high){
    if(low < high){
        int pi = split(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
//merge sort --------------------------------------
void conqure(int arr[],int start,int mid,int end){
    int idx1 = start;
    int idx2 = mid+1;
    int auxArr[end-start+1];
    int x = 0;
    while(idx1<=mid && idx2<=end){
        if(arr[idx1] < arr[idx2]){
            auxArr[x++] = arr[idx1++];
        }else{
            auxArr[x++] = arr[idx2++];
        }
    }
    while(idx1<=mid){
        auxArr[x++] = arr[idx1++];
    }
    while(idx2<=end){
        auxArr[x++] = arr[idx2++];
    }
    for(int i = start,j=0; i<=end && j<end-start+1;i++,j++){
        arr[i] = auxArr[j];
    }
}
void mergeSort(int arr[], int start , int end ){
    if(start >= end){
        return ;
    }
    int mid = start + (end - start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    conqure(arr,start,mid,end);
}
//Heap sort------------------------------------
void maxHeapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right < n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&arr[largest],&arr[i]);
        maxHeapify(arr,n,largest);
    }
}
void heapSort(int arr[], int n){
    //for creating a max heap
    for (int i = n/2-1; i>=0; i--){
        maxHeapify(arr,n,i);
    }
    //for deleting the max heap
    for (int i = n-1; i>=0; i--){
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i,0);
    }
}

int main(){
    int size ;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i<size ; i++){
        arr[i] = rand()%100;
    }
    display(arr,size);
    // BubbleSort(arr,size);
    // selectionSort(arr,size);
    // insertionSort(arr,size);
    quickSort(arr,0,size-1);
    // mergeSort(arr,0,size-1);
    // heapSort(arr,size);
    display(arr,size);
   
}
