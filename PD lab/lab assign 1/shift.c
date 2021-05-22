#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int main(){
int *a,*b,i,j,k,n;
scanf("%d %d",&n,&k);
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
scanf("%d",&a[i]);
if(k>n)
k=k%n;
b=(int*)malloc(k*sizeof(int));
for(i=n-k,j=0;i<n,j<k;i++,j++)
b[j]=a[i];
for(i=n-1;i>=k;i--)
a[i]=a[i-k];
for(i=0;i<k;i++)
a[i]=b[i];
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}

