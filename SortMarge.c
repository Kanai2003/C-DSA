#include <stdio.h>

void divide(int arr[],int start , int end);

void conqure(int arr[],int start ,int mid, int end);

int main(){
    //taking array as input 
    int size ;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    for(int i =0 ; i<size;i++){
        printf("Enter Array[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    //sorting
    divide(arr,0,size-1);
    
    //printing the sorted array
    for(int i =0 ; i<size;i++){
        printf(" %d ",arr[i]);
    }
    
    return 0;
}

void divide(int arr[], int start , int end ){
    if(start >= end){
        return;
    }
        
    int mid  = start + (end - start)/2;
    divide(arr,start,mid);
    divide(arr,mid+1,end);
    conqure(arr,start,mid,end);
}

void conqure(int arr[], int start, int mid, int end){
    int mar[end - start + 1];
    int idx1 = start;
    int idx2 = mid+1;
    int x = 0;
    while(idx1 < mid && idx2 < end){      
        if(arr[idx1] <= arr[idx2]){
            mar[x++] = arr[idx1++];
        }else{
            mar[x++] = arr[idx2++];
        }
    }

    while (idx1 < mid){
        mar[x++] = arr[idx1++];
    }

    while (idx2 < end){
        mar[x++] = arr[idx2++];
    }

    for(int i=0,j=start ; i <= end ; i++,j++){
        arr[j]= mar[i];
    }

}
