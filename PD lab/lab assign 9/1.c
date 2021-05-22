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

node INSERT(tree T,node z)
{
if(T->root==0)return z; 
else if(z->val<T->root->val) {
		T->root->left=INSERT(T->root->left,z); 
		T->root->left->par=T->root;
	}
	else {
		T->root->right=INSERT(T->root->right,z); 
		T->root->right->par=T->root;
	}
	return T->root;

}

node TREE_MIN(node T)
{
while(T->left!=NULL)T=T->left;
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
         T->root=INSERT(T,x);
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
         
case 'i':INORDER(T->root);
         break;
         
case 'p':PREORDER(T->root);
         break;
         
case 't':POSTORDER(T->root);
         break;
         
case 'e':w++;
}}
return 0;
}
