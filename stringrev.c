#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str;
	printf("Enter String: ");
	scanf("%s", str);
	int len = strlen(str);
	printf("You've entered : %s with length %d\n",str,len);
	char temp;
	int i,j;
	for(i=0, j=len-1; i<=j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("The reversed string is: %s\n",str);  
	return 0;
}
