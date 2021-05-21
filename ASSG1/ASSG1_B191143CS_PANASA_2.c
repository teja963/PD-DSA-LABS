#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int c=0;
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
int getlevel(node T,int k,int l){
if(T==NULL)return 0;
if(T->val==k)return l;
int dl=getlevel(T->left,k,l+1);
if(dl!=0)return dl;
return getlevel(T->right,k,l+1);}

int count = 0;
void print_level(node T,int k,int l){
if(T==NULL||l<2)return ;
if(l==2){
    if(T->left!=NULL){
        if(T->left->val==k)
            return;
    }
    if(T->right!=NULL){
        if(T->right->val==k)
            return;
    }

 //if(T->left->val==k||T->right->val==k)return ;
 if(T->left!=NULL){
        count += 1;
     printf("%d ",T->left->val);
 }
 if(T->right!=NULL){
        count += 1;
     printf("%d ",T->right->val);
 }
 }
 
else if(l>2){
 print_level(T->left,k,l-1);
 print_level(T->right,k,l-1);
}

}

void cous(node T,int k){
 int level=getlevel(T,k,1);
 print_level(T,k,level);
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
                T->right= STRING_TREE();
                scanf(" %c",&c);                                                                                                                                                                                                      return T;                                                                                                                                                                                                   }                                                                                                                                                                                                                    else                                                                                                                                                                                                                 {                                                                                                                                                                                                                            scanf(" %c",&c);                                                                                                                                                                                                     return NULL;
	}
}



int main(){
int k,i=0;
char *s;
node N;
tree T=(tree)malloc(sizeof(struct tree));
T->root=STRING_TREE();
scanf("%d",&k);
cous(T->root,k);
    if(!count)
        printf("-1");
return 0;}


