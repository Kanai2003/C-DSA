#include<stdio.h>
int main(){
    // printf("Enter two value for definesize of 2D array : ");
    // int row,col;
    // scanf("%d %d", &row,&col);
    int values[3][3],i,j;
    printf("Now Enter value of array : ");
    for(i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++){
            scanf("%d",&values[i][j]);
        } 
    }
    printf("Now your Array is : \n");
    for(int k= 0; k<3; k++) {
        for (int l = 0; l < 3; l++){
            printf(" %d ",values[k][l]);
        }
        printf("\n");
    }

    
}