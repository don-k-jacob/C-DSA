#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node* link;
};

int m = 0, n = 0;

void display(struct node *header){
    struct node* ptr;
    ptr = header;
    while (ptr->link != NULL){
        printf("%dx^%d + ", ptr->coeff, ptr->exp);
        ptr = ptr->link;
    }
    printf("%dx^%d\n\n", ptr->coeff, ptr->exp);
}

struct node* newNode(struct node* head, float coeff, int exp){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->link = NULL;

    if (head == NULL)
        return newnode;

    struct node* ptr = head;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = newnode;
    return head;
}

void removeDuplicate(struct node* header){
    struct node *ptr1, *ptr2, *tmp;
    ptr1 = header;
    while (ptr1 != NULL && ptr1->link != NULL){
        ptr2 = ptr1;
        while (ptr2->link != NULL){
            if (ptr1->exp == ptr2->link->exp){
                ptr1->coeff = ptr1->coeff + ptr2->link->coeff;
                tmp = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(tmp);
            }
            else
                ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
}

struct node* multiply(struct node* pHeader, struct node* qHeader, struct node* rHeader){
    struct node *pptr, *qptr;
    pptr = pHeader;
    qptr = qHeader;
    while (pptr != NULL){
        while (qptr != NULL){
            int c;
            int p;
            c = pptr->coeff * qptr->coeff;
            p = pptr->exp + qptr->exp;
            rHeader = newNode(rHeader, c, p);
            qptr = qptr->link;
        }
        qptr = qHeader;
        pptr = pptr->link;
    }
    removeDuplicate(rHeader);
    return rHeader;
}   

void sort(struct node* header){
    int swapped;
    struct node *ptr1;
    struct node *ptr2 = NULL;
    if (header == NULL)
        return;
    do{
        swapped = 0;
        ptr1 = header;
        while (ptr1->link != ptr2)
        {
            if (ptr1->exp < ptr1->link->exp)
            {
                int temp = ptr1->exp;
                ptr1->exp = ptr1->link->exp;
                ptr1->link->exp = temp;

                int tp = ptr1->coeff;
                ptr1->coeff = ptr1->link->coeff;
                ptr1->link->coeff = tp;

                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        ptr2 = ptr1;
    }
    while (swapped);
}

int main(){
    struct node *pHeader = NULL, *qHeader = NULL, *rHeader = NULL;
    int coef;
    int exp;
    printf("Enter Terms in First Polynomial : "); 
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        printf("Enter the Coefficient of %d term : ",(i+1));
        scanf("%d", &coef);
        printf("Enter the exponent of %d term : ",(i+1));
        scanf("%d", &exp);
        pHeader = newNode(pHeader, coef, exp);
    }
    printf("\n\nEnter the number of terms in Second Polynomial : "); 
    scanf("%d", &n);
    if(m==0 && n==0){
        printf("!!!MULTIPLICATION NOT POSSIBLE!!!\n\n");
        exit(1);
    }
    if((m==0 && n!=0 )|| (m!=0 && n==0)){
        printf("\nThe resultant polynomial is : 0x^0\n\n");

        exit(1);
    }
    for(int j=0; j<n; j++){
        printf("Enter the coefficient : ");
        scanf("%d", &coef);
        printf("Enter the exponent : ");
        scanf("%d", &exp);
        qHeader = newNode(qHeader, coef, exp);
    }
    printf("\nThe first polynomial is : \n"); 
    display(pHeader);
    printf("\nThe second polynomial is : \n"); 
    display(qHeader);
    rHeader = multiply(pHeader, qHeader, rHeader);
    sort(rHeader);  
    printf("\nThe resultant polynomial is : \n"); 
    display(rHeader);
}