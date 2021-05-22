#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct arr{
char nm[30];
int acc;
float f;
};
typedef struct arr* st;

struct cgpa{
float f;
char nm[50];
int acc;
};

void read_store(st E,int n){
int i;
for(i=0;i<n;i++)
scanf("%d %s %f",&(E+i)->acc,(E+i)->nm,&(E+i)->f);
}

void display(st E,int n){
int i;
for(i=0;i<n;i++)
printf("%d %s %.2f\n",(E+i)->acc,(E+i)->nm,(E+i)->f);
}

int search_record(st E,int n,int j){
int i;
for(i=0;i<n;i++){
if(j==(E+i)->acc)return i;}
return -1;

}

void TURN(int* c,int* d){
int temp;
temp=*c;
*c=*d;
*d=temp;}

void swap(float* c,float* d){
float temp;
temp=*c;
*c=*d;
*d=temp;}

void change(char* a,char* b){
char s[50];
strcpy(s,a);
strcpy(a,b);
strcpy(b,s);}

int PARTITION(struct cgpa* C,int l,int h){
 int p=(C+h)->acc;
  int i=l-1,j;
  for(j=l;j<h;j++)
  {
    if((C+j)->acc<p){
    i++;
    swap(&(C+i)->f,&(C+j)->f);
    TURN(&(C+i)->acc,&(C+j)->acc);
    change((C+i)->nm,(C+j)->nm);
   }
  }
    TURN(&(C+i+1)->acc,&(C+h)->acc);
    change((C+i+1)->nm,(C+h)->nm);
    swap(&(C+i+1)->f,&(C+h)->f);
    return (i+1);
    }


void QUICK_SORT(struct cgpa* C,int l,int h){
if(l<h){
  int pi=PARTITION(C,l,h);
  QUICK_SORT(C,l,pi-1);
  QUICK_SORT(C,pi+1,h);}}




int main(){
int i,j,n,w=0;
char ch;
st E=(st)malloc(100*sizeof(struct arr));
struct cgpa* C=(struct cgpa*)malloc(100*sizeof(struct cgpa));
while(w<1){
scanf("%c",&ch);
switch(ch){
case 'r':scanf("%d",&n);
         read_store(E,n);
         break;
         
case 'd':display(E,n);
         break;
         
case 'f':scanf("%d",&j);
         i=search_record(E,n,j);
         if(i!=-1)printf("i\n");
         else printf("-1\n");
         break;
         
case 's':for(i=0;i<n;i++){
         (C+i)->acc=(E+i)->acc;
         strcpy((C+i)->nm,(E+i)->nm);
         (C+i)->f=(E+i)->f;}
         QUICK_SORT(C,0,n-1);
         for(i=0;i<n;i++)
         printf("%d %s %.2f\n",(C+i)->acc,(C+i)->nm,(C+i)->f);
         break;
         
case 'e':w++;
}}
return 0;
}
