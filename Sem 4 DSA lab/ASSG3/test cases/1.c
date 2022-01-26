#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};
typedef struct Node* node;
int max(int a, int b);
int height(node N)
{
	if (N == NULL)return 0;
	return N->height;
}

int max(int a, int b){return (a > b)? a : b;}

node newNode(int key)
{
	node N = (node)malloc(sizeof(struct Node));
	N->key = key;
	N->left = NULL;
	N->right = NULL;
	N->height = 1;
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
	else 
		return N;

	
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


 
void PAR(node root)
{
        if(root!=NULL)
        {
                printf("( %d ",root->key);
                PAR(root->left);
                PAR(root->right);
                printf(") ");
        }
        else
        {
                printf("( ) ");
                return;
        }
}

node minValueNode(node N)
{
    node current = N;
    while (current->left != NULL)current = current->left;
    return current;
}

node DELETE(node root, int key)
{ 
    if(root==NULL)return root;
    if(key<root->key)root->left=DELETE(root->left,key);
    else if(key>root->key)root->right=DELETE(root->right,key);
    else
    {
        if((root->left==NULL)||(root->right==NULL))
        {
            node temp=root->left ? root->left:root->right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp; 
            free(temp);
        }
        else
        {
           
            node temp = minValueNode(root->right);
            root->key = temp->key;
            root->right=DELETE(root->right,temp->key);
        }
    }
  
    if(root == NULL)return root;
    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if(balance>1&&getBalance(root->left)>=0)return rightRotate(root);
    if(balance>1&&getBalance(root->left)<0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
  
   
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
  
    return root;
}

node SEARCH(node root,int key)
{
    if(root==NULL||root->key==key)return root;
    if(root->key < key)return SEARCH(root->right, key);
    return SEARCH(root->left, key);
}
int main()
{
node root = NULL;
node N;
int i,j,k,w=0;
char c;
while(w<1){
 scanf("%c",&c);
 switch(c){
  case 'i':scanf("%d",&k);
           root=insert(root,k);
           break;
           
  case 's':scanf("%d",&k);
           N=SEARCH(root,k);
           if(N!=NULL)printf("TRUE\n");
           else printf("FALSE\n");
           break;
           
  case 'd':scanf("%d",&k);
           N=SEARCH(root,k);
           if(N!=NULL){printf("%d\n",k); root=DELETE(root,k);}
           else printf("FALSE\n");
           break;
           
  case 'b':scanf("%d",&k);
           N=SEARCH(root,k);
           if(N!=NULL)printf("%d\n",getBalance(N));
           else printf("FALSE\n");
           break;
           
           
  case 'p':PAR(root);
           printf("\n");
           break;
           
  case 'e':w++;
  
  }}
  return 0;
}

