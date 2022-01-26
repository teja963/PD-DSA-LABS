#include<stdio.h>
#include<stdlib.h>
struct stack{
int data;
struct stack* next;
};

typedef struct stack* node;

struct list{
node top;
};

node CREATE_NODE(int k)
{
  node N=(node)malloc(sizeof(struct stack));
  N->data=k;
  N->next=0;
  return N; 
}

void PUSH(struct list* S,node N)
{
  if(S->top==0)S->top=N;
  else{
   N->next=S->top;
    S->top=N;}
}

void POP(struct list* S)
{
  if(S->top==0)printf("-1\n");
  else{
    printf("%d\n",S->top->data);
    S->top=S->top->next;
  }

}

void STACK_EMPTY(struct list* S)
{
  if(S->top==0)printf("-1\n");
  else printf("1\n");

}
int main(){
struct list S;
S.top=0;
node N;
char ch;
int w=0,k;
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'i':scanf("%d",&k);
         N=CREATE_NODE(k);
         PUSH(&S,N);
         break;
         
case 'd':POP(&S);
         break;
         
case 'e':STACK_EMPTY(&S);
         break;
         
case 't':w++;
}}
return 0;
}
         


