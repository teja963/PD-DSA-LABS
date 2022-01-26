#include<stdio.h>
#include<stdlib.h>
struct Linkedlist{
int data;
struct Linkedlist* next;
};
typedef struct Linkedlist* node;

struct list{
node head;
};

node CREATE(int x)
{
  node N=(node)malloc(sizeof(struct Linkedlist));
  N->data=x;
  N->next=0;
 return N;
}

node LIST_SEARCH(struct list* L,int y)
{
 node x=L->head;
 while (x!=0&&x->data!=y)
    x=x->next;
 
 return x;

}
void LIST_INSERT_FRONT(struct list* L,node N)
{
  N->next=L->head;
  L->head=N;
 
}

void LIST_INSERT_TAIL(struct list* L,node N)
{
   node last=L->head;
   if(L->head==0)L->head=N;
   else{
   while(last->next!=0)
     last=last->next;
     
     last->next=N;
   }
}

void LIST_INSERT_AFTER(struct list* L,node N,node T)
{

 N->next=T->next;
 T->next=N;

}

void LIST_INSERT_BEFORE(struct list* L,node N,node T)
{
  node last=L->head;
  if(last!=0&&last->next==T->next){
  N->next=T;
  L->head=N;
  }
  
  else{
  N->next=T;
  while(last->next!=N->next)
    last=last->next;
    
  last->next=N;
}}

void LIST_DELETE(struct list* L,node T)
{
  node last=L->head;
  if(last!=0&&last==T){
  L->head=last->next;
  printf("%d\n",T->data);
  free(last);
  }
  else{
 while(last->next!=T)
  last=last->next;
  
  last->next=T->next;
 printf("%d\n",T->data);
}
}

void LIST_DEL_FIRST(struct list* L)
{
  node last=L->head;
  if(last!=0)
  {
    L->head=last->next;
    printf("%d\n",last->data);
    }
    else printf("-1");
    

}

void LIST_DEL_LAST(struct list* L)
{

 if(L->head==0)
 printf("-1\n");
 else{
  node last=L->head;
  node temp=L->head;
  while(last->next!=0)
   last=last->next;
   
   
   if(last->next==temp->next){
     printf("%d\n",last->data);
     last->data=-1;}
   else
   {
  while(temp->next!=last)
    temp=temp->next;
    
     temp->next=0;
     printf("%d ",last->data);
    }
       
    }
}

int main(){
char ch;
int w=0,x,y;
node N,T;
struct list L;
L.head=0;
while(w<1)
{
   scanf("%c",&ch);
  switch(ch)
  {
  
  case 'f':scanf("%d",&x);
           N=CREATE(x);
           LIST_INSERT_FRONT(&L,N);
           break;
           
  case 't':scanf("%d",&x);
           N=CREATE(x);
           LIST_INSERT_TAIL(&L,N);
           break;
           
  case 'a':scanf("%d %d",&x,&y);
           N=CREATE(x);
           T=LIST_SEARCH(&L,y);
           LIST_INSERT_AFTER(&L,N,T);
           break;
           
  case 'b':scanf("%d %d",&x,&y);
           N=CREATE(x);
           T=LIST_SEARCH(&L,y);
           LIST_INSERT_BEFORE(&L,N,T);
           break;
           
  case 'd':scanf("%d",&x);
           T=LIST_SEARCH(&L,x);
           if(LIST_SEARCH(&L,x)!=0)
           LIST_DELETE(&L,T);
           else
           printf("-1\n");
           break;
           
  case 'i':LIST_DEL_FIRST(&L);
           break;
           
  case 'l':LIST_DEL_LAST(&L);
           break;
        
  case 's':scanf("%d",&x);
           if(LIST_SEARCH(&L,x)==0)
           printf("-1\n");
           else
           printf("1\n");
           break;
  case 'e':w++;

}
}
return 0;
}
