#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int gcd(int a,int b){
if(a==0)return b;
if(b==0)return a;
else return gcd(b,a%b);}
int main(){
int n1,n2;
scanf("%d %d",&n1,&n2);
if(n1==0&&n2==0)
printf("-1");
else
printf("%d",gcd(n1,n2));
return 0;
}
