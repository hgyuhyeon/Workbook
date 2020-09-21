#include <stdio.h>
#define N 100


/* Adjacency Matrix */
int n;
int adj_matrix[N][N];
//정점 u와 v 의 인접체크
void Matrixuv(int u, int v) {
	if ((adj_matrix[u][v] == 1) || (adj_matrix[v][u] == 1))
		printf("정점 %d와 정점 %d는 인접함\n", u, v);
	else
		printf("정점 %d와 정점 %d는 인접하지 않음\n", u, v);
}
//정점 u와 인접한 모든 정점 탐색
void MatrixAd(int u) {
	printf("정점 %d와 인접한 모든 정점: ", u);
	for (int i = 0; i < N; i++) {
		if ((adj_matrix[u][i] == 1) || (adj_matrix[i][u] == 1))
			printf("%d", i);
	}
	printf("\n");
}
//깊이
void Matrixdeg(int u) {
	int degree = 0;
	for (int i = 0; i < N; i++) {
		if ((adj_matrix[u][i] == 1) || (adj_matrix[i][u] == 1))
			degree++;
	}
	printf("차수: %d", degree);
}


/* Adjacency List */
typedef struct _node { /* 각 노드 */
	int vertex;
	struct _node* next;
} Node;
typedef struct {
	Node* graph[N]; /* Node 포인터 배열 */
	int vertexCnt; /* 정점 개수 */
	int edgeCnt; /* 간선 개수 */
} adj_list;

adj_list* G;

//정점 u와 v 의 인접체크
void Listuv(int u, int v) {
	Node* p = G->graph[u];
	while (p->next != NULL) {
		if (p->next == v) {
			printf("정점 %d와 정점 %d는 인접함\n", u, v);
			break;
		}
		p = p->next;
	}
	printf("정점 %d와 정점 %d는 인접하지 않음\n", u, v);
}
//정점 u와 인접한 모든 정점 탐색
void ListAd(int u) {
	Node* p = G->graph[u];
	while (p->next != NULL) {
		printf("%d ", p->vertex);
		p = p->next;
	}
}
//깊이
void Listdeg(int u) {
	Node* p = G->graph[u];
	int degree = 0;
	while (p->next != NULL) {
		degree++;
		p = p->next;
	}
	printf("차수: %d", degree);
}

int main(void) {
	printf("인접 행렬 / 인접 리스트 ");
}
