#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *begin, char *end) {
	char temp;
	while(begin < end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}
	
void reverse_word(char *str) {
	int length = strlen(str);
	char *str1;

	char *begin;
	char *temp;
	
	begin = str;
	temp = str;

	while(*temp) {
		temp ++;
		if(*temp == '\0'){
			reverse(begin, temp-1);
		} else if (*temp == ' ') {
			reverse(begin, temp-1);
			begin = temp+1;
		}
	}
	
	reverse(str, temp-1);
	return;
}		
	
	
int main() {
	char *str;
	printf("Enter string: ");	
	scanf("%[^\n]s", str);
	printf("\nYou have entered: %s",str);	
	
	reverse_word(str);
	
	printf("\nWords reversed: %s", str);
	return 0;
}
