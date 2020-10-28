#include <stdio.h>
#include <stdlib.h>
#define vertexnum 4 /* 정점 개수 */
#define INF 1000000 //무한대 값

/* Graph Data Structure */
typedef struct edge { /* 각 노드 */
	int src; /* 정점 번호 */
	int dest; /* nextnode, edge */
	int weight; /* 가중치 */
} Edge;
typedef struct {
	Edge* edges[vertexnum]; /* 간선 포인터 배열 */
	int edgeCnt; //현재 간선 개수 카운팅
} Graph;
void insertEdge(Graph* g, int u, int v, int w);
void FloydWarshall(Graph* g);

int main(void) {

	/* initialize with test graph */
	Graph* g = (Graph*)malloc(sizeof(Graph));
	for (int i = 0; i < vertexnum; i++) {
		g->edges[i] = (Edge*)malloc(vertexnum * sizeof(Edge));
		for (int j = 0; j < vertexnum; j++) {
			g->edges[i][j].src = i;
			g->edges[i][j].dest = j;
			if (i == j) {
				g->edges[i][j].weight = 0;
			}
			else
				g->edges[i][j].weight = INF;
		}
	}
	g->edgeCnt = 0;

	/* insert edges to graph */
	insertEdge(g, 0, 1, 3);
	insertEdge(g, 0, 3, 5);
	insertEdge(g, 1, 0, 2);
	insertEdge(g, 1, 3, 4);
	insertEdge(g, 2, 1, 1);
	insertEdge(g, 3, 2, 2);

	FloydWarshall(g);

	for (int i = 0; i < vertexnum; i++)
		free(g->edges[i]);
	free(g);
	return 0;
}

void insertEdge(Graph* g, int u, int v, int w) {
	g->edges[u][v].src = u;
	g->edges[u][v].dest = v;
	g->edges[u][v].weight = w;
	g->edgeCnt++;
}

void FloydWarshall(Graph* g) {
	int dist[vertexnum][vertexnum];

	for (int i = 0; i < vertexnum; i++)
		for (int j = 0; j < vertexnum; j++)
			dist[i][j] = g->edges[i][j].weight;

	for (int k = 0; k < vertexnum; k++)
		for (int i = 0; i < vertexnum; i++)
			for (int j = 0; j < vertexnum; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	printf("Floyd-Warshall from vertex 0\n");
	for (int i = 0; i < vertexnum; i++) {
		for (int j = 0; j < vertexnum; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}
