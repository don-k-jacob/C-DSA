#include <stdio.h>

#define MAX 20

int a[MAX], n;

void merge(int l, int mid, int r){
	int i, j, L[MAX], R[MAX];
	int n1 = mid - l + 1;
	int n2 = r - mid;
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[mid + j + 1];
	L[n1] = 1000;
	R[n2] = 1000;
	i = j = 0;
	for (int k = l; k <= r; k++){
		if (L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int l, int r){
	if (l < r){
		int mid = (l + r) / 2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}
}

int main(){
	printf("\nEnter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\nEnter the array elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = 0, r = n - 1;
	mergeSort(l, r);
	printf("\nSorted Array : ");
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
}