#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct CGPA{
char ch[10];
float f;
};

void print(struct CGPA* s,int x){
for(int i=0;i<x;i++)
printf("%s %.2f\n",(s+i)->ch,(s+i)->f);
}
void combine(struct CGPA* s,struct CGPA* h,int x,int y){
int i=0,j=0,k,t=0;
while(j<y){
   for(i=0;i<x;i++)
  {
      if((h+j)->f<=(s+i)->f&&++t)
      {
        
           for(k=x;k>i;k--){
             (s+k)->f=(s+k-1)->f;
             strcpy((s+k)->ch,(s+k-1)->ch);
           }
             (s+i)->f=(h+j)->f;
             strcpy((s+i)->ch,(h+j)->ch);
             j++;
             x++;
             i=0;
             t=0;
            }
            
        }
      if(t==0){ 
     (s+x)->f=(h+j)->f;
     strcpy((s+x)->ch,(h+j)->ch);
     x++;
     j++;
       i=0;
     }

}
print(s,x);
}
int main(){
int x,y,i,j;
struct CGPA* s=(struct CGPA*)malloc(10*sizeof(struct CGPA));
struct CGPA* h=(struct CGPA*)malloc(10*sizeof(struct CGPA));


scanf("%d %d",&x,&y);
for(i=0;i<x;i++)
scanf("%s %f",(s+i)->ch,&(s+i)->f);
for(j=0;j<y;j++)
scanf("%s %f",(h+j)->ch,&(h+j)->f);
combine(s,h,x,y);
return 0;
}


