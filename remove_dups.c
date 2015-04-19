#include<stdio.h>
#include<stdlib.h>

int * remove_dups(int *arr, int n) {
	int i=0;
	int j=1;
	
	while(j<n){
		if(arr[i] != arr[j]) {
			i++;
			arr[i] = arr[j];
		}
		j++;
	}
	i++;
	while(i<n) {
		arr[i] = 0;
		i++;
	}
	return arr;
}

int main() {

	int *arr;
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	
	arr = (int *) malloc(n*sizeof(int));	
	printf("\nEnter Array: ");
	
	for(int k=0; k<n; k++)
		scanf("%d", &arr[k]);
	
	arr = remove_dups(arr,n);
	
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);

	return 0;
} 
