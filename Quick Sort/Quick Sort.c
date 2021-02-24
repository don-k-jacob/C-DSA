#include <stdio.h>

#define MAX 20

int a[MAX]; 

int partition(int left, int right){
    int temp;
    int pivot = a[left];
    int i = left;
    int j = right + 1;
    while (i < j){
        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[left];
    a[left] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int left, int right){
    if (left < right){
        int p = partition(left, right);
        quickSort(left, p - 1);
        quickSort(p + 1, right);
    }
}

int main(){
    int n;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = 1000;
    quickSort(0, n - 1);
    printf("\nSorted Array : ");
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
}