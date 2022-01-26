#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
int search(char a[],char b[],int m,int n)
{
 int i,j;
 for(i=0;i<=m-n;i++)
 {
    j=0;
  while(j<m&&a[i+j]==b[j])
  {
   j++;
   }
 if(j==n)
 return i;}

 return -1;
   

}
int main(){
char a[1000],b[100];
fgets(a,1000,stdin);
fgets(b,100,stdin);
printf("%d",search(a,b,strlen(a)-1,strlen(b)-1));
}

