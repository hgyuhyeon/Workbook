/* Bellman-ford Algorithm */
#include <stdio.h>
#include <stdlib.h>
#define vertexnum 5 /* 정점 개수 */
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
void BellmanFord(Graph* g);


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
	insertEdge(g, 0, 1, -4);
	insertEdge(g, 0, 2, 5);
	insertEdge(g, 0, 3, 2);
	insertEdge(g, 0, 4, 3);
	insertEdge(g, 1, 3, -1);
	insertEdge(g, 2, 3, -7);
	insertEdge(g, 3, 4, 6);
	insertEdge(g, 4, 3, -4);

	/* Debug */
	//for (int i = 0; i < vertexnum; i++) {
	//	for (int j = 0; j < vertexnum; j++) {
	//		printf("%d ", g->edges[i][j].weight);
	//	}
	//	printf("\n");
	//}

	BellmanFord(g); //정점 0에서부터 탐색함

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

void BellmanFord(Graph* g) {
	/* distance 배열 생성 및 초기화 */
	int* dist = (int*)malloc(vertexnum * sizeof(int));
	for (int i = 0; i < vertexnum; i++)
		if (i == 0)
			dist[i] = 0; //start vertex = 0
		else
			dist[i] = INF; //infinity

	/* start Bellman-ford algotithm */
	for (int i = 0; i < vertexnum - 1; i++) {
		for (int j = 0; j < vertexnum; j++) {
			if (i == j)
				continue; //자기자신은 pass
			int a = g->edges[i][j].src; //시작점
			int b = g->edges[i][j].dest; //도착점
			/* Debug */
			//printf("src = %d, dest = %d, weight = %d, ... ", a, b, g->edges[i][j].weight);
			/* 시작점이 무한대 값이 아니면서 && 시작점까지의 최단 거리+가중치 < 도착점의 가중치 */
			if (dist[a] != INF && dist[a] + g->edges[i][j].weight < dist[b])
				dist[b] = dist[a] + g->edges[i][j].weight;
			/* Debug */
			//printf("dist[%d]: %d\n", b, dist[b]);

		}
	}
		
	/* find negative weight cycle */
	for (int i = 0; i < vertexnum; i++) {
		for (int j = 0; j < vertexnum; j++) {
			int a = g->edges[i][j].src; //시작점
			int b = g->edges[i][j].dest; //도착점
			if (dist[a] != INF && dist[a] + g->edges[i][j].weight < dist[b]) {
				printf("Negative weight cycle detected.\n");
				break;
			}
		}
	}

	/* Print */
	printf("Bellman-ford from vertex 0\n");
	for (int k = 0; k < vertexnum; k++)
		printf("dist[%d]: %d\n", k, dist[k]);

	free(dist);
}
