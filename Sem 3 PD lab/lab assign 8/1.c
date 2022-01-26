#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
int top;
int n;
char a[1000];
};
typedef struct stack* node;
int ISOPREAND(char ch){return (ch>='a'&&ch<='z');}
int ISEMPTY(node S){return (S->top==-1);}
int ISFULL(node S){return (S->top==S->n-1);}
void PUSH(node S,char ch){S->a[++S->top]=ch;}
char POP(node S){return S->a[S->top--];}
int PRI(char ch)
{switch(ch)
{
   case '+':
   case '-':return 1;
   case '*':
   case '/':return 2;
   case '^':return 3;
} return -1;}

char *INFIX_POSTFIX(char *ch)
{
   int i,k;
   struct stack S;
   S.top=-1;
   S.n=strlen(ch);
   for(i=0,k=-1;ch[i];i++)
   {
     if(ISOPREAND(ch[i]))ch[++k]=ch[i];                     //2
     else if(ch[i]=='(')PUSH(&S,ch[i]);                     //3
     else if(ch[i]==')')
     {
       while(!ISEMPTY(&S)&&S.a[S.top]!='(')                //4
       ch[++k]=POP(&S);
       POP(&S);
      }
    else
   {
   while(!ISEMPTY(&S)&&PRI(ch[i])<=PRI(S.a[S.top]))
    ch[++k]=POP(&S);                                             //6 7
    PUSH(&S,ch[i]);
     }
     
   }
   while(!ISEMPTY(&S)){                                  //8
   ch[++k]=S.a[S.top--];}
   ch[++k]='\0';
   return ch;
}
int main(){
char s[500],ch[500];
scanf("%[^\n]",ch);
strcpy(s,INFIX_POSTFIX(ch));
printf("%s",s);
return 0;
}
