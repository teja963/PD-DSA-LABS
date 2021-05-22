#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack{
int top;
int n;
int a[1000];
};
typedef struct stack* node;
void PUSH(node S,int ch){S->a[++S->top]=ch;}
int POP(node S){return S->a[S->top--];}
int EVALULATE_POSTFIX(char *ch)
{
  struct stack S;
   S.top=-1;
   S.n=strlen(ch);
   int i;
   for(i=0;ch[i];i++)
   {
     if(ch[i]==' ')continue;
     else if(isdigit(ch[i]))
     {
       int num=0;
     while(isdigit(ch[i])){
      num=num*10+(int)(ch[i]-'0');
             i++;} 
          i--;
        PUSH(&S,num);
     }
      else{
       int l1=POP(&S);
       int l2=POP(&S);
       switch(ch[i]){
       case '+':PUSH(&S,l2+l1);break;
       case '-':PUSH(&S,l2-l1);break;
       case '*':PUSH(&S,l2*l1);break;
       case '/':PUSH(&S,l2/l1);break;}
       }}
       return POP(&S);
       }
int main(){
int i;
char ch[100];
scanf("%[^\n]",ch);
printf("%d",EVALULATE_POSTFIX(ch));
return 0;
}

