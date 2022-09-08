#include <stdio.h>
void margeSort(int a[] , int n ){
    int i,j,k,l1,l2,u1,u2,s=1;
    int aux[n];
    while(s<n){      //pass
        l1=0;               //lower bound of 1st sub array
        k=0;
        while(l1+s<n){      //pair wise marge
            l2=l1+s;        //lower bound of 2nd sub array
            u1=l2-1;        //upper bound of 1st sub array
            u2=(l2+s-1<n)?(l2+s-1):(n-1);   //upper bound of 2nd sub array
            for(i =l1,j=l2; i<=u1&&j<=u2; k++){
                if(a[i]<a[j]){
                    aux[k] = a[i++];
                }else{
                    aux[k]=a[j++];
                }
            }
            //copy remaining part of sub arrays 
            for(;i<=u1;k++){
                aux[k]=a[i++];
            }
            for(;j<=u2;k++){
                aux[k]=a[j++];
            }
            l1=u2+1;
        }
        //copy unpaired sub array
        for(i=l1; i<n; i++){
            aux[k++]=a[i];
        }
        //copy 'aux" to 'a'
        for(i=0; i<n; i++){
            a[i]=aux[i];
        }
        s*=2;

    }
}

int main (){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter Array Elements : ");
    for(int i =0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    margeSort(arr,size);
    for(int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
}