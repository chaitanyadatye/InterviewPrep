#include <stdio.h>
#include <stdlib.h>

int * insertion_sort(int *arr, int n) {
	int i;
	int j;
	int key;
	
	for(j=1; j<n; j++) {
		key = arr[j];
		i = j-1;
		while(i>=0 && arr[i] > key) {
			arr[i+1] = arr[i];
			i = i - 1;
		}
		arr[i+1] = key;
	}
	return arr;
}

int main() {

	int *arr;
	int n;
	int i=0;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	printf("\nEnter the array: ");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	arr = insertion_sort(arr, n);
	
	printf("\nThe sorted array is: ");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);

	return 0;
} 

