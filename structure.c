#include <stdio.h>

struct student{
    char name[20];
    int uroll;
    float cgpa;
};



int main(){


    struct student kanai;
    printf("Enter name \n");
    scanf("%[^\n]s %d %f",kanai.name);
    printf("Enter uroll \n");
    scanf("%d",&kanai.uroll);
    printf("Enter cgpa \n");
    scanf("%f",&kanai.cgpa);
    
    printf("%s  %d  %.2f\n",kanai.name,kanai.uroll,kanai.cgpa);
    return 0;
}