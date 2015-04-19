#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char phone[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void printWords(int * number, int cur_pos, char *output, int n) {
	
	int i;
	if(cur_pos == n) {
		printf("%s\n", output);
		return;
	}

	for(i = 0; i<strlen(phone[number[cur_pos]]); i++) {
		output[cur_pos] = phone[number[cur_pos]][i];
		printWords(number, cur_pos+1, output, n);
		if(number[cur_pos] == 0 || number[cur_pos] == 1)
			return;
	}
}

int main() {
	
	int * number;
	int n;

	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	number = (int *)malloc(n*sizeof(int));

	for(int i=0; i<n; i++)
		scanf("%d", &number[i]);
	
	char *output;
	output = (char *)malloc((n+1)*sizeof(char));
	output[n] = '\0';
	printWords(number, 0, output, n);
	
	return 0;
}
