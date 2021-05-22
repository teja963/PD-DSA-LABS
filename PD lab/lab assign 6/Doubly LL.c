#include<stdio.h>
#include<stdlib.h>
struct DoublyLinkedlist{
int data;
struct DoublyLinkedlist* next;
struct DoublyLinkedlist* prev;
};
typedef struct DoublyLinkedlist* node;

struct list{
node head;
};

node CREATE(int x)
{
  node N=(node)malloc(sizeof(struct DoublyLinkedlist));
  N->data=x;
  N->next=0;
  N->prev=0;
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
  N->prev=T;
 
}

void LIST_INSERT_BEFORE(struct list* L,node N,node T)
{
 if(T->prev==0){
 T->prev=N;
 N->next=T;
 L->head=N;}
 else{
 node last=L->head;
 N->next=T;
 while(last->next!=T)
 last=last->next;
 
 last->next=N;
 T->prev=N;
 N->prev=last;
  }
}

void LIST_DELETE(struct list* L,node T)
{
 node last=L->head;
 node k=T->next;
 
 if(T->prev==0&&T->next==0&&L->head==T){
 printf("%d\n",T->data);
 T->data=-1;}
 
 else{
      if(T->next==0)
     {
        while(last->next!=T)
         last=last->next;
   
         last->next=0;
        printf("%d\n",T->data);
   
      }
  
     else{
         if(T->prev!=0&&T->next!=0)
        {
          while(last->next!=T)
          last=last->next;
 
            last->next=T->next;
               printf("%d\n",T->data);
            if(k!=0){
           k->prev=last;}
   
        }
  
         else
            {
             L->head=T->next;
              k->prev=0;
            printf("%d\n",T->data);
            }
          }
}}

void LIST_DEL_FIRST(struct list* L)
{
  node last=L->head;
  if(last!=0&&last->next==0){
  printf("%d\n",last->data);
  last->data=-1;}
  else{
  L->head=last->next;
  printf("%d\n",last->data);
  last=last->next;
  last->prev=0;
  }

}

void LIST_DEL_LAST(struct list* L)
{
  node last=L->head;
  node temp=L->head;
  if(last==0)printf("-1\n");
  else{
  if(last->prev==0&&last->next==0){printf("%d\n",last->data);last->data=-1;}
  else{
  while(last->next!=0)
  last=last->next;
  
  while(temp->next!=last)
  temp=temp->next;
  
  temp->next=last->next;
  printf("%d\n",last->data);}
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
