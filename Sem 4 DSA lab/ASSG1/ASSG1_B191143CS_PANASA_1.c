#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
int val;
struct node* left;
struct node* right;
struct node* par;
struct node* next;
};

typedef struct node* node;

struct tree{
node root;
};

struct Queue{
node head;
node tail;
};
typedef struct tree* tree;
typedef struct Queue* Queue;
node CREATE(int k)
{
 node N=(node)malloc(sizeof(struct node));
 N->val=k;
 N->left=N->right=N->par=NULL;
 return N;
}

void ENQUEUE(Queue Q,node N)
{
 if(Q->head==NULL&&Q->tail==NULL){
 Q->head=N;
 Q->tail=N;}
 else{
 Q->tail->next=N;
 Q->tail=N;}

}

void DEQUEUE(Queue Q){
if(Q->head==NULL)return ;
else {Q->head=Q->head->next;}
return ;
}

node INSERT(node T,node z,Queue Q)
{
 if(T==NULL){T=z; ENQUEUE(Q,z); return T;}
 node N=Q->head;
 if(N->left==NULL){N->left=z; ENQUEUE(Q,z); return T;}
 if(N->right==NULL){N->right=z; ENQUEUE(Q,z); DEQUEUE(Q); return T;}
}

void TREE_STRING(node root)
{
        if(root!=NULL)
        {
                printf("( %d ",root->val);
                TREE_STRING(root->left);
                TREE_STRING(root->right);
                printf(") ");
        }
        else
        {
                printf("( ) ");
                return;
        }
}


int main(){
char ch;
node x;
tree T=(tree)malloc(sizeof(struct tree));
Queue Q=(Queue)malloc(sizeof(struct Queue));
Q->head=Q->tail=NULL;
T->root=NULL;
int w=0,k;
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'i':scanf("%d",&k);
         x=CREATE(k);
         T->root=INSERT(T->root,x,Q);
         break;
         
case 'p':TREE_STRING(T->root);
         break;
case 'e':w++;
}}
return 0;
}
