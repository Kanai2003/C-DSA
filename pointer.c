# include<stdio.h>
int main()
{
    int age = 18;
    int *ptr = &age;               //"*" is dinoting value of "ptr" and '&' is denoting address of "age"  
    printf("Address of age is : %u \n",ptr);
    printf("Value of age is : %d\n", age);
    printf("Value of age is : %d\n", *ptr);
    printf("%u",*(&ptr));
    

    return 0;
}
