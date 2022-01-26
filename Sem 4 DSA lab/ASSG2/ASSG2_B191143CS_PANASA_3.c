#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>
struct node{
char string[500];
struct node* next;
};
typedef struct node* node;

node CREATE(char *s){
node N=(node)malloc(sizeof(struct node));
strcpy(N->string,s);
N->next=NULL;
return N;}

int POWER(char *s){
int i,j=0,a1=0,b1=0,c1=0,d1=0,e1=0,f1=0,g1=0,h1=0;
for(i=0;i<strlen(s);i++){
if(s[i]=='a'&&a1==0){j+=pow(2,0); a1++;}
if(s[i]=='b'&&b1==0){j+=pow(2,1); b1++;}
if(s[i]=='c'&&c1==0){j+=pow(2,2); c1++;}
if(s[i]=='d'&&d1==0){j+=pow(2,3); d1++;}
if(s[i]=='e'&&e1==0){j+=pow(2,4); e1++;}
if(s[i]=='f'&&f1==0){j+=pow(2,5); f1++;}
if(s[i]=='g'&&g1==0){j+=pow(2,6); g1++;}
if(s[i]=='h'&&h1==0){j+=pow(2,7); h1++;}
}return j;}
void CONSTRUCT(node *h,char a[][100],int n){
int i,j,k,p;
for(i=0;i<n;i++){
p=POWER(a[i]);
if(h[p]==NULL)h[p]=CREATE(a[i]);
else{
node N=h[p];
while(N!=NULL&&N->next!=NULL)N=N->next;
N->next=CREATE(a[i]);}}}

void print(node *h,int n){
int i;
for(i=0;i<255;i++){
if(h[i]!=NULL){
node N=h[i];
while(N->next!=NULL){printf("%s ",N->string); N=N->next;}
printf("%s\n",N->string);
}
}}

void sort(char a[][100],int n){
int i,j,k;
char t[100];
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(strcmp(a[i],a[j])>0){
strcpy(t,a[i]);
strcpy(a[i],a[j]);
strcpy(a[j],t);}}}}

int main(){
int i,j,k,n;
char a[100][100];
scanf("%d",&n);
node h[255];
for(i=0;i<255;i++)h[i]=NULL;
for(i=0;i<n;i++)scanf("%s",a[i]);
sort(a,n);
CONSTRUCT(h,a,n);
print(h,n);
return 0;}




