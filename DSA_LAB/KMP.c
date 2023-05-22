#include <stdio.h>
#include <string.h>

void computeLPS(char* pattern, int m, int* lps) {
	int len = 0, i = 1;
	lps[0] = 0;

	while (i < m) {
    	if (pattern[i] == pattern[len]) {
        	len++;
        	lps[i] = len;
        	i++;
    	}
    	else {
        	if (len != 0) {
            	len = lps[len-1];
        	}
        	else {
            	lps[i] = 0;
            	i++;
        	}
    	}
	}
}

void KMP(char* str, char* pattern) {
	int n = strlen(str);
	int m = strlen(pattern);
	int lps[m];
	int i = 0, j = 0, count = 0;

	computeLPS(pattern, m, lps);

	while (i < n) {
    	count++;
    	if (pattern[j] == str[i]) {
        	j++;
        	i++;
    	}
    	if (j == m) {
        	printf("Pattern found at index %d\n", i-j);
        	printf("Number of comparisons incurred: %d\n", count);
        	j = lps[j-1];
    	}
    	else if (i < n && pattern[j] != str[i]) {
        	if (j != 0) {
            	j = lps[j-1];
        	}
        	else {
            	i++;
        	}
    	}
	}
	if (j == m) {
    	printf("Pattern found at index %d\n", i-j);
	}
	else {
    	printf("Pattern not found\n");
	}
}

void printLPS(char* pattern, int m) {
	int lps[m];
	computeLPS(pattern, m, lps);
	printf("LPS array: ");
	for (int i = 0; i < m; i++) {
    	printf("%d ", lps[i]);
	}
	printf("\n");
}

void multipleMatches(char* str, char* pattern) {
	int n = strlen(str);
	int m = strlen(pattern);
	int lps[m];
	int i = 0, j = 0, count = 0, found = 0;

	computeLPS(pattern, m, lps);

	while (i < n) {
    	count++;
    	if (pattern[j] == str[i]) {
        	j++;
        	i++;
    	}
    	if (j == m) {
        	printf("Pattern found at index %d\n", i-j);
        	found = 1;
        	j = lps[j-1];
    	}
    	else if (i < n && pattern[j] != str[i]) {
        	if (j != 0) {
            	j = lps[j-1];
        	}
        	else {
            	i++;
        	}
    	}
	}
	if (!found) {
    	printf("Pattern not found\n");
	}
}

int main() {
	char str[100], pattern[100];
	printf("Enter a string: ");
	scanf("%[^\n]%*c", str);
	printf("Enter a pattern: ");
	scanf("%[^\n]%*c", pattern);
	printf("\nKMP algorithm:\n");
	KMP(str, pattern);
	printf("\nLPS array:\n");
	printLPS(pattern, strlen(pattern));
	printf("\nMultiple matches:\n");
	multipleMatches(str, pattern);
	return 0;
}

