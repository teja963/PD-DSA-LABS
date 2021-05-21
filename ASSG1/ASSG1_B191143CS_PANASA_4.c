#include<stdio.h>
#include<stdlib.h>
struct node{
int val;
struct node* left;
struct node* right;
struct node* par;
};

typedef struct node* node;

struct tree{
node root;
};

typedef struct tree* tree;

node CREATE(int k)
{
 node N=(node)malloc(sizeof(struct node));
 N->val=k;
 N->left=N->right=N->par=NULL;
 return N;
}

void INSERT(tree T,node z){
node y=NULL,x=T->root;
while(x!=NULL){
  y=x;
  if(z->val<x->val)x=x->left;
  else x=x->right;}
z->par=y;
if(y==NULL)T->root=z;
else if(z->val<y->val)y->left=z;
else y->right=z;

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

void TRANSPLANT(tree T,node u,node v)
{
if(u->par==NULL)T->root=v;
else if(u==u->par->left)u->par->left=v;
else u->par->right=v;
if(v!=NULL)v->par=u->par;
}

void DELETE(tree T,node x)
{
 node y;
if(x->left==NULL)TRANSPLANT(T,x,x->right);
else if(x->right==NULL)TRANSPLANT(T,x,x->left);
else {
 y=TREE_MIN(x->right);
 if(y->par!=x)
 {
  TRANSPLANT(T,y,y->right);
  y->right=x->right;
   y->right->par=y;
  }
     TRANSPLANT(T,x,y);
    y->left=x->left;
   y->left->par=y;
	}
}

node SEARCH(tree T,int k)
{
 node y=T->root;
	int f=0;
	while(y!=NULL)
	{
	 if(y->val==k)
	 {
	  f=1;
	  return y;
	  }
	 else if(k<y->val)y=y->left;
	 else y=y->right;
	}
	if(f==0)return NULL;
}

int find(node T,int k,int l){
if(T==NULL)return 0;
if(T->val==k)return l;
int x=find(T->left,k,l+1);
if(x!=0)return x;
x=find(T->right,k,l+1);
return x;}

int LEVEL(node T,int k){
return find(T,k,1);
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

void INORDER(node T){
if(T){
INORDER(T->left);
printf("%d ",T->val);
INORDER(T->right);}}

void PREORDER(node T){
if(T){
printf("%d ",T->val);
PREORDER(T->left);
PREORDER(T->right);}
}

void POSTORDER(node T){
if(T){
POSTORDER(T->left);
POSTORDER(T->right);
printf("%d ",T->val);}
}

int main(){
char ch;
node x;
tree T=(tree)malloc(sizeof(struct tree));
T->root=NULL;
int w=0,k;
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'a':scanf("%d",&k);
         x=CREATE(k);
         INSERT(T,x);
         break;
         
case 'd':scanf("%d",&k);
         x=SEARCH(T,k);
	 if(x==NULL)printf("-1\n");
	 else{
	 printf("%d\n",k);
	 DELETE(T,x);}
         break;
         
case 's':scanf("%d",&k);
         if(SEARCH(T,k))printf("1\n");
         else printf("-1\n");
         break;
         
case 'l':scanf("%d",&k);
         if(SEARCH(T,k))printf("%d\n",LEVEL(T->root,k));
         else printf("-1\n");
         break;
         
case 'r':scanf("%d",&k);
         x=SEARCH(T,k);
         if(x){if(PRE(x)!=NULL)printf("%d\n",PRE(x)->val); else printf("-1\n");}
         else printf("-1\n");
         break;
         
case 'u':scanf("%d",&k);
         x=SEARCH(T,k);
         if(x){if(SUC(x)!=NULL)printf("%d\n",SUC(x)->val); else  printf("-1\n");}
         else printf("-1\n");
         break;
         
case 'm':if(T->root!=NULL)
         printf("%d\n",TREE_MIN(T->root)->val);
         break;
         
case 'x':if(T->root!=NULL)
         printf("%d\n",TREE_MAX(T->root)->val);
         break;
         
case 'i':INORDER(T->root);
         printf("\n");
         break;
         
case 'p':PREORDER(T->root);
         printf("\n");
         break;
         
case 't':POSTORDER(T->root);
         printf("\n");
         break;
         
case 'e':w++;
}}
return 0;
}
