#include<stdio.h>
#include<stdlib.h>
int main(){
int *a,*c,i,j,k,n,t;
scanf("%d",&n);
a=(int*)malloc(n*sizeof(int));
c=(int*)calloc(n,sizeof(int));
for(i=0;i<n;i++){
scanf("%d",&a[i]);
c[i]=-1;
}
for(i=0;i<n;i++){
k=0;
for(j=i+1;j<n;j++){
if(a[i]==a[j]){
k++;
if(k+1>n/2)
c[i]=a[i];}
}}
k=c[0];
for(i=0;i<n;i++){
if(k<c[i])
k=c[i];
}
printf("%d",k);

return 0;
}

