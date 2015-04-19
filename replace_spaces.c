#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * replace_spaces(char *str) {
	char *str1;
	int count = 0;
	int i;
	while(str[i] != '\0') {
		if(str[i] == ' ')	
			count ++;
		i++;
	}
	
	str1 = (char *) malloc((strlen(str) + count*2)*sizeof(char));
	
	i = 0;
	int j = 0;
	
	while(i < strlen(str)) {
		if(str[i] == ' '){
			str1[j] = '%';
			str1[j+1] = '2';
			str1[j+2] = '0';
			j = j+3;
		}
		else {
			str1[j] = str[i];
			j = j + 1;
		}
		i ++;
	}
	return str1;
}

int main() {
	char *str;
	printf("Enter String: ");
	scanf("%[^\n]s", str);
	
	str = replace_spaces(str);

	printf("\nModified String is: %s", str);
	
	return 0;
}
