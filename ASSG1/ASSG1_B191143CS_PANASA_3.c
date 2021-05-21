#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c=0;
struct node{
int val;
int sum;
struct node* left;
struct node* right;
struct node* par;
};

struct tree{
struct node* root;
};

typedef struct node* node;
typedef struct tree* tree;

node CREATE()
{
 node N=(node)malloc(sizeof(struct node));
 N->left=N->right=N->par=NULL;
 return N;
}

node input()
{
        char c;
        int d;
        scanf(" %c",&c);
        if(scanf("%d",&d)==1)
        {
                node T=CREATE();
                T->val = d;
                T=T;
                T->left = input();
                T->right = input();
                scanf(" %c",&c);                                                                                                                                                                                                      return T;                                                                                                                                                                                                   }                                                                                                                                                                                                                    else                                                                                                                                                                                                                 {                                                                                                                                                                                                                            scanf(" %c",&c);                                                                                                                                                                                                     return NULL;
	}
}

node min(node x){while(x->left!=NULL)x=x->left; return x;}
node max(node x){while(x->right!=NULL)x=x->right; return x;}


int inorderbst(node root)
{
    if(root==NULL)return 1;
    if(root->left&&max(root->left)->val>root->val)return 0;
    if(root->right&&min(root->right)->val<root->val)return 0;
    if(!inorderbst(root->left)||!inorderbst(root->right))return 0;
return 1;
}

void sum(node ptr,int k)
{
    if(ptr->left)sum(ptr->left,k);
    if(ptr->right)sum(ptr->right,k);
    ptr->sum=ptr->val;
    if(ptr->left)ptr->sum=ptr->sum+ptr->left->sum;
    if(ptr->right)ptr->sum=ptr->sum+ptr->right->sum;
}

void BST(node root,int k)
{
    if(root==NULL)return;
    BST(root->left,k);
    if(root->sum==k&&inorderbst(root))c++;
    BST(root->right,k);
}
 



int main(){
int k;
tree T=(tree)malloc(sizeof(struct tree));
T->root=input();
scanf("%d",&k);
if(T->root==NULL)printf("-1\n");
else{
sum(T->root,k);
BST(T->root,k);
if(c)printf("%d\n",c);
else printf("-1\n");}
return 0;}

