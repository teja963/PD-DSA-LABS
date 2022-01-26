#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
//#include<conio.h>
struct node{
char word[500];
struct node* next;
};
typedef struct node* node;

node CREATE(char *s){
node N=(node)malloc(sizeof(struct node));
strcpy(N->word,s);
N->next=NULL;
return N;}

int  REMOVE(char *str1,char substr[][100]){
int k=0,j=0,i=0;
while(str1[k]!='\0')//for splitting sentence
    {
        j=0;
        while(str1[k]!=' '&&str1[k]!='\0')
        {
            substr[i][j]=str1[k];
            k++;
            j++;
        }
        substr[i][j]='\0';
        i++;
        if(str1[k]!='\0')
        {
            k++;
        }        
    }
    int len=i;
    //Removing repeated words same as removing repeated elements in arrays
    for(i=0;i<len;i++)
    {
      for(j=i+1;j<len;)
       {
         if(strcmp(substr[i],substr[j])==0)
          {     
             for(k=j;k<len;k++)
              {
                strcpy(substr[k],substr[k+1]);
              }
                len--;
           }
          else
           {
             j++;
           } 
        }
     }
     return len;
     }

void CONSTRUCT(char a[][100],node* h,int n,int n1){
int i,k=0;
for(i=0;i<n1;i++){
k=strlen(a[i]);
if(h[(k*k)%n]==NULL)h[(k*k)%n]=CREATE(a[i]);
else{
node N;
N=h[(k*k)%n];
while(N!=NULL&&N->next!=NULL)N=N->next; 
N->next=CREATE(a[i]);}}}

void print(node* h,int n){
int i,j,k;
for(i=0;i<n;i++){
printf("%d:",i);
if(h[i]==NULL)printf("null");
else{
k=0;
while(h[i]->next!=NULL){k++;
if(k>=2)printf("-%s",h[i]->word); 
else printf("%s",h[i]->word); h[i]=h[i]->next;}
if(k!=0)printf("-%s",h[i]->word); else printf("%s",h[i]->word);}
printf("\n");}
}
int main(){
int i,j=0,k=0,n;
char s[100],sub[100][100]={0};
scanf("%d",&n);
getchar();
scanf("%[^\n]s",s);
k=REMOVE(s,sub);
node h[n];
for(i=0;i<n;i++)h[i]=NULL;
CONSTRUCT(sub,h,n,k);
print(h,n);
return 0;}


