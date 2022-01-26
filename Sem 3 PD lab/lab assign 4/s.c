#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct emp{
	char name[10];
	int sal;
	int work;
	int lev;
};
void ins(struct emp *a,int i) {
	scanf("%s\n",a[i].name);
	scanf("%d\n",&a[i].sal);
	scanf("%d\n",&a[i].work);
	scanf("%d",&a[i].lev);
}
void non_incr(struct emp *a,int n) {
	int i;
	for(i=0;i<n;i++) {
		if(a[i].work<8) {
			printf("%s %d\n",a[i].name,a[i].sal);
		}
	}
}
void fi_sal(struct emp *a,int n) {
	int i;
	for(i=0;i<n;i++) {
		if(a[i].work>=8&&a[i].work<10) {
			a[i].sal+=50;
		}
		if(a[i].work==10) {
			a[i].sal+=100;
		}
		if(a[i].work>10){
			a[i].sal+=150;
		}
		printf("%s %d\n",a[i].name,a[i].sal);
	}
}
void wor(struct emp *a,int n,int t) {
	int i;
	for(i=0;i<n;i++) {
		if(a[i].work==t) {
			printf("%s %d\n",a[i].name,a[i].sal);
		}
	}
}

void Computedeductions(struct emp *a,int n,char num){
int i;
for(i=0;i<n;i++){
if(strcmp(a[i].name,name)==0)
{
  if(a[i].lev>5)
  printf("%s %d\n",a[i].name,(a[i].lev-5)*1000);
  else
  printf("%s %d\n",a[i].name,0);
}
}}


int main() {
	char s,num[10];
	int i,j,k=1,t;
	struct emp *a=(struct emp*)malloc(10*sizeof(struct emp));
	i=0;
	while(k) {
	scanf("%c",&s);
	switch(s) {
	        
		case 'r':ins(a,i);
			 i++;
			 break;
		case 'i':non_incr(a,i);
			 break;
		case 'f':fi_sal(a,i);
			 break;
		case 'w':scanf("%d",&t);
			 wor(a,i,t);
			 break;
	        case 'l':scanf("%s",&num);
	                 Computedeductions(a,i,num);
	                 break;
	        case 't':k=0;
	        
	                 
			
		
	}
}
	return 0;
}
