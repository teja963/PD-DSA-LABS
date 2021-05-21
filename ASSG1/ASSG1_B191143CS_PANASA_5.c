#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
int val;
struct node* left;
struct node* right;
};

typedef struct node* node;

struct tree{
node root;
};

typedef struct tree* tree;
node CREATE()
{
 node N=(node)malloc(sizeof(struct node));
 N->left=N->right=NULL;
 return N;
}



int k_small(node T,int *i,int k){
if(T==NULL)return INT_MAX;
int l=k_small(T->left,i,k);
if(l!=INT_MAX)return l;
if(k==++*i)return T->val;
return k_small(T->right,i,k);}

int kth(node T,int k){
int i=0;
return k_small(T,&i,k);
}

node STRING_TREE()
{
        char c;
        int d;
        scanf(" %c",&c);
        if(scanf("%d",&d)==1)
        {
                node T=CREATE();
                T->val = d;
                T=T;
                T->left = STRING_TREE();
                T->right =STRING_TREE();
                scanf(" %c",&c);                                                                                                                                                                                                      return T;                                                                                                                                                                                                   }                                                                                                                                                                                                                    else                                                                                                                                                                                                                 {                                                                                                                                                                                                                            scanf(" %c",&c);                                                                                                                                                                                                     return NULL;
	}
}


int main(){
int k;
char *s;
tree T=(tree)malloc(sizeof(struct tree));
T->root=STRING_TREE();
scanf("%d",&k);
printf("%d\n",kth(T->root,k));
return 0;}
