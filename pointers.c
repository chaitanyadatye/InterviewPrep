#include <stdio.h>
#include <stdlib.h>

void init(int *p) {
	*p = 5;
	printf("IN FUNC %d\n", *p);
	return;
}

int main() {
	
	int *p;
	
	p = (int *) malloc(sizeof(int));
	*p=100;
	init(p);
	printf("IN MAIN %d\n", *p);

	return 0;
}
