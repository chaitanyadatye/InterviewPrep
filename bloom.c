#include<stdio.h>
#include<stdlib.h>

int *bloom_filter;

void print() {
	for(int i=0; i<32; i++) {
		printf("%d\t", bloom_filter[i]);
	}
	printf("\n\n");
}

void bloom(int n){
	int sq = n*n;
	int cu = sq*n;
	int prod = sq + cu;
		
	for(int i=1; i<4; i++) {
	bloom_filter[(prod*i) % 32] = 1;
	}
	
return;
}

int main() {
	
	bloom_filter = (int *)malloc(32*sizeof(int));
	for(int i=0; i<32; i++) 
		bloom_filter[i] = 0;
	bloom(2013);
	print();
	bloom(2010);
	print();
	bloom(2007);
	print();
	bloom(2004);
	print();
	bloom(2001);
	print();
	bloom(1998);
	print();

	return 0;
}	
	
