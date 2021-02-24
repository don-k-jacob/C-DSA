#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

 
struct node   
{  
int info;  
struct node *link;  
};  
struct node *top;  

void push(char x){
struct node *new = (struct node*)malloc(sizeof(struct node));   
    new->info = x;
    new->link = top;
    top = new;
}

char pop(){
    char item;
    struct node *temp;
struct node *new = (struct node*)malloc(sizeof(struct node)); 
    if(top == NULL)
        printf("\n\n!!!STACK IS EMPTY!!!\n\n");
    else
        temp = top;
        top = temp->link;
        item = temp->info;
        free(temp);
        return item; 
}

int priority(char x)
{
if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
      else if(x=='^')
         return 3;
    else
        return 0;}
int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(top->info) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    printf("evaluvation done\n");
    while(top != NULL)
    {
        printf("%c ",pop());
    }
    return 0;
}