#include <stdio.h>
#include <string.h>     //for C language there is not any string , we use character array for string concept
int main(){
    
    char str[] = {'M','y',' ','N','a','m','e',' ','i','s','K','a','n','a','i','\0'}; //'\0' is remark for end of this string
    printf("%s\n",str);

    char str1[] = "My Name is Kanai";  // "\0" is not necessary for it
    printf("%s\n", str1);              // we can change pointer arrray but we cant change any notmal character array

    char *str2 = "My Name is Kanai"; // this is called as pointer array

    printf("%s",str2);
    return 0;
}
