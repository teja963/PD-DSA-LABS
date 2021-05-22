#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
static int c=0;
void insertion(int a[],int n){
int i,k,val;
for(i=1;i<n;i++)
{
    val=a[i];
    k=i-1;
      while(k>=0&&val<a[k])
        {
          a[k+1]=a[k];
          k--;
          c++;
        }
        if(k>=0){
        c++;
        }
  a[k+1]=val;
}
}
void print(int a[],int n){
int i;
for(i=0;i<n;i++)
 printf("%d ",a[i]);
 }
int main(){
int *a,n,i,k;
scanf("%d",&n);
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
scanf("%d",&a[i]);
insertion(a,n);
print(a,n);
printf("\n%d",c);
return 0;
}
