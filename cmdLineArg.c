#include<stdio.h>
int main(int argc, char *argv[],char *envp[]){      //argc -> argument count
    printf("%d\n",argc);
    for(int i =0; i<argc;i++){
        printf("arg[%d] = %s \n",i,argv[i]);        //argv -> argument value
    }
    int i =0;
    while(envp[i] != NULL){
        printf("%s   ",envp[i]);            //envp -> environment veriable
        i++;
    }
    return 0;
}