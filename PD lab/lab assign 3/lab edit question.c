#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
int merge(int a[],int b[],int p,int q,int r)
{
int i,j,k,z=0;
i=p;
k=p;
j=q;
while (i <=(q-1) && j <=r)
  { 
    
     if (a[i] <= a[j])    // 4<=5
            b[k++] = a[i++]; 
            
    else {
            b[k++] = a[j++];   
            z+=(q-i); 
        } 
  } 
  
    
    while (i <=(q-1)) {
        b[k++] = a[i++]; 
    } 
 
    while (j <=r) { 
        b[k++] = a[j++];  
    }
    
     for (i = p; i <=r; i++) 
        a[i] = b[i]; 
        
    return z;
} 

int mergesort(int a[],int b[],int l,int h)
{
int z=0;
if(l<h){
  int m=(l+h)/2;
  z+=mergesort(a,b,l,m);
  z+=mergesort(a,b,m+1,h);
  z+=merge(a,b,l,m+1,h);}
  return z;
}


void print(int a[],int n){
int i;
for(i=0;i<n;i++)
  printf("%d ",a[i]);
}
int main()
{
  int *a,*b,n,i,t;
  scanf("%d",&n);
  a=(int*)malloc(n*sizeof(int));
  b=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
 t=mergesort(a,b,0,n-1);
  print(a,n);
  printf("\n%d",t);
  return 0;
}
