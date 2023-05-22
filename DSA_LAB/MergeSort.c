#include<stdio.h>

int arr[] = {7,1,9,0,4,3,6};
int size = sizeof(arr)/sizeof(arr[0]);
	
void conqure(int start,int mid,int end){
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
void mergeSort(int start , int end ){
    if(start >= end){
        return ;
    }
    int mid = start + (end - start)/2;
    mergeSort(start,mid);
    mergeSort(mid+1,end);
    conqure(start,mid,end);
}



int main(){

	
	mergeSort(0,size-1);
	for(int i = 0; i< size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

