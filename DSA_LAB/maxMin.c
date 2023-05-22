#include<stdio.h>
#include<stdlib.h>

int arr[] = {10,20,45,50,56,64,78,89,91,100};
int size = sizeof(arr)/sizeof(arr[0]);

int maxMin1(int *max , int *min){
    int count = 0;
    *min = *max = arr[0];
    for(int i = 1; i <size ; i++){
        count++;
        if(arr[i] < *min){
            *min = arr[i];
        }
        count++;
        if(arr[i] > *max){
            *max = arr[i];
        }
    }
    return count;
}

int maxMin2(int *max , int *min){
    int count = 0;
    *min = *max = arr[0];
    for(int i = 1; i <size ; i++){
        count++;
        if(arr[i] > *max){
            *max = arr[i];
        }else{
            count++;
            if(arr[i] < *min){
                *min = arr[i];
            }
        }
    }
    return count;
}

int dacMax,dacMin;
void maxMin_dac(int low, int  high){
    int min1, max1, mid;
    if(low == high){
   	    dacMin = dacMax = arr[low];
    }else if(low == high-1){
        if(arr[low] < arr[high]){
            dacMax = arr[high];
            dacMin = arr[low];
        }else{
            dacMax = arr[low];
            dacMin = arr[high];
   	    }
    }else{
        int mid = low + (high-low)/2;

        maxMin_dac(low,mid);
        max1 = dacMax;
        min1 = dacMin;
        
        maxMin_dac(mid+1,high);
        
        if(max1 > dacMax){
            dacMax = max1;
        }
        if(min1 < dacMin){
            dacMin = min1;
        }
    }    
    
}

int main (){
    int min , max;
    
    int c1 = maxMin1(&max,&min);
    printf("For maxMin1() function::\nmax: %d \t min: %d \t comparisions : %d \n",max,min,c1);
    
    int c2 = maxMin2(&max,&min);
    printf("For maxMin2() function::\nmax: %d \t min: %d \t comparisions : %d \n",max,min,c2);
    
    
    maxMin_dac(0,size-1);
    
    
    
    printf("For maxMin_dac() function ::\nmax: %d \t min: %d \n",dacMax,dacMin);
    return 0;
}
