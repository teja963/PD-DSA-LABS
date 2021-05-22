#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>
int bi(int a[],int l,int h,int k)
{
  int m;
   m=(l+h)/2;
   if(l==h)
   {
     if(a[l]==k) return l;
     else return -1;
   }
   else
   {
     if(a[m]==k) return m;
     if(k<a[m]) return bi(a,l,m-1,k);
     else return bi(a,m+1,h,k);
   }
}
int main()
{
int *a,n,i,j,k,t,ans;
scanf("%d",&n);
scanf("%d",&k);
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<k;i++)
{
   scanf("%d",&t);
   ans=bi(a,0,n-1,t);
   for(j=ans-1;j>=0;j--)
   {
     if(a[j]==t)
      ans=j;
   }
printf("%d\n",ans);
}
return 0;
}


