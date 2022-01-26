#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct queue_linkedlist{
char id[20];
char name[10];
int n;
float size;
struct queue_linkedlist* next;
};

typedef struct queue_linkedlist* node;

struct list{
node head;
node tail;
};

node CREATE(char *s1,char *s2,int pages,float tot){
node N=(node)malloc(sizeof(struct queue_linkedlist));
strcpy(N->id,s1);
strcpy(N->name,s2);
N->n=pages;
N->size=tot;
N->next=0;
return N;}

void ADD_REQUEST(struct list* Q,node N)
{
   node last=Q->head;
  if(Q->head==0&&Q->tail==0){
  Q->head=N;
  Q->tail=N;}
  else{
   while(last->next!=0)
   last=last->next;
  
   last->next=N;
  Q->tail=N;
  }
}

void EXTRACT_NEXTREQUEST(struct list* Q)
{
  if(Q->head==0&&Q->tail==0)printf("-1\n");
  else{
  if(Q->head==Q->tail){
  printf("%s\n",Q->head->id);
  Q->head=Q->tail=0;}
  else{
  printf("%s\n",Q->head->id);
  Q->head=Q->head->next;
}}
}

void LIST_REQUEST(struct list* Q){
node last=Q->head;
if(Q->head==0&&Q->tail==0)printf("-1\n");
else{
while(last->next!=0){
printf("%s %s %d %.1f\n",last->id,last->name,last->n,last->size);
last=last->next;}
printf("%s %s %d %.1f\n",last->id,last->name,last->n,last->size);
}}
int main(){
char ch,s1[20],s2[10];
int w=0,n;
float size;
struct list Q;
node N;
Q.head=Q.tail=0;
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'a':scanf("%s %s %d %f",s1,s2,&n,&size);
         N=CREATE(s1,s2,n,size);
         ADD_REQUEST(&Q,N);
         break;
         
case 'e':EXTRACT_NEXTREQUEST(&Q);
         break;
         
case 'l':LIST_REQUEST(&Q);
         break;
         
case 't':w++;
}}
return 0;
}
