#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Edge {int src, dest, weight;};
struct Graph {int V, E; struct Edge* edge;};
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*)malloc(E*sizeof(struct Edge));
	return graph;
}

int isNegCycleBellmanFord(struct Graph* graph,int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			return 1;
	}

	return 0;
}

int main()
{
	int V,E,i,j;
	scanf("%d %d",&V,&E);
	struct Graph* graph = createGraph(V, E);
	for(i=0;i<E;i++){
	scanf("%d %d %d",&(graph->edge[i].src),&(graph->edge[i].dest),&(graph->edge[i].weight));}
	if (isNegCycleBellmanFord(graph, 0))printf("1\n");
	else printf("-1\n");
	return 0;
}

