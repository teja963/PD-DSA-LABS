#include<stdio.h>
#include<stdlib.h>
int w=0;
struct heap{
	int n;
	int a[100000];
};

void heapify(struct heap* S,int i)
{
   
   int k1=i;
   int k2=(2*i)+1;
   int k3=(2*i)+2;
 if(k2<S->n && ++w && S->a[k1]<S->a[k2]){
     k1=k2;}
 if(k3<S->n && ++w && S->a[k1]<S->a[k3]){
     k1=k3;}
 if(k1!=i)
 {
      int t=S->a[i];
     S->a[i]=S->a[k1];
     S->a[k1]=t;  
  heapify(S,k1);
 }
}
void Build_heap(struct heap* S)
{
  for(int i=S->n/2-1;i>=0;i--)
    heapify(S,i);
}
void heap_sort(struct heap* S)
{
    Build_heap(S);
    for(int i=S->n-1;i>0;i--)
   {
     int t=S->a[0];
     S->a[0]=S->a[i];
     S->a[i]=t;
     S->n-=1;
     heapify(S,0);
    }
}


int main()
{
  int i,z;
  struct heap S;
  scanf("%d",&S.n);
  z=S.n;
  for(i=0;i<S.n;i++)
   scanf("%d",&S.a[i]);
  heap_sort(&S);
  for(i=0;i<z;i++)
  printf("%d ",S.a[i]);
  printf("\n%d",w); 
  return 0;
}
