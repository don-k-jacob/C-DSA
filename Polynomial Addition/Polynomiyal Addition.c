#include<stdio.h>

#define MAX 30

int * readPolynomial(int [],int );
void addPolynomial(int [],int [],int ,int );
void printPolynomial(int [],int );

int main(){
    int pol1[MAX],pol2[MAX];
    int * p1,* p2;
    int t1,t2;
    int a[10], b[10], c[10];

    printf("\nEnter the no. of terms of the polynomial 1 : ");
    scanf("%d", &t1);
    printf("\nEnter the degrees and coefficients : ");
    p1=readPolynomial(pol1,t1);
    printf("\nFirst polynomial is : ");
    printPolynomial(pol1,t1);

    printf("\n\nEnter the no. of terms of the polynomial 2 : ");
    scanf("%d", &t2);
    printf("\nEnter the degrees and coefficients : ");
    p2=readPolynomial(pol2,t2);
    printf("\nSecond polynomial is : ");
    printPolynomial(pol2,t2);

    addPolynomial(p1, p2, t1, t2);
    
    return 0;
}

int * readPolynomial(int p[],int t){
    for (int i=0; i<2*t; i++)
        scanf("%d", &p[i]);
    return p;
}

void printPolynomial(int p[], int t){
    int pos=0;   
    if(p[pos+1]==1)
        printf("x^%d", p[pos]);
    else
        printf("%dx^%d", p[pos+1],p[pos]);
    pos+=2;
    while (pos<2*t){
        printf("+%dx^%d", p[pos+1],p[pos]);
        pos+=2;
    }
}

void addPolynomial(int p1[], int p2[], int t1, int t2){
    int i=0, j=0, k=0, t3;
    int p3[MAX];
    while (t1>0 && t2>0){
        if (p1[i]==p1[j]){
            p3[k+1]=p1[i+1]+p2[j+1];
            p3[k]=p1[i];
            t1--;
            t2--;
            i+=2;
            j+=2;
        }
        else if (p1[i]>p2[j]){
            p3[k+1]=p1[i+1];
            p3[k]=p1[i];
            t1--;
            i+=2;
        }
        else{
            p3[k+1]=p2[j+1];
            p3[k]=p2[j];
            t2--;
            j+=2;
        }
        k+=2;
    }

    while (t1>0){
        p3[k+1]=p1[i+1];
        p3[k]=p1[i];
        k+=2;
        i+=2;
        t1--;
    }

    while (t2>0){
        p3[k+1]=p2[j+1];
        p3[k]=p2[j];
        k+=2;
        j+=2;
        t2--;
    }
    
    t3=k/2;    
    printf("\n\nSum of the two polynomials is : ");
    printPolynomial(p3,t3);
}
