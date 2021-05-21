#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
struct Edge{ int src,dest,wgt; };
typedef struct Node{ int vertex; struct Node *next; }*node;
typedef struct Graphs{ int V,E; node *list; }*Graph;
Graph create(int v)
{
	Graph graph = (Graph)malloc(sizeof(struct Graphs));	
	graph->V = v;
	graph->list = malloc(v*sizeof(node));
	return graph;
}

node createnode()
{
	node p = (node)malloc(sizeof(struct Node));
	p->next = NULL;
	return p;
}

typedef struct Subset{ int par,rank; }subset;

int find(subset subsets[],int i)	
{
	if(subsets[i].par!=i)subsets[i].par = find(subsets,subsets[i].par);
	return subsets[i].par;
}

void Union(subset subsets[],int x,int y)	
{
	int x_rep = find(subsets,x);
	int y_rep = find(subsets,y);
	if(subsets[x_rep].rank < subsets[y_rep].rank)subsets[x_rep].par = y_rep;
	else if(subsets[x_rep].rank > subsets[y_rep].rank)subsets[y_rep].par = x_rep;
	else
	{
		subsets[y_rep].par = x_rep;
		subsets[x_rep].rank++;
	}
}

void sort(struct Edge edges[],int e)
{
	int min=0,index=0;
	for(int j=0;j<e-1;j++)
	{
		index = j;
		min = edges[j].wgt;
		for(int k=j+1;k<e;k++)
		{
			if(min > edges[k].wgt)
			{
				index = k;
				min = edges[k].wgt;
			}
		}
		int s,d,w;
		s = edges[j].src;
		d = edges[j].dest;
		w = edges[j].wgt;
		edges[j].src = edges[index].src;
		edges[j].dest = edges[index].dest;
		edges[j].wgt = edges[index].wgt;
		edges[index].src = s;
		edges[index].dest = d;
		edges[index].wgt = w;
	}
}

int kruskal(Graph g)
{
	int v=g->V,e=0,flag=1;
	struct Edge edges[g->E],result[v];
	for(int i=0;i<v;i++)
	{
		node p = g->list[i];
		int t;
		scanf("%d",&t);
		while(p)
		{
			int wgt;
			scanf("%d",&wgt);
			for(int j=0;j<e;j++)
				if(edges[j].src==p->vertex&&edges[j].dest==i)
				{
					flag=0;
					break;
				}
			if(flag)
			{
				edges[e].src = i;
				edges[e].dest = p->vertex;
				edges[e].wgt = wgt;
				e++;
				p=p->next;
			}
			else
			{	
				flag = 1;
				p = p->next;
			}
			
		}
	}
	sort(edges,g->E);
	subset subsets[v];
	for(int i=0;i<v;i++)
	{
		subsets[i].par = i;
		subsets[i].rank = 0;
	}
	e = 0;
	int i = 0,sum=0;
	while(e<v-1&&i<g->E)
	{
		int x = find(subsets,edges[i].src);
		int y = find(subsets,edges[i].dest);
		if(x!=y)
		{
			result[e].src =  edges[i].src;
			result[e].dest = edges[i].dest;
			result[e].wgt = edges[i].wgt;
			sum += result[e].wgt;
			Union(subsets,x,y);
			e++;
			i++;
		}
		else
			i++;
	}
	printf("%d\n",sum);
}

int minkey(int key[],bool set[],int V)
{
	int min = INT_MAX,index;
	for(int v=0;v<V;v++)
	{
		if(set[v]==false&&key[v]<min)
		{
			min = key[v];
			index = v;
		}
	}
	return index;
}

int prim(Graph g)
{
	int v=g->V,e=0;
	struct Edge edges[g->E],result[v];
	for(int i=0;i<v;i++)
	{
		node p = g->list[i];
		int t;
		scanf("%d",&t);
		while(p)
		{
			edges[e].src = i;
			edges[e].dest = p->vertex;
			int wgt;
			scanf("%d",&wgt);
			edges[e].wgt = wgt;
			e++;
			p=p->next;
		}
	}
	e = g->E;
	bool set[v];
	int key[v];
	for(int i=0;i<v;i++)
	{
		set[i] = false;
		key[i] = INT_MAX;
	}
	key[0] = 0;
	for(int i=0;i<v-1;i++)
	{
		int u = minkey(key,set,v);
		set[u] = true;
		for(int j=0;j<e;j++)
		{
			if(edges[j].src == u&&set[edges[j].dest]==false&&key[edges[j].dest] > edges[j].wgt)
			{
				key[edges[j].dest] = edges[j].wgt;
			}
		}
	}
	int sum = 0;
	for(int i=0;i<v;i++)
	{
		sum += key[i];
	}
	printf("%d\n",sum);
				
}


int main()
{
	int v,e=0;
	char s;
	scanf("%c",&s);
	scanf("%d",&v);
	Graph graph = create(v);
	for(int i=0;i<v;i++)graph->list[i] = NULL;
	for(int i=0;i<v;i++)
	{
		char c;
		int d,f=0;
		node p;
		do
		{
		        
			scanf("%d%c",&d,&c);
			if(f==0){f++; continue;}
			else 
			{
			   
			   node new = createnode();
			   new->vertex = d;
			if(graph->list[i] == NULL)
			{
				graph->list[i] = new;
				p = graph->list[i];
			}
			else
			{
				p->next = new;
				p = p->next;
			}
			e++;}
		}while(c != '\n');
	}
	
if(s=='a'){graph->E=e/2;  kruskal(graph);}
if(s=='b'){graph->E=e; prim(graph);}
}




