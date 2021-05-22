#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
int top;
char s[1000];
};

void ISPALINDROME(struct stack* S)
{
  int i,n,c=-1;
  n=strlen(S->s)/2-1;
  S->top=strlen(S->s)-1;
  for(i=0;i<=n;i++){
     if(S->s[i]==S->s[S->top--])c++;}
    if(c==n)printf("1");
    else printf("0");

}

int main(){
struct stack S;
S.top=-1;
scanf("%s",S.s);
ISPALINDROME(&S);
return 0;
}

