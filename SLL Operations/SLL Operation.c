#include<stdio.h>
#include<stdlib.h>

void enque();
void deque();
void display();
 
struct Node{
    int data;
    struct Node *link;
}*top=NULL,*new,*temp,*prev=NULL;

int count=0;

int main(){
    int choice;
    while(1){
        printf("\nChoose SLL Operation ==>\n");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Display List");
        printf("\n4. Exit\n\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:enque();
                   break;
            case 2:deque();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default: printf("\n\n!!!WRONG INPUT!!!\n\n");
        }
    }
}

void enque(){
    int i=1,item,pos;
    printf("\nEnter Element to Insert : ");    
    scanf("%d",&item);
    printf("\nEnter Position to Insert(1-%d) : ",count+1);    
    scanf("%d",&pos);
    if(pos==1){
        new=(struct Node*)malloc(sizeof(struct Node));
        new->data=item;
        new->link=top;
        top=new;
        count++;
    }
    else if(pos==count+1){
        new=(struct Node*)malloc(sizeof(struct Node));
        new->data=item;
        new->link=NULL;
        temp=top;
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=new;
        count++;                
    }
    else if(pos==0||pos>count+1)
        printf("\n\n!!!INVALID POSTION!!!\n\n");
    else{
        new=(struct Node*)malloc(sizeof(struct Node));
        new->data=item;
        temp=top;                
        while(i<pos-1){
            temp=temp->link;
            i++;
        }
        new->link=temp->link;
        temp->link=new;
        count++;
    }
}

void deque(){
    int item;
    if(top==NULL)
        printf("\n\n!!!LIST IS EMPTY!!!\n\n");
    else{
        printf("\nEnter Element to Delete : ");    
        scanf("%d",&item);
        temp=top;            
        while(temp!=NULL&&temp->data!=item){
            prev=temp;
            temp=temp->link;
        }                    
        if(temp==NULL)
            printf("\n\n!!!ELEMENT NOT PRESENT!!!\n\n");
        else if(top==temp){
            top=top->link;
            item=temp->data;
            free(temp);
            count--;
        }   
        else if(prev->link==temp) {
            prev->link=temp->link;
            item=temp->data;
            free(temp);
            count--;
        }
        else{
            item=temp->data;
            prev->link=NULL;
            free(temp);
            count--;
        }
    }
}

void display(){
    if(top==NULL)
        printf("\n\n!!!LIST IS EMPTY!!!\n\n");
    else{
        temp=top;
        printf("LIST ==>\n");        
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
}