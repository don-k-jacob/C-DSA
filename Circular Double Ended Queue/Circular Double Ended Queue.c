#include<stdio.h>
#include<stdlib.h>

#define MAX 5

void enqueFront(int, int *, int *);
void enqueRear(int, int *, int *);
void dequeFront(int *, int *);
void dequeRear(int *, int *);
void displayQueue(int *, int *);

int array[MAX];

int main(){
int ch1, element, rear=-1, front=-1, ch2 ;
	while(1){
		printf("\nChoose Operation ==>\n");
    	printf("\n1. Insert Element");
    	printf("\n2. Delete Element");
    	printf("\n3. Display");
    	printf("\n4. Exit\n\n");

    	scanf("%d",&ch1);
	    switch(ch1){
    	    case 1 : printf("\nEnter Element to Insert : ");
	        		 scanf("%d",&element);
	        		 printf("\nWhere to Insert?\n\n1. At Front\n2. At Rear\n\n");
	        		 scanf("%d",&ch2);
	        		 if(ch2==1)
	        		 	enqueFront(element, &rear, &front);
	        		 else if(ch2==2)
	        		 	enqueRear(element, &rear, &front);
        			 break;
        	case 2 : printf("\nWhere to delete from?\n\n1. At Front\n2. At Rear\n\n");
	        		 scanf("%d",&ch2);
	        		 if(ch2==1)
	                	dequeFront(&rear, &front);
	        		 else if(ch2==2)
	                	dequeRear(&rear, &front);
    	    		 break;
	        case 3 : displayQueue(&rear, &front);
        			 break;
        	case 4 : exit(0);
        	default: printf("\n\n!!!WRONG INPUT!!!\n\n");
    	}
	}
}

void enqueFront(int x, int *r, int *f){
	if((*f==0 && *r==MAX-1) || (*f==*r+1))
		printf("\n\n!!!QUEUE IS FULL!!!\n\n");
	else if(*f==-1 && *r==-1){
		*f=*r=0;
		array[*f]=x;
	}
	else if(*f==0){
		*f=MAX-1;
		array[*f]=x;
	}
	else{
		*f=*f-1;
		array[*f]=x;
	}
}

void enqueRear(int x, int *r, int *f){
	if((*f==0 && *r==MAX-1) || (*f==*r+1))
		printf("\n\n!!!QUEUE IS FULL!!!\n\n");
	else if(*f==-1 && *r==-1){
		*f=*r=0;
		array[*r]=x;
	}
	else if(*r==MAX-1){
		*r=0;
		array[*r]=x;
	}
	else{
		*r=*r+1;
		array[*r]=x;
	}
}

void dequeFront(int *r, int *f){
	if(*f==-1 && *r==-1)
		printf("\n\n!!!QUEUE IS EMPTY!!!\n\n");
	else if(*f==*r){
		printf("\n==> %d deleted.\n",array[*f]);
		*f=*r=-1;
	}
	else if(*f==MAX-1){
		printf("\n==> %d deleted.\n",array[*f]);
		*f=0;
	}
	else{
		printf("\n==> %d deleted.\n",array[*f]);
		*f=*f+1;
	}
}

void dequeRear(int *r, int *f){
	if(*f==-1 && *r==-1)
		printf("\n\n!!!QUEUE IS EMPTY!!!\n\n");
	else if(*f==*r){
		printf("\n==> %d deleted.\n",array[*r]);
		*f=*r=-1;
	}
	else if(*r==0){
		printf("\n==> %d deleted.\n",array[*r]);
		*r=MAX-1;
	}
	else{
		printf("\n==> %d deleted.\n",array[*r]);
		*r=*r-1;
	}
}

 
void displayQueue(int *r, int *f){
	if(*f==-1 && *r==-1)
		printf("\n\n!!!QUEUE IS EMPTY!!!\n\n");
	else{
		printf("\n\n\nQUEUE==>\n");
		for(int i=*f;i<=*r;i++) 
			printf("%d\t",array[i]);
		printf("\n");
	}
}