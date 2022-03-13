#include <stdio.h>
int main(){
    
    //dataTypes---------------------------------------------------
    // printf("Enter a Integer value\n");      //"\n" --> is for new line
    // int x,y,z;                              //"\t"--> is for tab in line
    // scanf("%d",&x);                         //"%d"--> is for dinote integer value
    // scanf("%d",&y);                         //"%c"--> is for dinote character 
    // z = x+y;
    // printf("%d",z);
    // char c;             
    // double d;
    // printf("Enter a character :\n");
    // scanf("%c\n",&c);
    // printf("Enter a double value : \n");
    // scanf("%d\n",&d);
    // printf("c is : %c\n","\t",c);
    // printf("d is : %d\n",d);

    /*printf("\t%5d\n",1);             //"%5"--> dinote that the integer value will take only 5 space area. we can take it any number
    printf("\t%5d\n",12);
    printf("\t%5d\n",123);
    printf("\t%5d\n",1234);
    printf("\t%5d\n",12345);*/

    // for ( int a = 1; a<=5;a++){
        
    //     for(int b = 1 ; b<=a;b++){
    //          printf("I Love My Parents\t");
    //     }
    //     printf("\n");
    // }

    // printf("%f\n",1.1212);
    // printf("%d\n",1.11212121212121);



    double a , b, result;
    char x;
    
    printf("Enter a character(+,-,*,/) : ");
    scanf("%c",&x);

    printf("Enter two float value : ");
    scanf("%lf %lf",&a,&b);
    switch (x)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        printf("Enter a valid character\n");
        break;
    }
    printf("%lf\n",result);

    return 0;
}