#include <stdio.h>
#include <conio.h>
#include <string.h>     //for C language there is not any string , we use character array for string concept
int main(){
    
    // char str[] = {'M','y',' ','N','a','m','e',' ','i','s',' ','K','a','n','a','i','\0'}; //'\0' is remark for end of this string
    // printf("%s\n",str);

    // char str1[] = "My Name is Kanai";  // "\0" is not necessary for it
    // printf("%s\n", str1);              // we can change pointer arrray but we cant change any notmal character array

    // char *str2 = "My Name is Kanai"; // this is called as pointer array
    // printf("%s",str2);


    //Functions in C ------------------

    // char *s1 = "Kanai";
    // int n =strlen(s1);     // it will calculate length of a string
    // printf("\nLength of string 1 is %d \n",n);

    // char s2[]="lal";
    // strcat(s1,s2);
    //printf("%s",s2);



    // verious output process --------------------------------
    char str[] = "Introduction to C ";
    clrscr();
    printf("\n |%s|",str);
    printf("\n |%20s|",str);
    printf("\n |%-20s|",str);
    printf("\n |%.4s|",str);
    printf("\n |%20.4s|",str);
    printf("\n |%-20.4s|",str);

    
    return 0;
}
