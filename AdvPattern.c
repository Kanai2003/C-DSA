#include <stdio.h>



int main() {
    int n ;
    printf("Enter a number to print this pattern : ");
    scanf("%d",&n);
    //upper half
    for(int i = 0; i<n ; i++){
        //upper left
        for(int j =n; j>n-i;j--){
            printf("%d ",j);
        }
        for(int j = n-i; j>0 ; j--){
            printf("%d ",n-i);
        }
        
        //upper right
        for(int j = 0; j<n-i-1; j++){
            printf("%d ",n-i);
        }
        for(int j =n-i+1; j<=n;j++){
            printf("%d ",j);
        }
        // next line
        printf("\n");
    }
    
    //lower half
    for(int i = n-2 ; i>=0;i--){
        //lower left
        for(int j =n; j>n-i;j--){
            printf("%d ",j);
        }
        for(int j = n-i; j>0 ; j--){
            printf("%d ",n-i);
        }
        
        //lower right
        for(int j = 0; j<n-i-1; j++){
            printf("%d ",n-i);
        }
        for(int j =n-i+1; j<=n;j++){
            printf("%d ",j);
        }
        // next line
        printf("\n");
    }
    

    return 0;
}



//another way , using while loop 
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// int main() 
// {

//     int n;
//     scanf("%d", &n);
//     // Complete the code to print the pattern.
//     int i = n;
//     while(i > 1) {
//         int j = n;
//         int k = n;
//         while (j > 1) {
//             printf("%d ", k);
//             if (j > i) {
//                 k--;
//             }
//             j--;
//         }
//         while (j <= n) {
//             if (j > i) {
//                 k++;
//             }
//             printf("%d ", k);
//             j++;
//         }
//         printf("\n");
//         i--;
//     } 
    
//     while(i <= n) {
//         int j = n;
//         int k = n;
//         while (j > 1) {
//             printf("%d ", k);
//             if (j > i) {
//                 k--;
//             }
//             j--;
//         }
//         while (j <= n) {
//             if (j > i) {
//                 k++;
//             }
//             printf("%d ", k);
//             j++;
//         }
//         printf("\n");
//         i++;
//     } 
//     return 0;
// }