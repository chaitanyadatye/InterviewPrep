#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * replace(char *str) {
	
	int k = 0;
	int i = 0;
	
	while(i<strlen(str)) {
		
		if(str[i] == 'b') 
			i++;
		else if(str[i] == 'a' && str[i+1] == 'c' && i+1 < strlen(str))
			i+=2;
		else {
			if(str[i] == 'c' && str[k-1] == 'a' && k>0) {
				i++;
				k--;
			} else {
				str[k] = str[i];
				k++;
				i++;
			}
		}
	
	}
	
	str[k] = '\0';
	return str;
}
			
int main() {
	
	printf("Enter string: ");
	char *str;
	
	scanf("%s", str);
	
	str = replace(str);

	printf("\n STR IS REPLACED : %s",str);
	
	return 0;
}

