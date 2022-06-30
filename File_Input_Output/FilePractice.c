#include<stdio.h>
int main(){
    FILE *fptr;
    fptr = fopen("FilePractice.txt","a");
    for(int i = 0 ; i < 2; i++){
        char name[20];
        int salery;
        printf("Enter name: ");
        scanf("%s",name);
        printf("Enter salery: ");
        scanf("%d",&salery);
        fprintf(fptr,"%s , ",name);
        fprintf(fptr,"%d\n",salery);
    }
    printf("\n The file has been generated , you can check now ");

   

    fclose(fptr);
    return 0;

}