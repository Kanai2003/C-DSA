// #include <stdio.h>

// struct student{
//     char name[20];
//     int uroll;
//     float cgpa;
// };



// int main(){


//     struct student kanai;
//     printf("Enter name \n");
//     scanf("%[^\n]s %d %f",kanai.name);
//     printf("Enter uroll \n");
//     scanf("%d",&kanai.uroll);
//     printf("Enter cgpa \n");
//     scanf("%f",&kanai.cgpa);
    
//     printf("%s  %d  %.2f\n",kanai.name,kanai.uroll,kanai.cgpa);
//     return 0;
// }




#include<stdio.h>
struct student{
    int roll;
    float cgpa;
};

void main(){
    typedef struct student tint;
    tint x[3];
    for (int i = 0; i < 3; i++){
        printf("\nEnter roll : ");
        scanf("%d",&x[i].roll);
        printf("\nEnter cgpa : ");
        scanf("%f",&x[i].cgpa);
    }
    
    for (int  i = 0; i < 3; i++){
        for (int  j = 0; i < 3-i-1; j++){
            if(x[j].cgpa <x[j+1].cgpa){
                int temp = x[j].cgpa;
                x[j].cgpa = x[j+1].cgpa;
                x[j+1].cgpa = temp;

                temp = x[j].roll;
                x[j].roll = x[j+1].roll;
                x[j+1].roll = temp;
            }
        } 
    }
    for (int  i = 0; i < 3; i++){
        printf("\n %d  %.2f",x[i].roll,x[i].cgpa);
    }
    
    
}