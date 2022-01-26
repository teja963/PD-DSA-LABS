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

node INSERT(node T,node x){
if(T==NULL)return x;
if(x->data<T->data){T->left=INSERT(T->left,x); T->left->par=T;}
else if(x->data>T->data){T->right=INSERT(T->right,x); T->right->par=T;}
return T;}

int maxelpath(node q, int x) 
{ 
    node p = q; 
    int mx = INT_MIN;  
    while (p -> data != x) 
    { 
        if (p -> data > x) 
        { 
            mx =(mx>p->data)?mx:p->data; 
            p = p -> left; 
        } 
        else
        { 
            mx =(mx>p->data)?mx:p->data;
            p = p -> right; 
        } 
    } 
  
    return mx; 
} 

int maximumElement(node T, int x, int y) 
{ 
    node p = T;  
    while ((x < p -> data && y < p -> data) || 
        (x > p -> data && y > p -> data)) 
    {  
        if (x < p -> data && y < p -> data) p = p -> left; 
        else if (x > p -> data && y > p -> data) p = p -> right; 
    } 
    if(p->data!=x&&p->data!=y)return (maxelpath(p, x)>maxelpath(p, y))?maxelpath(p, x):maxelpath(p, y);
    else if(p->data==x){
    if(y<x) return maxelpath(p->left,y); 
    else return maxelpath(p->right,y);}
    else if(p->data==y){
    if(x>y)return maxelpath(p->right,x);
    else return maxelpath(p->left,x);} 
} 
int main(){
int i,j,k,w=0;
char c;
tree T=(tree)malloc(sizeof(struct tree));
T->root=NULL;
while(w<1){
if(scanf("%d%c",&i,&c)&&c==' ')T->root=INSERT(T->root,CREATE(i));
else {T->root=INSERT(T->root,CREATE(i)); w++;}}
scanf("%d %d",&j,&k);
printf("%d\n",maximumElement(T->root, j, k));
return 0;}


