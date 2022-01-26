#include<stdio.h>
#include<stdlib.h>
void print(float L1[],int x)
{
for(int i=0;i<x;i++)
printf("%.2f ",L1[i]);
}
int  combine(float L1[],float L2[],int x,int y){
int i=0,j=0,k,t=0;
while(j<y){
   for(i=0;i<x;i++)
  {
      if(L2[j]<=L1[i]&&++t)
      {
        
           for(k=x;k>i;k--)
             L1[k]=L1[k-1];
           
             L1[i]=L2[j++];
             x++;
             i=0;
             t=0;
            }
            
        }
      if(t==0){ 
     L1[x++]=L2[j++];
       i=0;
     }

}
print(L1,x);
}
int main(){
float L1[50],L2[50];
int x,y,i,j,k;
scanf("%d %d",&x,&y);
for(i=0;i<x;i++)
scanf("%f",&L1[i]);
for(j=0;j<y;j++)
scanf("%f",&L2[j]);
combine(L1,L2,x,y);
return 0;
}

