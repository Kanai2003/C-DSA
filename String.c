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
    // puts(s1);       // we can use puts() as well as printf() function



    //Functions in C --------------------------------------

    char *s1 = "Kanai";
    char *s2="lal";

    int n =strlen(s1);     //  calculate length of a string

    strcat(s1,s2);           //Is used to concatenate or join two strings

    //strcpy(s1,s2);          //Can copy the content of a string to another

    int i=strcmp(s1, "Kanailal");      //Can compare two strings
    int j=strcmp(s1, s2);
    
    printf("%d%d%d",i,j);

    printf("%s",strrev(s1));     //Is used to reverse the string

    printf("%d",strlwr(s1));    //Can convert the string to lowercase

    printf("%d",strupr(s1));    //Can convert the string to uppercase




    // verious output process --------------------------------
    char str[] = "Introduction to C ";
    // clrscr();
    printf("\n |%s|",str);
    printf("\n |%20s|",str);
    printf("\n |%-20s|",str);
    printf("\n |%.4s|",str);+-


    printf("\n |%20.4s|",str);
    printf("\n |%-20.4s|",str);

    

    
    return 0;
}
