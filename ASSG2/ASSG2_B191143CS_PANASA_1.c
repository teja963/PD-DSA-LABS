#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void QUA_PROB(int *h,int n,int c1,int c2){
int i,j,k,w=0,l;
char c;
while(w<1){
scanf("%c",&c);
switch(c){
case 'i':scanf("%d",&k);
         if(h[k%n]==-1)h[k%n]=k;
         else{
         for(i=0;i<n;i++){
         if(h[(k%n+c1*i+c2*i*i)%n]==-1){ h[(k%n+c1*i+c2*i*i)%n]=k; i=n+1; }}}
         break;
         
case 'p':for(i=0;i<n;i++){
         if(h[i]==-1)printf("%d ()\n",i);
         else printf("%d (%d)\n",i,h[i]);}
         break;
         
case 's':scanf("%d",&k);
         l=0;
         for(i=0;i<n;i++)if(h[i]==k){printf("1\n"); l++;}
         if(l==0)printf("-1\n");
         break;
         
case 'd':scanf("%d",&k);
         for(i=0;i<n;i++)if(h[i]==k)h[i]=-1;
         break;
        
case 't':w++;}}}

void DOUBLE_PROB(int *h,int n,int r){
int i,j,k,w=0,l;
char c;
while(w<1){
scanf("%c",&c);
switch(c){
case 'i':scanf("%d",&k);
         if(h[k%n]==-1)h[k%n]=k;
         else{
         for(i=0;i<n;i++){
         if(h[(k%n+i*(r-(k%r)))%n]==-1){h[(k%n+i*(r-(k%r)))%n]=k; i=n+1;}}}
         break;

case 'p':for(i=0;i<n;i++){
         if(h[i]==-1)printf("%d ()\n",i);
         else printf("%d (%d)\n",i,h[i]);}
         break;
         
case 's':scanf("%d",&k);
         l=0;
         for(i=0;i<n;i++)if(h[i]==k){printf("1\n"); l++;}
         if(l==0)printf("-1\n");
         break;
         
case 'd':scanf("%d",&k);
         for(i=0;i<n;i++)if(h[i]==k)h[i]=-1;
         break;
        
case 't':w++;}}}
  
int main(){
int i,j,k,n,c1,c2;
char c,d;
scanf("%c",&c);
scanf("%d",&n);
int h[n];
for(i=0;i<n;i++)h[i]=-1;
if(c=='a'){
scanf("%d %d",&c1,&c2);
QUA_PROB(h,n,c1,c2);}
if(c=='b'){
int s[n];
for(i=0;i<n;i++)s[i]=0;
for(i=2;i<=n;i++){
if(s[i])continue;
for(j=2*i;j<=n;j+=i)s[j]=i;}
for(i=n-1;i>=2;i--)if(s[i]==0){k=i; i=0;}
DOUBLE_PROB(h,n,k);}
return 0;}
