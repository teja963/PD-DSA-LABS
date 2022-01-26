#include<stdio.h>
#include<stdlib.h>
struct stack{
int top;
int n;
int a[10000];
};

typedef struct stack* node;

int STACK_FULL(node S)
{
  if(S->top==S->n-1)return 1;
  else return 0;

}
void PUSH(node S,int k)
{
     
    if(!STACK_FULL(S)){
    S->top++;
    S->a[S->top]=k;}
}

void POP(node S)
{
  if(S->top==-1)printf("-1\n");
  else {printf("%d\n",S->a[S->top]);
   S->top--;
}}

void STACK_EMPTY(node S)
{
  if(S->top==-1)printf("-1\n");
  else printf("1\n");

}



int main(){
char ch;
int w=0,k;
struct stack S;
S.top=-1;
scanf("%d",&S.n);
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'i':scanf("%d",&k);
         PUSH(&S,k);
         break;
         
case 'd':POP(&S);
         break;
         
case 'e':STACK_EMPTY(&S);
         break;
         
case 't':w++;
         
}}
return 0;
}
