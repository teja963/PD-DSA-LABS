#include<stdio.h>
#include<stdlib.h>
struct Queue{
int head;
int tail;
int n;
int a[10000];
};

typedef struct Queue* node;

int QUEUEFULL(node Q){
  if(Q->tail+1==Q->head||(Q->head==0&&Q->tail==Q->n-1))return 1;
  else return -1;
}

int QUEUEEMPTY(node Q){
  if(Q->head==-1)return 1;
  else return -1;

}
void ENQUEUE(node Q,int k)
{
if(QUEUEFULL(Q)==1)printf("-1\n");
else{
   if(Q->head==-1)Q->head=0;
   if(Q->tail==Q->n-1)Q->tail=0;
   else Q->tail++;
   
   Q->a[Q->tail]=k;
 }
}
void DEQUEUE(node Q)
{
if(QUEUEEMPTY(Q)==1)printf("-1\n");
else{
printf("%d\n",Q->a[Q->head]);
if(Q->head==Q->tail){
Q->head=Q->tail=-1;}
else{
if(Q->head==Q->n-1)Q->head=0;
else Q->head=Q->head+1;
}  
}}
int main(){
struct Queue Q;
Q.head=-1;
Q.tail=-1;
char ch;
int w=0,k;
scanf("%d",&Q.n);
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'i':scanf("%d",&k);
         ENQUEUE(&Q,k);
         break;
         
case 'd':DEQUEUE(&Q);
         break;
         
case 'f':printf("%d\n",-(QUEUEFULL(&Q)));
         break;
         
case 'e':printf("%d\n",-(QUEUEEMPTY(&Q)));
         break;
         
case 't':w++;
}}
return 0;
}
