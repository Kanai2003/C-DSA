// #include <stdio.h>
// struct student{
//     char name[20];
//     int uroll;
//     float cgpa;
// };

// int main(){
//     struct student kanai;
//     struct student classX[10];       //we can make this type of array
//     printf("Enter name \n");
//     scanf("%[^\n]s",kanai.name);
//     printf("Enter uroll \n");
//     scanf("%d",&kanai.uroll);
//     printf("Enter cgpa \n");
//     scanf("%f",&kanai.cgpa);
//     printf("%s  %d  %.2f\n",kanai.name,kanai.uroll,kanai.cgpa);
//     return 0;
// }




// #include<stdio.h>
// struct student{
//     int roll;
//     float cgpa;
// };

// void main(){
//     typedef struct student tint;
//     tint x[3];
//     for (int i = 0; i < 3; i++){
//         printf("\nEnter roll : ");
//         scanf("%d",&x[i].roll);
//         printf("\nEnter cgpa : ");
//         scanf("%f",&x[i].cgpa);
//     }
    
//     for (int  i = 0; i < 3; i++){
//         for (int  j = 0; i < 3-i-1; j++){
//             if(x[j].cgpa <x[j+1].cgpa){
//                 int temp = x[j].cgpa;
//                 x[j].cgpa = x[j+1].cgpa;
//                 x[j+1].cgpa = temp;

//                 temp = x[j].roll;
//                 x[j].roll = x[j+1].roll;
//                 x[j+1].roll = temp;
//             }
//         } 
//     }
//     for (int  i = 0; i < 3; i++){
//         printf("\n %d  %.2f",x[i].roll,x[i].cgpa);
//     }    
// }



#include <stdio.h>
struct bank{
    char name[20];
    long ACNum;
    long balance;
};


int main(){
    typedef struct bank pnb ;
    pnb x[2];
    for(int  i = 0; i < 2; i++){
        printf("Enter name : ");
        gets(x[i].name);
        if(i > 0){
            gets(x[i].name);
        }
        printf("\nEnter a/c number : ");
        scanf("%ld",&x[i].ACNum);
        printf("\nEnter a/c balance : ");
        scanf("%ld",&x[i].balance);
    }

    long n;
    printf("Enter a/c number to view details: ");
    scanf("%ld",&n);
    for(int i = 0; i< 2; i++){
        if(x[i].ACNum == n){
            printf("Name : %s\n",x[i].name);
            printf("A/C Number : %ld\n",x[i].ACNum);
            printf("Balance : %ld\n",x[i].balance);
        }
    }
    return 0;
}




