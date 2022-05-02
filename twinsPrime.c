#include <stdio.h>
int main(){
    int n , prm1 , prm2;
    printf("Enter higher limit to check twin primes number : ");
    scanf("%d",&n);
    for(int i =3 ; i <= n-2 ; i++){
        prm1 = 0;
        prm2 = 0;
        for(int j = 2 ; j <= i/2 ; j++){
            if(i%j == 0){
                prm1 = 1;
                break;
            }else {
                for(int k = 2 ; k <= (i+2)/2 ; k++){
                    if((i+2)%k ==0){
                        prm2 = 1;
                        break;
                    }
                }
            }
        }
        if(prm1 == 0 && prm2 == 0){
            printf("Twins prime numbers are : %d & %d \n",i,i+2);
        }
    }
}