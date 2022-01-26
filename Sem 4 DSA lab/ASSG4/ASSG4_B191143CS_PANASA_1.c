#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void convert(long long int a[][1000],int n){
int i,j,k;
for(i=0;i<n;i++){
   printf("%d ",i);
 for(j=0;j<n;j++){
    if(a[i][j]==1)printf("%d ",j);}
    printf("\n");}}
       
int main(){
long long int a[1000][1000];
int i,j,n;
scanf("%d",&n);
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%lld",&a[i][j]);
}}
convert(a,n);
return 0;} 

