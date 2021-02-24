#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 50

struct node {
    char info;
    struct node *link;
}*top = NULL;


void push(char item)
{  
struct node *new = (struct node*)malloc(sizeof(struct node));  
    if(new == NULL)
    {
        printf("\nItem could not be pushed");
        exit(0);
    }
    else
    {
        new->info = item;
        if(top == NULL)
        {
            new->link = NULL;
            top = new;
        }
        else 
        {
            new->link = top;
            top = new;
        }
    }    
}


char pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow!");
        exit(1);
    }
    struct node *temp = top;
    char item = temp->info;
    top = top->link;
    free(temp);
    return item;
}


int precedence(char item)
{
    if(item == '(')
        return 0;
    
    else if(item == '+'  || item == '-')
        return 1;
    
    else if(item == '*' || item == '/' || item == '%')
        return 2;
    else
         if(item == '^')
         return 3;
    else
        return -1;
}


void infixToPostfix(char infix[MAX], char postfix[MAX])
{
    int j = 0;
    
    for(int i=0; infix[i] != '\0'; i++)
    {
        if(isalpha(infix[i]))
            postfix[j++] = infix[i];
        
        else if(infix[i] == '(' || infix[i] == '^')
            push(infix[i]);
        
        else if(infix[i] == ')')
        {
            while(top->info != '(')
                postfix[j++] = pop();
                
            pop();
        }
        else
        {
            if(precedence(infix[i]) == -1)
            {
                printf("Invalid Input!");
                exit(1);
            }
            
            while((precedence(top->info)) >= precedence(infix[i]))
                postfix[j++] = pop();
                
            push(infix[i]);
        }
    }
}  



int main()
{
    int ch;
    
    do
    {
        char infix[MAX], postfix[MAX] = "";
        
        printf("Enter the Infix Expression : ");
        scanf("%s", infix);
        
        strcat(infix, ")");
        push('(');
        
        infixToPostfix(infix, postfix);
        
        printf("The Postfix Expression : %s\n", postfix);
        
        printf("\npress 1 to enter another expression (0 to stop) : ");
        scanf("%d", &ch);
        
    }while(ch != 0);
    return 0;
}