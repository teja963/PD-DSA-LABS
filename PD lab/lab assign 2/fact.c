#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
long long int fact(int n){
if(n==0)return 1;
else return n*fact(n-1);}
int main(){
long long int n;
scanf("%lld",&n);
printf("%lld",fact(n));
return 0;}

