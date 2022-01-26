#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
long long int fib(int n){
if(n==0)return 0;
if(n==1)return 1;
else return fib(n-1)+fib(n-2);
}

int main(){
int n,i;
scanf("%d",&n);
for(i=0;i<=n;i++)
printf("%lld ",fib(i));
return 0;
}
