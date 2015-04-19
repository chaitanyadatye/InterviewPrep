#include<stdio.h>
#include<stdlib.h>

void display(int **a, int m, int n) {
	
	int i,j;
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	return;
}

void rotateInPlace(int **src, int m, int n) {
	if(m!=n)
		return;
	
	int i,j;
	int temp;
	
	for(i = 0; i<n/2; i++) {
		for(j=i; j<n-i-1; j++) {
			temp = src[i][j];
			src[i][j] = src[m-j-1][i];
			src[m-j-1][i] = src[m-i-1][m-j-1];
			src[m-i-1][m-j-1] = src[j][m-i-1];
			src[j][m-i-1] = temp;
		}
	}
}
	
int **rotate(int **src, int m, int n) {
	int **dest;
	
	dest = (int **)malloc(n*sizeof(int *));
	
	int i;
	for(i=0; i<n; i++) {
		dest[i] = (int *)malloc(m*sizeof(int));
	}
	
	i=0;
	int j=0;
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			dest[j][m-i-1] = src[i][j];
		}
	}
	
	return dest;
}

int main() {
	
	int **src;
	int m;
	int n;
	
	printf("Enter rows and cols\n");
	scanf("%d %d", &m, &n);
	
	src = (int **)malloc(n*sizeof(int *));
	
	int i;
	for(i=0; i<n; i++) {
		src[i] = (int *)malloc(m*sizeof(int));	
	}
	
	printf("Enter the matrix\n");
	
	int j;
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&src[i][j]);
		}
	}
	
	printf("You entered\n");
	display(src, m, n);
	printf("\n");
	int **dest;
	
	dest = rotate(src, m, n);
	
	printf("On rotating\n");
	display(dest, n, m);

	printf("\n");
	
	printf("On rotating in place\n");
	rotateInPlace(src, n, n);
	display(src, n, n);
		
	return 0;
}
