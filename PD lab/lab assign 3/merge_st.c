#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
static int z=0;
void merge(int a[],int p,int q,int r)
{
int n1,n2,i,j,k;
n1=q-p+1;
n2=r-q;
int b[n1],c[n2];
for(i=0;i<n1;i++)
  b[i]=a[p+i];
for(j=0;j<n2;j++)
  c[j]=a[q+j+1];
i=0;
j=0;
k=p;
while (i < n1 && j < n2)
  { 
    
     if (b[i] <= c[j]) 
        { 
            a[k] = b[i]; 
            i++; 
        } 
    else 
        { 
            a[k] = c[j]; 
            j++; 
        } 
        k++; 
        z++;
  } 
  
    
    while (i < n1) {
        a[k] = b[i]; 
        i++; 
        k++;
        z++; 
    } 
  
    
    while (j < n2) { 
        a[k] = c[j]; 
        j++; 
        k++; 
        z++;
    }
} 

void mergesort(int a[],int l,int h)
{
if(l<h){
  int m=(l+h)/2;
  mergesort(a,l,m);
  mergesort(a,m+1,h);
  merge(a,l,m,h);}
}
void print(int a[],int n){
int i;
for(i=0;i<n;i++)
  printf("%d ",a[i]);
}
int main()
{
  int *a,n,i;
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
 mergesort(a,0,n-1);
  print(a,n);
  printf("\n%d",z);
  return 0;
}
