#include <stdio.h>
#define N 20
int arr[N] = {10 ,5 , 23 , 1 , 9};
int size = 5;

void insert(int pos , int value ){
    if(pos <= size){
        for (int i = size; i>=pos ; i--){
            arr[i] = arr[i-1];
        }
    }
    arr[pos-1] = value;
    size++;
}

void delete(int pos){           //12 24 456 2 31 53 
    for(int i = pos-1 ; i < size ; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

int BinarySearch(int tar){
    for (int i = 0; i<size-1 ; i++){
        for(int j =0; j<size-1-i ; j++){
                                      
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }    
        }
    }
    int start =0;
    int end = size-1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid] == tar){
            return mid ;
        }else if(arr[mid] > tar){
            end = mid-1;
        }else{
            start = mid +1;
        }
    }
    return -1;
}

int main(){
    printf("Your array is : \n");
    for(int i = 0 ; i<size;i++){
        printf("%d ",arr[i]);
    }
    int exit = 0;
    while(exit != 1){
        int func ;
        printf("\nEnter 1 for Insert , 2 for Delete , 3 for Binary Search and 4 for exit :  ");
        scanf("%d",&func);

        switch(func){
            case 1:
                if(size != N){
                    int value , pos;
                    printf("Enter value and Position to insert : ");
                    scanf("%d%d",&value ,&pos);
                    insert(pos , value);
                }else {
                    printf("Array is full :( ");
                }
                break;
            case 2:
                if(size != 0){
                    int pos ;
                    printf("Enter position to Delete : ");
                    scanf("%d",&pos);
                    delete(pos);
                }else{
                    printf("Array is Empty :(");
                }
                break;
            case 3:
                if(size != 0){
                    int target;
                    printf("Enter Target to binary search : ");
                    scanf("%d",&target);
                    int idx = BinarySearch(target);
                    if(idx == -1){
                        printf("Target not found :(");
                    }else {
                        printf("Target found at index : %d  \n",idx);
                    }
                }else{
                    printf("Empty array :( ");
                }
                break;
            case 4 :
                exit = 1;
                break;
            default:
                printf("Enter valid input :( \n");
        }
        for(int i = 0 ; i<size ;i++){
            printf("%d ",arr[i]);
        }
    }
    
}










