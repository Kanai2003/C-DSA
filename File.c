#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fptr;
    fptr = fopen("test.txt","r");     // for open the file  "test.txt" is file name & have to exist
                                        // "r" is order for read , "rb"->read in binary , "w"->write , "wb"->write in binary , "a"->append
    fclose(fptr);       

    char ch;
    fscanf(fptr,"%c",&ch);
    printf("character = %c \n",ch);
    fclose(fptr);

    fprintf(fptr,"%c",ch);

    fgetc(fptr);        // to get a character
    while(ch != EOF){       //"EOF" -> End Of File
        printf("%c",ch);
        ch = fget(fptr);
    }
    fputc('a',fptr);        // to put a character in a file

    return 0;
}

