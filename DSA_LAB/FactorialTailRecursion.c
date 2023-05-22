#include <stdio.h>
int fact(int a, int c){
	if(c == 1){
		return a;
	}
	return fact(a*c,c-1);
}
int main(){
	int num;
	printf("Enter a number : ");
	scanf("%d",&num);
	
	printf("\nFactorial Value : %d",fact(1,num));
	return 0;
}
