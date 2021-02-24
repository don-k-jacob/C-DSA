#include<stdio.h>
#include<stdlib.h>
#define maxsize 25;

void Insertion(int[],int);
void Search(int[],int);
void Display(int[],int );

int main()
{
    int size,op,i,n;
    printf("------HASHING-------");
    printf("\n Enter the size of the hash table:");
    scanf("%d",&size);
    int A[size];
    for(i=0;i<size;i++)
        A[i]=-9999;
    do
    {
        printf("Available Operations:");
        printf("\n1.INSERTION\t2.SEARCH\t3.DISPLAY\t4.EXIT");
        printf("\nChoose Operation:");
        scanf("%d",&op);
        switch (op)
        {
            case 1: 
            {
                printf("\nEnter number of elements to be inserted in hash table:");
                scanf("%d",&n);
                if(n>size)
                    printf("\nEntered value greater than size of hash table");
                else
                {
                    for(i=0;i<n;i++)
                    Insertion(A,size);
                    break;
                }
            }
            case 2: Search(A,size);
                    break;
            case 3: Display(A,size);
                    break;
            case 4: 
            {
                    printf("SUCCESSFULLY EXITED");
                    exit(0);
            }
            default:printf("Enter correct choice:");
                    break;
        }
    } while (1);
    
    

}

void Insertion(int A[],int array_size)
{
    int value, key,flag,k; 

    printf("Enter the element to insert : ");
    scanf("%d",&key);
    value = key % array_size;
    flag = value;
    for(k=0;k<array_size;k++)
    {
        if(A[flag]==-9999)
        {
            A[flag]=key;
            break;
        }
        flag++;
        if(flag == array_size)
        {
            flag=0;
        }
    }
    if(k==array_size)
        printf("\nElement cannot be Inserted\n");
}
void Search(int A[],int arr_size)
{
    int search_ele, loc=0;
    printf("\nEnter the element to be searched:");
    scanf("%d",&search_ele);

    int k;

    for( k=0; k<arr_size;k++)
    {
        if(A[k] == search_ele)
        {
            loc++;
            break;
        }
    }

    if(loc==1)
    {
        printf("\nThe element %d is found at index position %d ",A[k],k);
    }
    else
    {
        printf("Element is not present in the array!\n");
    }
    
}

void Display(int A[],int size)
{
    printf("Elements in the hash table are:\n");
    for(int i=0; i<size; i++)
    {
        if(A[i]==-9999)
            printf("Element at index value %d = Empty\n",i);
        else
            printf("Element at index value %d = %d\n",i,A[i]);
    }
}