#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
int rev(long int n){
 int r=0;
while(n>0){
r=r*10+n%10;
n/=10;}
return r;}
int main(){
long int n;
scanf("%ld",&n);
printf("%d",rev(n));
return 0;
}
