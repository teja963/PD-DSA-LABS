#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int main(){
int *a,*b,*c,i,j,k,n1,n2,n3;
scanf("%d",&n1);
a=(int*)malloc(n1*sizeof(int));
for(i=0;i<n1;i++)
scanf("%d",&a[i]);
scanf("%d",&n2);
b=(int*)malloc(n2*sizeof(int));
for(i=0;i<n2;i++)
scanf("%d",&b[i]);
n3=n1+n2;
c=(int*)calloc(n3,sizeof(int));
i=0;
while(i<n3){
while(i<n1){
c[i]=a[i];
i++;}
c[i]=b[i-n1];
i++;}
for(i=0;i<n3;i++)
{
 for(j=i+1;j<n3;j++)
 {
   if(c[i]==c[j]){
     for(k=j;k<n3;k++){
      c[k]=c[k+1];}
    n3--;
    j--;     }
              }
}
for(i=0;i<n3;i++){
for(j=i+1;j<n3;j++){
if(c[i]>c[j]){
k=c[i];
c[i]=c[j];
c[j]=k;}}}
for(i=0;i<n3;i++)
printf("%d ",c[i]);
return 0;

}

