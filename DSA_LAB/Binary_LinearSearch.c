#include<stdio.h>

//taking global array and its size
int arr[] = {-100,-89,-56, -5, 0,6,10 ,75, 99};
int size = sizeof(arr)/sizeof(arr[0]);

//function for linear search
int LinearSearch(int target){
	int count = 0;
	for(int i =0; i< size;i++){
		count++;
		if(arr[i] == target){
			return count ;
		}
	}
	return count;

}

//function for binary search
int BinarySearch(int target){
	int low = 0;
	int high = size-1;
	int count = 0;
	while(low <= high){
		int mid = low + (high-low)/2;
		count++;
		if(arr[mid] == target){
			return count;
		}else{
			count++;
			if(arr[mid] < target){
				low = mid+1;
			}else{
				high = mid -1;
			}
		}
		
	}
	return count;
}

int main(){
	int first = -100;		
	int last = 99;	
	int mid = 0;	
	int notInArr = 7;		
	
	//comparing for first element
	printf("For First Element : \n ");
	int l = LinearSearch(first);
	int b = BinarySearch(first);
	if(l<b){
		printf("Linear Search is Better  \n");
	}else{
		printf("Binary Search is better  \n");
	}
	
	//comparing for middle element
	printf("\nFor Middle Element : \n");
	l = LinearSearch(mid);
	b = BinarySearch(mid);
	if(l<b){
		printf("Linear Search is Better  \n");
	}else{
		printf("Binary Search is better  \n");
	}
	
	//comparing for last element
	printf("\nFor Last Element : \n");
	l = LinearSearch(last);
	b = BinarySearch(last);
	if(l<b){
		printf("Linear Search is Better  \n");
	}else{
		printf("Binary Search is better  \n");
	}
	
	//comparing for non existing element
	printf("\nFor non existing Element : \n ");
	l = LinearSearch(notInArr);
	b = BinarySearch(notInArr);
	if(l<b){
		printf("Linear Search is Better  \n");  
	}else{
		printf("Binary Search is better  \n");
	}
	return 0;
}

