#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int key,rank;
	struct NODE *parent,*next;
}node;

int k=0;
int count1=0;
int count2=0;
int count3=0;
int count4=0;

node *find(node *x)
{
	if(k == 1)count1++;
	else if(k == 2)count2++;
	if(x->parent == x)return x;
	else return find(x->parent);
}



node *Union_1(node *x, node *y)
{
	x = find(x);
	y = find(y);
	if(x == y)return x;
	else{y->parent = x; return x;}
}

node makeset(node rl, int n)
{
	node *x = (node *)malloc(sizeof(node));
	x->parent = x;
	x->key = n;
	x->rank = 0;
	x->next = NULL;
	rl.next = x;
	return rl;
}


node *Union_2(node *x, node *y)
{
	x = find(x);
	y = find(y);
	if(x == y)
		return x;
	else
	{
		if(x->rank >= y->rank)
		{
			y->parent = x;
			if(x->rank == y->rank)
				x->rank += 1;
			return x;
		}
		else
		{
			x->parent = y;
			return y;
		}
	}
}

node *find_path_comp(node *x)
{
	if(k == 3)count3++;
	else if(k == 4)count4++;
	if(x->parent != x)x->parent = find_path_comp(x->parent);
	return x->parent;
}



node *Union_3(node *x, node *y)
{
	x = find_path_comp(x);
	y = find_path_comp(y);
	if(x == y)
                return x;
        else
        {
                y->parent = x;
                return x;
        }
}

node *Union_4(node *x, node *y)
{
        x = find_path_comp(x);
        y = find_path_comp(y);
        if(x == y)
                return x;
        else
        {
                if(x->rank >= y->rank)
                {
                        y->parent = x;
                        if(x->rank == y->rank)
                                x->rank += 1;
                        return x;
                }
                else
                {
                        x->parent = y;
                        return y;
                }
        }
}

int main()
{
	char ch;
	int a,b,t=0;
	node rl1[50],rl2[50],rl3[50],rl4[50];
	for(int i=0;i<50;i++)
	{
		rl1[i].next = NULL;
		rl2[i].next = NULL;
		rl3[i].next = NULL;
		rl4[i].next = NULL;
	}
	node *x,*y,*z,*w;
	while(t<1)
	{
		scanf("%c",&ch);
		switch(ch){

		case 'm':scanf("%d",&a);
			if(rl1[a].next == NULL){
			rl1[a] = makeset(rl1[a],a);
			rl2[a] = makeset(rl2[a],a);
			rl3[a] = makeset(rl3[a],a);
			rl4[a] = makeset(rl4[a],a);
			printf("%d\n",rl1[a].next->key);
			}
			else printf("-1\n");
			break;
			
		
		case 'u':scanf("%d %d",&a,&b);
			if(rl1[a].next == NULL || rl1[b].next == NULL)printf("-1 -1 -1 -1\n");
			else
			{
				k = 1;
				x = Union_1(rl1[a].next,rl1[b].next);
				k = 2;
				y = Union_2(rl2[a].next,rl2[b].next);
				k = 3;
				z = Union_3(rl3[a].next,rl3[b].next);
				k = 4;
				w = Union_4(rl4[a].next,rl4[b].next);
				printf("%d %d %d %d\n",x->key,y->key,z->key,w->key);
			}
			break;
		
		case 'f':scanf("%d",&a);
			if(rl1[a].next == NULL)printf("-1 -1 -1 -1\n");
			else
			{
				k = 1;
				x = find(rl1[a].next);
				k = 2;
				y = find(rl2[a].next);
				k = 3;
				z = find_path_comp(rl3[a].next);
				k = 4;
				w = find_path_comp(rl4[a].next);
				printf("%d %d %d %d\n",x->key,y->key,z->key,w->key);
			}
			break;
		
		case 's':
		
			printf("%d %d %d %d\n",count1,count2,count3,count4);
			t++;
		
	}
}
return 0;}
