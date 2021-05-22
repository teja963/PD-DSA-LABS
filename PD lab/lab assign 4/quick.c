#include<stdio.h>
#include<stdlib.h>
int t=0;   
int swap(int *c,int *d){
int temp;
temp=*c;
*c=*d;
*d=temp;}

int partition(int a[],int l,int h)
{
  int p=a[h];
  int i=l-1;
  for(int j=l;j<h;j++)
  {
   
   if(++t&&a[j]<p)
   {
    i++;
    swap(&a[i],&a[j]);
   }
  }
    swap(&a[i+1],&a[h]);
    return (i+1);
    }



int quick_sort(int a[],int l,int h)
{
  if(l<h)
  {
   int p;
   p=partition(a,l,h);
   quick_sort(a,l,p-1);
   quick_sort(a,p+1,h);
   }
}
    
int main()
{
 int *a,i,j,k,n;
 scanf("%d",&n);
 a=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 quick_sort(a,0,n-1);
 for(i=0;i<n;i++){
 printf("%d ",a[i]);}
 printf("\n%d",t);
 return 0;
}

