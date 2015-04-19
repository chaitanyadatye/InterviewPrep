#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *str, int s, int e) {
	
	int j;

	if(s == e) {
		printf("%s\n", str);	
		return;
	}
	
	else {
		for(j=s; j<=e; j++) {
			swap(str+s, str+j);
			permute(str, s+1, e);
			swap(str+s, str+j);
		}
	}
	return;
}

int main() {
	
	char *str;
	printf("Enter string to permute: ");
	scanf("%s", str);
	
	permute(str, 0, strlen(str)-1);
	
	return 0;
}
