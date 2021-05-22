#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(){
int i,j=0,n,k,*a;
scanf("%d",&n);
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
scanf("%d",&k);
for(i=0;i<n;i++)
{
if(k==a[i]){
printf("%d ",i);
j++; }
}
if(j==0)
printf("-1");
return 0;}
