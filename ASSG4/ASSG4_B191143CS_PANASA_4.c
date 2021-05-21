#include<stdio.h>
#include<stdlib.h>
 
#define MAX 250
 
#define initial 1
#define waiting 2
#define visited 3
 
int n,v1;    
int adj[MAX][MAX];
int state[MAX]; 
void create_graph();
void BF_Traversal();
void DF_Traversal();
void BFS(int v);
void DFS(int v);
int G[250][250],vis[250]; 
 
int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
 
int main()
{
	create_graph();
	BF_Traversal();
	return 0;
}

void BF_Traversal()
{
	int v;
	char x;
	for(v=0; v<n; v++) 
		state[v] = initial;
	
	//printf("Enter Start Vertex for BFS: \n");
	scanf("%c", &x);
	v1=x-'a'+1;
	BFS(v1);
}
 
void BFS(int v)
{
	int i;
	
	insert_queue(v);
	state[v] = waiting;
	
	while(!isEmpty_queue())
	{
		v = delete_queue( );
		printf("%c ",v+'a'-1);
		state[v] = visited;
		
		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && state[i] == initial) 
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}

void DF_Traversal()
{
        int v;
        
        for(v=0;v<n;v++)
               vis[v]=0;
               
        DFS(v1);
        
}

void DFS(int v)
{
    int j;
	printf("%d ",v);
    vis[v]=1;
	
	for(j=0;j<n;j++)
       if(!vis[j]&&G[v][j]==1)
            DFS(j);

 }
 
void insert_queue(int vertex)
{
	if(rear != MAX-1)
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		//printf("Queue Underflow\n");
		exit(1);
	}
	
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
 
void create_graph()
{
        char x,y;
	int count,max_edge,origin,destin,v;
	scanf("%d %d",&v,&n);
	max_edge = n;
 
	for(count=1; count<=max_edge; count++)
	{
		scanf("%c %c",&x,&y);
		origin=x-'a'+1;
		destin=y-'a'+1;
		if(origin>=n || destin>=n || origin<0 || destin<0||origin>=v)
		{
			//printf("Invalid edge!\n");
			count--;
		}
		else
		{
			adj[origin][destin] = 1;
			G[origin][destin]=1;
		}
	}
}
