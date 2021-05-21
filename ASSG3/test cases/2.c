#include<stdio.h>
#include<stdlib.h>
struct node{
  int key;
  int count;
  int height;
  struct node* left;
  struct node* right;
  };
  
typedef struct node* node;

int max(int a, int b);
int height(node N)
{
	if (N == NULL)return 0;
	return N->height;
}

int max(int a, int b){return (a > b)? a : b;}

node newNode(int key)
{
	node N = (node)malloc(sizeof(struct node));
	N->key = key;
	N->left = NULL;
	N->right = NULL;
	N->height =N->count= 1;
	return N;
}


node rightRotate(node y)
{
	node x = y->left;
	node T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	return x;
}


node leftRotate(node x)
{
	node y = x->right;
	node T2 = y->left;

	
	y->left = x;
	x->right = T2;

	
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	return y;
}


int getBalance(node N)
{
	if (N == NULL)return 0;
	return height(N->left) - height(N->right);
}

node insert(node N, int key)
{
	
	if (N == NULL)
		return(newNode(key));

	if (key < N->key)
		N->left = insert(N->left, key);
	else if (key > N->key)
		N->right = insert(N->right, key);
	else N->count++;

	
	N->height = 1 + max(height(N->left),height(N->right));
	int balance = getBalance(N);
	if(balance>1&&key<N->left->key)return rightRotate(N);
	if(balance<-1&&key>N->right->key)return leftRotate(N);
	if (balance > 1 && key >N->left->key)
	{
		N->left = leftRotate(N->left);
		return rightRotate(N);
	}

	
	if (balance < -1 && key <N->right->key)
	{
		N->right = rightRotate(N->right);
		return leftRotate(N);
	}
	return N;
}

void inorder(node root){
 if(root){
 inorder(root->left);
 while(root->count--)printf("%d ",root->key);
 inorder(root->right);
 }}

int main(){
node root=NULL;
int n,i,j,k;
scanf("%d",&n);
int *a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)scanf("%d",&a[i]);
for(i=0;i<n;i++)root=insert(root,a[i]);
inorder(root);
return 0;}

