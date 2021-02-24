
#include<stdio.h>
#include<stdlib.h>

void Stack();
void push(int);
void pop();
void diplayStack();

void Queue();
void enque(int);
void deque();
void displayQueue();

int item;

struct Node{
	int data;
	struct Node *link;
}*top=NULL,*front=NULL,*rear=NULL;

int main(){
	int choice;
	printf("\nMain Menu ==>\n");
    printf("\n1. Stack");
   	printf("\n2. Queue");
	printf("\n3. Exit\n\n");
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
        			 push(element);
        			 break;
        	case 2 : pop();
    	    		 break;
	        case 3 : diplayStack();
        			 break;
        	case 4 : system("clear");
        			 main();
        	default: printf("\n\n!!!WRONG INPUT!!!\n\n");
    	}
	}
}

void push(int x){
	struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = x;
    new->link = top;
	top = new;
}

void pop(){
	struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
	if(top == NULL)
		printf("\n\n!!!STACK IS EMPTY!!!\n\n");
	else
		temp = top;
        top = temp->link;
        item = temp->data;
        free(temp);
}

void diplayStack(){
	struct Node *p;  
    p=top;
	if(top == NULL)
		printf("\n\n!!!STACK IS EMPTY!!!\n\n");
	else
		printf("STACK ==>\n");
        while(p != NULL){  
            printf("%d\t",p->data);  
            p = p->link;
        }
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
        			 enque(element);
        			 break;
        	case 2 : deque();
    	    		 break;
	        case 3 : displayQueue();
        			 break;
			case 4 : system("clear");
        			 main();
           	default: printf("\n\n!!!WRONG INPUT!!!\n\n");
    	}
	}
}

void enque(int x){
	struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = x;
    new->link = NULL;
    if(front == NULL){
        front = rear = new;
    }
    else{
        rear->link = new;
        rear = new;
    }
}

void deque(){
	struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
	if(front == NULL && rear == NULL)
		printf("\n\n!!!QUEUE IS EMPTY!!!\n\n");
	else{ 
		item = front->data;
        temp = front;
        if(front == rear)
        	front = rear = NULL;
        else
           front = front->link;
    }
	free(temp);
}

void displayQueue(){
	struct Node *p;  
    p = front;
	if(front == NULL && rear == NULL)
		printf("\n\n!!!QUEUE IS EMPTY!!!\n\n");
	else
		printf("QUEUE ==>\n");
		while(p != NULL){  
            printf("%d\t",p->data); 
            p = p->link;
        } 
		printf("\n");
}