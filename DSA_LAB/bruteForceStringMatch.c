#include <stdio.h>
#include <string.h>

void bruteforce(char* str, char* pattern) {
	int n = strlen(str);
	int m = strlen(pattern);
	int i, j, count = 0;

	for (i = 0; i <= n - m; i++) {
    	for (j = 0; j < m; j++) {
        	count++;
        	if (str[i+j] != pattern[j])
            	break;
    	}
    	if (j == m) {
        	printf("Pattern found at index %d\n", i);
        	printf("Number of comparisons incurred: %d\n", count);
        	return;
    	}
	}
	printf("Pattern not found\n");
}

int main() {
	char str[100], pattern[100];
	printf("Enter a string: ");
	scanf("%[^\n]%*c", str);
	printf("Enter a pattern: ");
	scanf("%[^\n]%*c", pattern);
	bruteforce(str, pattern);
	return 0;
}

