// for open and read("r") the "file.txt" file have to exist , and for write("w") if exist then it will overwrite
// "r" is order for read , "rb"->read in binary , "w"->write , "wb"->write in binary , "a"->append
           

#include<stdio.h>
int main(){
    FILE *fptr;

    //write a file --------------------------------
    int num = 130;
    fptr = fopen("file.txt","w");       //at first we need to open the file
    fprintf(fptr,"The number is %d and that's all for me ",num);    //fprintf(); will write something on that perticular file
    fprintf(fptr, "\nThanks for visiting this file "); 
    putc('T',fptr);       //we can use fputc() and putc() functions to write
    fputc('U',fptr);
    fclose(fptr);       //after writting or reading the file we need to close the file        



    // //Read the file's characters ----------------------------------
    // fptr = fopen("file.txt","r");
    // printf("The value if the file is : %c\n",fgetc(fptr));      //fgetc() will read the file's characters
    // printf("The value if the file is : %c\n",fgetc(fptr));
    // printf("The value if the file is : %c\n",fgetc(fptr));
    // printf("The value if the file is : %c\n",fgetc(fptr));
    // printf("The value if the file is : %c\n",fgetc(fptr));
    // char ch;
    // fscanf(fptr,"%c",&ch);      //We can also use fscanf() ro read the file  
    // printf("character = %c \n",ch);   //WE can also read integer as well as character
    // fclose(fptr);



    // // To read the whole file -------------------------------
    fptr = fopen("file.txt","r");
    char c = fgetc(fptr);
    while(c != EOF){           //"EOF" is constant that means the End Of File
        printf("%c",c);
        c = fgetc(fptr);
    }
    fclose(fptr);



    return 0;
}