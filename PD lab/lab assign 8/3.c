#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  char data;
 struct node* left;
 struct node* right;
 struct node* next;
};
typedef struct node* node;
struct stack{
node top;
};
typedef struct stack* node1;
struct tree{
node root;
};
typedef struct tree* node2;

int S_E(node1 S){
if(S->top==0)return 1;
else return 0;
}
node PUSH(node1 S,node x) {
	
	if(S->top==0)return x;
	else{
	x->next=S->top;
	return x;}}
	
node POP(node1 S) {
	if(S_E(S))return S->top;
	else{
	    S->top=S->top->next;
	    return S->top;
	}
}
node CREATE(char ch)
{
  node N=(node)malloc(sizeof(struct node));
  N->data=ch;
  N->left=N->right=N->next=0;
  return N;
}
node CONSTRUCT_TREE(char *e)
{
  node1 S=(node1)malloc(sizeof(struct stack));
	S->top=0;
	int i,j,k;
	int n=strlen(e);
	for(i=0;i<n;i++) {
		if(e[i]=='+'||e[i]=='-'||e[i]=='*'||e[i]=='/') {
			node var1=S->top;
			S->top=POP(S);
			node var2=S->top;
			S->top=POP(S);
			node var3=CREATE(e[i]);
			var3->right=var1;
			var3->left=var2;
			S->top=PUSH(S,var3);
		}
		else {
			node var=CREATE(e[i]);
			S->top=PUSH(S,var);
		}
	}
	node var=S->top;
	return var;

}
void INORDER(node T)
{
  if(T){
  INORDER(T->left);
  printf("%c",T->data);
  INORDER(T->right);
}
}
void PREORDER(node T)
{
  if(T){
  printf("%c",T->data);
  PREORDER(T->left);
  PREORDER(T->right);
}
}
void POSTORDER(node T)
{
 if(T){
 POSTORDER(T->left);
 POSTORDER(T->right);
 printf("%c",T->data);
}
}
int main()
{
 char ch,e[100];
 int w=0;
 node2 T=(node2)malloc(sizeof(struct tree));
 T->root=0;
 while(w<1)
 {
  scanf("%c",&ch);
  switch(ch){
  case 'e':scanf("%s",e);
           T->root=CONSTRUCT_TREE(e);
           break;
           
  case 'i':INORDER(T->root);
           break;
           
  case 'p':PREORDER(T->root);
           break;
           
  case 's':POSTORDER(T->root);
           break;
           
  case 't':w++;
  }}
  return 0;
  }

