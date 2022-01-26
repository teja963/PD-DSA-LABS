#include<stdio.h>
#include<stdlib.h>
struct arr{
char M_id[40];
float rat;
};

void store_Db(struct arr* Db,int n)
{
 int i;
   for(i=0;i<n;i++)
      scanf("%s %f",(Db+i)->M_id,&(Db+i)->rat);

}

void list_Db(struct arr* Db,int n)
{
int i;
   for(i=0;i<n;i++)
  printf("%s %.2f\n",(Db+i)->M_id,(Db+i)->rat);
       
}

void popular_rating(struct arr* Db,int n)
{
int i,j,c=0,p1=0,p2=0,p3=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((Db+i)->rat==(Db+j)->rat)c++;
            if(c==2)p1=(Db+i)->rat;
            if(c==3)p2=(Db+i)->rat;
            if(c==4)p3=(Db+i)->rat;
           }
        }
      if(p3>0)printf("%.2f\n",p3);
      if(p2>0)printf("%.2f\n",p2);
      else printf("%.2f\n",p1);       
}

void best_r(struct arr* E,struct arr* H,struct arr* M,int n ,int r){

}

int main()
{
int n,w=0,num;
char ch;
struct arr* E=(struct arr*)malloc(100*sizeof(struct arr));
struct arr* H=(struct arr*)malloc(100*sizeof(struct arr));
struct arr* M=(struct arr*)malloc(100*sizeof(struct arr));
scanf("%d",&n);
while(w<1)
{
scanf("%c",&ch);
switch(ch){
case 's':scanf("%d",&num);
         if(num==1)
         store_Db(E,n);
         if(num==2)
         store_Db(H,n);
         if(num==3)
         store_Db(M,n);
         break;
        
case 'l':scanf("%d",&num);
         if(num==1)
         list_Db(E,n);
         if(num==2)
         list_Db(H,n);
         if(num==3)
         list_Db(M,n);
         break;
         
case 'p':scanf("%d",&num);
         if(num==1)
         popular_rating(E,n);
         if(num==2)
         popular_rating(H,n);
         if(num==3)
         popular_rating(M,n);
         break;
         
case 'b':scanf("%d",&num);
         best_r(E,H,M,n,r);
         break;
              
case 't':w++;
}
}
return 0;
}
         

