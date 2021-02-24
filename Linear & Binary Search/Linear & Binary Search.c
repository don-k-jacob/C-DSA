#include <stdio.h>

#define MAX 100

int linearSearch(int [], int, int);
int binarySearch(int [], int, int);

int main(){
    int a[MAX], key, terms, index, choice;

    printf("\nEnter Number of Elements in Array : ");
    scanf("%d", &terms);

    printf("\nEnter %d Elements : ", terms);
    for (int i=0; i<terms; i++)
        scanf("%d", &a[i]);

    printf("\nEnter a Number to Search : ");
    scanf("%d", &key);

    printf("\nChoose Search Method : \n");
    printf("\n1. Linear Search");
    printf("\n2. Binary Search\n");
    scanf("%d",&choice);
    switch(choice){
        case 1 : index=linearSearch(a, terms, key);
                 break;
        case 2 : index=binarySearch(a, terms, key);
                 break;
        default: printf("\n\n!!!WRONG INPUT!!!\n\n");
    }
    
    if(index!=-1)
        printf("\n%d found at index position %d .", key, index);
    else
        printf("Element %d not found.",key);
}

int linearSearch(int a[], int t, int k){
    int i, pos=-1;
    for (i=0; i<t; i++){
        if (a[i]==k){
            pos=i;
            break;
        }
    }
    return pos;
}

int binarySearch(int a[],int t, int k){
    int pos=-1, f, l, i;
    f=0;
    l=t-1;
    while(f<=l){
        i=(f+l)/2;
        if(k==a[i]){
            pos=i;
            break;
        }
        else if(k<a[i])
            l=i-1;
        else
            f=i+1;
    }
    return pos;
}