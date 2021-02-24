#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void Stack();
void push(int, int *);
void pop(int *);
void diplayStack(int *);

void Queue();
void enque(int, int *, int *);
void deque(int *, int *);
void displayQueue(int *, int *);

int array[MAX];

int main(){
	int choice;
	while(1){
    	printf("\n\n1. Stack");
    	printf("\n2. Queue\n");
    	scanf("%d",&choice);
    	switch(choice){
        	case 1 : Stack();
        			 break;
        	case 2 : Queue();
        			 break;
        	case 3 : exit(0);
        	default: printf("\n\n!!!WRONG INPUT!!!\n\n");
    	}
	}
}

void Stack(){
	int ch, element, top=-1;
	while(1){
		printf("\nChoose Stack Operation ==>\n");
    	printf("\n1. Insert Element(Push)");
    	printf("\n2. Delete Element(Pop)");
    	printf("\n3. Display Stack");
    	printf("\n4. Exit\n\n");
    	scanf("%d",&ch);
	    switch(ch){
    	    case 1 : printf("\nEnter Element to Push : ");
	        		 scanf("%d",&element);
        			 push(element, &top);
        			 break;
        	case 2 : pop(&top);
    	    		 break;
	        case 3 : diplayStack(&top);
        			 break;
        	case 4 : exit(0);
        	default: printf("\n\n!!!WRONG INPUT!!!\n\n");
    	}
	}
}

void push(int x, int *top){
	if(*top==MAX-1)
		printf("\n\n!!!STACK IS FULL!!!\n\n");
	else{
		*top=*top+1;
		array[*top]=x;
	}
}

void pop(int *top){
	if(*top==-1)
		printf("\n\n!!!STACK IS EMPTY!!!\n\n");
	else
		*top=*top-1;
}

void diplayStack(int *top){
	if(*top==-1)
		printf("\n\n!!!STACK IS EMPTY!!!\n\n");
	else
		printf("STACK==>\n");
		for(int i=0;i<=*top;i++)
			printf("%d\t",array[i]);
		printf("\n");
}

void Queue(){
	int ch, element, rear=-1, front=-1;
	while(1){
		printf("\nChoose Queue Operation ==>\n");
    	printf("\n1. Insert Element(enque)");
    	printf("\n2. Delete Element(deque)");
    	printf("\n3. Display Queue");
    	printf("\n4. Back to Main\n\n");

    	scanf("%d",&ch);
	    switch(ch){
    	    case 1 : printf("\nEnter Element to Push : ");
	        		 scanf("%d",&element);
        			 enque(element, &rear, &front);
        			 break;
        	case 2 : deque(&rear, &front);
    	    		 break;
	        case 3 : displayQueue(&rear, &front);
        			 break;
        	case 4 : break;
        	default: printf("\n\n!!!WRONG INPUT!!!\n\n");
    	}
	}
}

void enque(int x, int *rear, int *front){
	if(*rear==MAX-1)
		printf("\n\n!!!QUEUE IS FULL!!!\n\n");
	else{
		if(*front==-1)
			*front=0;
		*rear=*rear+1;
		array[*rear]=x;
	}
}

void deque(int *rear, int *front){
	if(*front==-1 && *rear==-1)
		printf("\n\n!!!QUEUE IS EMPTY!!!\n\n");
	else
		if(*front==*rear)
			*front=*rear=-1;
		else
			*front=*front+1;
}

void displayQueue(int *rear, int *front){
	if(*front==-1 && *rear==-1)
		printf("\n\n!!!QUEUE IS EMPTY!!!\n\n");
	else
		printf("QUEUE==>\n");
		for(int i=*front;i<=*rear;i++) 
			printf("%d\t",array[i]);
		printf("\n");
}