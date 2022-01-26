#include<stdio.h>
#include<stdlib.h>
struct hsp{
	int n;
	int a[100];
	char ch;
};

void swap(int *c,int *d)
{
 int t;
  t=*c;
  *c=*d;
  *d=t;
}
void MIN_HEAPIFY(struct hsp* S,int i)
{
   
   int k1=i;
   int k2=(2*i)+1;
   int k3=(2*i)+2;
 if(k2<S->n && S->a[k1]>S->a[k2]){
     k1=k2;}
 if(k3<S->n && S->a[k1]>S->a[k3]){
     k1=k3;}
 if(k1!=i)
 {
  swap(&S->a[i],&S->a[k1]);   
  MIN_HEAPIFY(S,k1);
 }
}
void MIN_HEAP_INSERT(struct hsp* S,int x)
{
  
   S->a[S->n]=x;
   S->n+=1;
   
   for(int i=(S->n/2)-1;i>=0;i--)
      MIN_HEAPIFY(S,i);
   
   
}
void HEAP_EXTRACT_MIN(struct hsp* S)
{

    if(S->n>0)
    {
      printf("%d\n",S->a[0]);
      swap(&S->a[0],&S->a[S->n-1]);
      S->n-=1;
     MIN_HEAPIFY(S,0);
     }
   else
   {
    printf("-1");
    }
}
void HEAP_MIN(struct hsp* S)
{
  if(S->n>0)
  printf("%d\n",S->a[0]);
  else
  printf("-1");
}

void HEAP_DECREASE_KEY(struct hsp* S,int i,int t)
{
  for(int j=0;j<S->n;j++)
  {
   if(S->a[j]==i)
     S->a[j]=t;
     {
     for(int k=j;k>=0;k--)
      MIN_HEAPIFY(S,k);
     }}
  
}
void heapify(int a[],int n,int i)
{
   
   int k1=i;
   int k2=(2*i)+1;
   int k3=(2*i)+2;
 if(k2<n &&  a[k1]<a[k2]){
     k1=k2;}
 if(k3<n &&  a[k1]<a[k3]){
     k1=k3;}
 if(k1!=i)
 {
  swap(&a[i],&a[k1]);   
  heapify(a,n,k1);
 }
}
void Build_heap(int a[],int n)
{
  for(int i=n/2-1;i>=0;i--)
    heapify(a,n,i);
}
void SORT(int a[],int n)
{
    Build_heap(a,n);
    for(int i=n-1;i>0;i--)
   {
     swap(&a[0],&a[i]);
     heapify(a,i,0);
    }
}

void DISPLAY_QUEUE(struct hsp* S)
{
  int b[S->n];
  for(int i=0;i<S->n;i++)
  {
    b[i]=S->a[i];
   }  
SORT(b,S->n);
for(int i=0;i<S->n;i++){
printf("%d ",b[i]);}

}

int main()
{
  int w=0,x,t,i;
  struct hsp S;
  S.n=0;
while(w<1)
{
scanf("%c",&S.ch);
  switch(S.ch){
   case 'i':scanf("%d",&x);
            MIN_HEAP_INSERT(&S,x);
            break;
   case 'e':HEAP_EXTRACT_MIN(&S);
            break;
   case 'm':HEAP_MIN(&S);
            break;
   case 'c':scanf("%d %d",&i,&t);
            HEAP_DECREASE_KEY(&S,i,t);
            break;
   case 'd':DISPLAY_QUEUE(&S);
            break;        
   case 's':w++;
   }
}
return 0;
}
   

