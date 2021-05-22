#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct PCB{
int  id;
struct PCB* next;
char state[50];
};
typedef struct PCB* node;

struct list{
node head;
};

node CREATE(int x)
{
  node N=(node)malloc(sizeof(struct PCB));
  N->id=x;
  N->next=0;
 return N;
}

node LIST_SEARCH(struct list* L,int y)
{
 node x=L->head;
 while (x!=0&&x->id!=y)
    x=x->next;
 
 return x;

}
void LIST_INSERT_FRONT(struct list* L,node N)
{
   N->next=L->head;
    L->head=N;

}
void LIST_DELETE(struct list* L,node T)
{
  node last=L->head;
  if(last!=0&&last->next==T){
  L->head=last->next;
  printf("%d\n",T->id);
  T->id=-1;}
  else{
     while(last->next!=T)
      last=last->next;
  
     last->next=T->next;
     printf("%d\n",T->id);}

}

void UPDATE_STATE(struct list* L,int x,char* S)
{
node T;
T=LIST_SEARCH(L,x);
 strcpy(T->state,S);
}

void LIST_WAITING_PROCESSES(struct list* L)
{
 int c=0;
  node last=L->head;
  while(last->next!=0){
  if(strcmp(last->state,"waiting")==0)printf("%d ",last->id);
  last=last->next;
  c++;}
  
  if(strcmp(last->state,"waiting")==0){
  printf("%d\n",last->id);
  c++;}
  if(c==0)printf("-1");

}

void GET_STATE(struct list*L,node T)
{
printf("%s\n",T->state);
}
int main(){
char ch,st[50];
int w=0,x,y;
node N,T,S;
struct list L;
L.head=0;
while(w<1)
{
   scanf("%c",&ch);
  switch(ch)
  {
  
  case 'i':scanf("%d",&x);
           N=CREATE(x);
           scanf("%s",N->state);
           LIST_INSERT_FRONT(&L,N);
           break;
           
           
  case 'd':scanf("%d",&x);
           T=LIST_SEARCH(&L,x);
           if(LIST_SEARCH(&L,x)!=0)
           LIST_DELETE(&L,T);
           else
           printf("-1\n");
           break;
           

  case 'u':scanf("%d %s",&x,st);
           UPDATE_STATE(&L,x,st);
           break;
           
  case 'l':LIST_WAITING_PROCESSES(&L);
           break;
           
  case 'g':scanf("%d",&x);
           T=LIST_SEARCH(&L,x);
           if(LIST_SEARCH(&L,x)!=0)
           GET_STATE(&L,T);
           else
           printf("-1\n");
           break;
          
  case 'e':w++;

}
}
return 0;
}
