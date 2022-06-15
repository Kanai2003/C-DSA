#include<stdio.h>
// int main()
// { 
//     int n;
//     printf("Enter the array length ");
//     scanf("%d",&n);
//     int a[n], c1 =0,c2 =0,en=0;
//     printf("Enter the array elements : ");
    
//     //scanning array element
//     for(int i=0;i<n;i++)
//     { 
//         scanf("%d",&a[i]);
//     }
    
//     //checking
//     for(int i=0;i<n-1;i++)
//     {   if(a[i]<a[i+1])
//         c1++;
//                 if(c1>c2)
//                 {c2 =c1; en =i+1;}
//                 if(a[i]>=a[i+1])
//                     c1 =0;
//     }
    
//     printf("The elements of the maximum subarray are : ");
//     for(int k=en-c2;k<=en;k++)
//     { 
//         printf(" %d ",a[k]);
//     }

//     return 0;
// }

