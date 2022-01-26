#include<stdio.h>
#include<stdlib.h>
struct mhp{
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
void MIN_HEAPIFY(struct mhp* S,int i)
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
void MIN_HEAP_INSERT(struct mhp* S,int x)
{
  
   S->a[S->n]=x;
   S->n+=1;
   
   for(int i=(S->n/2)-1;i>=0;i--)
      MIN_HEAPIFY(S,i);
   
   
}
void HEAP_EXTRACT_MIN(struct mhp* S)
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
void HEAP_MIN(struct mhp* S)
{
  if(S->n>0)
  printf("%d\n",S->a[0]);
  else
  printf("-1");
}

void HEAP_DECREASE_KEY(struct mhp* S,int i,int t)
{
  S->a[i]=t;
  for(int k=i;k>=0;k--)
    MIN_HEAPIFY(S,k);
}


int main()
{
  int w=0,x,t,i;
  struct mhp S;
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
   case 'd':scanf("%d %d",&i,&t);
            HEAP_DECREASE_KEY(&S,i,t);
            break;        
   case 's':w++;
   }
}
return 0;
}
   

