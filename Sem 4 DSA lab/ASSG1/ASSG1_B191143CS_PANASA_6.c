#include<stdio.h>
#include<stdlib.h>
struct node{
int val;
struct node* left;
struct node* right;
};

typedef struct node* node;


node CREATE(int k)
{
 node N=(node)malloc(sizeof(struct node));
 N->val=k;
 N->left=N->right=NULL;
 return N;
}
node sorted_array(int *a,int l,int h){
if(l>h)return NULL;
int m=(l+h)/2;
node T=CREATE(a[m]);
T->left=sorted_array(a,l,m-1);
T->right=sorted_array(a,m+1,h);
return T;}

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

void calculateLevelSum(node T, int level, int sum[]) { 
if (T == NULL) return; 
sum[level] += T->val;  
calculateLevelSum(T->left, level + 1, sum); 
calculateLevelSum(T->right, level + 1, sum); 
} 

int getHeight(node root) 
{ 
    if (root->left == NULL && root->right == NULL)return 0;
    int left = 0; 
    if (root->left != NULL) left = getHeight(root->left);
    int right = 0; 
    if (root->right != NULL) right = getHeight(root->right); 
    return (1+(left>right?left:right)); 
} 
  

void printArr(int *arr, int n){ 
printf("\n");
    for (int i = 0; i < n; i++)printf("%d ",arr[i]);
} 
int main()
{
int n,*a,i,j;
node x;
a=(int*)malloc(n*sizeof(int));
scanf("%d",&n);
if(n==0)printf("( ) ");
else{
for(i=0;i<n;i++){
scanf("%d",&a[i]);}
x=sorted_array(a,0,n-1);
TREE_STRING(x);
 j= getHeight(x) + 1; 
int A[10000]={0}; 
calculateLevelSum(x, 0, A); 
printArr(A,j); }
return 0;
}

