#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
}*root;

struct node* getnode(){
    struct node *new;
    new  = (struct node*)malloc(sizeof(struct node));
    return new;
}

struct node* search(int key){
    struct node *PTR = root;
    while(PTR != NULL && PTR->info != key){
        if(PTR->info > key)
            PTR = PTR->lchild;
        else 
            PTR = PTR->rchild;
    }
    return PTR;
}

void preorder(struct node *p)
{
    if(root == NULL)
        printf("Tree empty\n");
    else if(p!=NULL){
        printf("%d ", (p)->info);
        preorder((p)->lchild);
        preorder((p)->rchild);
    }  
}

void inorder(struct node *p)
{
    if(root == NULL)
        printf("Tree empty\n");
    else if(p!=NULL)
    {
        inorder((p)->lchild);
        printf("%d ", (p)->info);
        inorder((p)->rchild);
    }
}

void postorder(struct node *p)
{
    if(root == NULL)
        printf("Tree empty\n");
    else if(p!=NULL){
        postorder((p)->lchild);
        postorder((p)->rchild);
        printf("%d ", (p)->info);
    }
}

struct node* searchParent(int key){
    struct node *PTR = root;
    struct node *PAR = PTR;
    while(PTR != NULL && PTR->info != key){
        PAR = PTR;
        if(PTR->info > key)
            PTR = PTR->lchild;
        else 
            PTR = PTR->rchild;
    }
    return PAR;
}

void Insert(int key){
    if(search(key) != NULL){
        printf("Element already exists");
        return;
    }
    struct node *new = getnode();
    new->info = key;
    new->lchild = new->rchild = NULL;
    struct node *PAR = searchParent(key);
    if(key > PAR->info)
        PAR->rchild = new;
    else 
        PAR->lchild = new;
}

void Create(){
    int key;
    printf("ENTER -1 TO STOP\n");
    printf("Enter the root : ");
    scanf("%d", &key);
    if(key != -1){
        root = getnode();
        root->info = key;
        root->lchild = root->rchild = NULL;
    }
    while(key != -1){
        printf("Enter the child : ");
        scanf("%d", &key);
        if(key != -1)
            Insert(key);
    }
}

struct node *Tree_successor(struct node *z){
    struct node *PTR = z->rchild;
    while(PTR->lchild != NULL)
        PTR = PTR->lchild;
    return PTR;
}

void Delete(){
    int key;
    printf("Element to Delete : ");
    scanf("%d", &key);
    struct node *x, *y, *z, *PAR;
    z = search(key);
    if(z == NULL){
        printf("!!!ELEMENT DOESN'T EXIST!!!");
        return;
    }
    if(z->lchild == NULL || z->rchild == NULL)
        y=z;
    else 
        y = Tree_successor(z);    
    if(y->lchild != NULL)
        x = y->lchild;
    else
        x= y->rchild;
    PAR = searchParent(y->info);
    if(PAR->lchild == y)
        PAR->lchild = x;
    else
        PAR->rchild = x;
    if(y != z)
        z->info = y->info;
    printf("Element %d deleted", key);
    free(y);
}

int main(){
    int ch; 
    printf("Menu\n");
    printf("1.Create\n2.Delete\n3.InOrder\n4.PreOrder\n5.PostOrder\n6.Exit");
    while(1){
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1 : Create(); break;
            case 2 : Delete(); break;
            case 3 : inorder(root); break;
            case 4 : preorder(root); break;
            case 5 : postorder(root); break;
            case 6 : exit(0);
        }
    }
}