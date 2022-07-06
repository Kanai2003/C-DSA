#include<stdio.h>

int main(){
    int size;
    printf("Enter size of array : \n");
    scanf("%d",&size);
    int arr[size];
    for(int i =0; i<size;i++){
        printf("Enter value of Array[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    int flag1=0,flag2=0;
    int low =0;
    int high = size -1;
    for (int  i = 0; i < size ; i++)
    {
        if (arr[i]>=arr[i+1])
        {
            flag1++;
        }else if (arr[i]<=arr[i+1]){
            flag2++;
        }
        
    }
    if(flag1 == size){
        printf("Descending Array \nSuitable for Binary Search \n");
        int target ;
        printf("Enter a number to search : \n");
        scanf("%d",&target);


        //Binary search
        while (low<=high){
            int mid  = (low + high)/2;
            if(arr[mid] == target){
                printf("Found at index %d\n",mid);
                break;
            }else{
                if(arr[mid]>target){
                    high = mid-1;
                }else{
                    low = mid + 1;
                }

            }
        }
    }else if(flag2 == size){
        printf("Assending Array \nSuitable for Binary search \n");
        int target ;
        printf("Enter a number to search : \n");
        scanf("%d",&target);


        //Binary Search
        while (low<=high){
            int mid  = (low + high)/2;
            if(arr[mid] == target){
                printf("Found at index %d\n",mid);
                break;
            }else{
                if(arr[mid]>target){
                    high = mid-1;
                }else{
                    low = mid + 1;
                }

            }
        } 
    }else{
        printf("Not Suitable for Binary Search \n");
        for(int i =0; i < size ; i++){
            int flagB =0;

            //Bouble sort
            for(int j=0; j<size;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    flagB=1;
                }
                if(flagB==0){
                    break;
                }
            }
        }
        printf("Now the array is in Descending order and suitable for Binary Search \n");
        int target ;
        printf("Enter a number to search : \n");
        scanf("%d",&target);

        //Binary Search
        while (low<=high){
            int mid  = (low + high)/2;
            if(arr[mid] == target){
                printf("Found at index %d\n",mid);
                break;
            }else{
                if(arr[mid]>target){
                    high = mid-1;
                }else{
                    low = mid + 1;
                }

            }
        }
    }
    
    return 0 ;
}