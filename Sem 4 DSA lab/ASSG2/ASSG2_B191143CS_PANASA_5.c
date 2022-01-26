#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
int data;
struct node* left;
struct node* right;
struct node* par;
};

typedef struct node* node;

struct tree{
node root;
};
typedef struct tree* tree;

node CREATE(int k){
node N=(node)malloc(sizeof(struct node));
N->data=k;
N->left=NULL;
N->right=NULL;
N->par=NULL;
return N;
}

node input(){
char c;
int i;
scanf(" %c",&c);
if(scanf("%d",&i)==1){
node T=CREATE(i);
T=T;
T->left=input();
T->right=input();
scanf(" %c",&c);
return T;}
else {scanf(" %c",&c); return NULL;}}

void INORDER(node T){
if(T){
INORDER(T->left);
printf("%d ",T->data);
INORDER(T->right);}}

node SEARCH(node T,int k)
{
 node y=T;
	int f=0;
	while(y!=NULL)
	{
	 if(y->data==k)
	 {
	  f=1;
	  return y;
	  }
	 else if(k<y->data)y=y->left;
	 else y=y->right;
	}
	if(f==0)return NULL;
}

node TREE_MIN(node T)
{
while(T->left!=NULL)T=T->left;
return T;
}

node TREE_MAX(node T)
{
while(T->right!=NULL)T=T->right;
return T;
}

node SUC(node x){
if(x->right!=NULL)return TREE_MIN(x->right);
node y=x->par;
while(y!=NULL&&x==y->right){x=y; y=y->par;}
return y;}

node PRE(node x){
if(x->left!=NULL)return TREE_MAX(x->left);
node y=x->par;
while(y!=NULL&&x==y->left){x=y; y=y->par;}
return y;}

int k_small(node T,int *i,int k){
if(T==NULL)return INT_MAX;
int l=k_small(T->left,i,k);
if(l!=INT_MAX)return l;
if(k==++*i)return T->data;
return k_small(T->right,i,k);}

int kth(node T,int k){
int i=0;
return k_small(T,&i,k);
}

int kth_larg(node T, int *i, int k)
{
    if (T == NULL)return INT_MAX;
    int left = kth_larg(T->right, i, k);
    if (left != INT_MAX)return left;
    if (++*i == k)return T->data;
    return kth_larg(T->left, i, k);
}
 
int kth_largest(node T, int k)
{
    int i = 0;
    return kth_larg(T, &i, k);}

int main(){
int i,j,k,w=0;
node N;
char c;
tree T=(tree)malloc(sizeof(struct tree));
T->root=input();
while(w<1){
scanf("%c",&c);
switch(c){
case 'r':scanf("%d",&k);
         node x=SEARCH(T->root,k);
         if(x){if(PRE(x)!=NULL)printf("%d\n",PRE(x)->data); else printf("-1\n");}
         else printf("-1\n");
         break;
         
case 'u':scanf("%d",&k);
         x=SEARCH(T->root,k);
         if(x){if(SUC(x)!=NULL)printf("%d\n",SUC(x)->data); else  printf("-1\n");}
         else printf("-1\n");
         break;
         
case 'i':INORDER(T->root);
         printf("\n");
         break;
         
case 'l':scanf("%d",&i);
         int j=kth_largest(T->root,i);
         if(j!=INT_MAX)printf("%d\n",j);
         else printf("-1\n");
         break;
         
case 's':scanf("%d",&i);
         printf("%d\n",kth(T->root,i));
         break;
         
case 'e':w++;}}
return 0;}


