#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int power(int x,int p){
if(p==0)return 1;
else 
return x*power(x,p-1);}
int main(){
int n,i,s=0;
scanf("%d",&n);
i=0;
while(n>0){
s+=(n%10)*power(2,i);
n/=10;
i++;}
printf("%d",s);
return 0;
}
