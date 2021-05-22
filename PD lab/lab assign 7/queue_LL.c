#include<stdio.h>
#include<stdlib.h>
struct Queue{
int data;
struct Queue* next;
};

typedef struct Queue* node;

struct list{
node head;
node tail;
};

node CREATE_NODE(int k)
{
  node N=(node)malloc(sizeof(struct Queue)); 
  N->data=k;
  N->next=0;
  return N;
}

int QUEUEEMPTY(struct list* Q)
{
  if(Q->head==0&&Q->tail==0)return 1;
  else return -1;

}

void ENQUEUE(struct list* Q,node N)
{
  node last=Q->head;
 if(Q->head==0&&Q->tail==0){
 Q->head=N;
 Q->tail=N;}
 else{
 while(last->next!=0)
 last=last->next;
 
 last->next=N;
 Q->tail=N;}

}

void DEQUEUE(struct list* Q)
{
  if(QUEUEEMPTY(Q)==1)printf("-1\n");
  else{
  if(Q->head==Q->tail){
  printf("%d\n",Q->head->data);
  Q->head=Q->tail=0;}
  else{
   printf("%d\n",Q->head->data);
   Q->head=Q->head->next;
}}
}
int main(){
char ch;
int w=0,k;
node N;
struct list Q;
Q.head=Q.tail=0;
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'i':scanf("%d",&k);
         N=CREATE_NODE(k);
         ENQUEUE(&Q,N);
         break;
         
case 'd':DEQUEUE(&Q);
         break;
         
case 'e':printf("%d\n",-(QUEUEEMPTY(&Q)));
         break;
         
case 't':w++;
}}
return 0;
}
