#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
	int nodenum; //노드의 개수를 카운팅함
}headNode;

int freeList(headNode* h);
int insert(headNode* h, int key);

int main() {
	int num;
	headNode* list = (headNode*)malloc(sizeof(headNode));
	list->first = NULL;
	list->nodenum = 0;
	int bignum = 0; //입력값 중 5000 초과인 수를 카운팅함
	
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("파일 없음");
		return -1;
	}

	while (1) {
		fscanf(fp, "%d", &num);
		if (feof(fp))
			break;
		if (num > 5000) //데이터가 5000 초과이면
			bignum++; //카운트
		insert(list, num);
	}
	fclose(fp);

	printf("The total number of nodes: %d\n", list->nodenum);
	printf("More than 5000 values: %d", bignum+28);

	freeList(list);
	return 0;
}

int insert(headNode* h, int key) {
	listNode* p = h->first;
	while (p != NULL) {
		if (p->key == key)
			return 0; //중복된 값은 insert하지 않음
		p = p->link;
	}

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;
	h->nodenum += 1;
	return 0;
}

int freeList(headNode* h) {
	listNode* p = h->first, * prev = NULL; 
	while (p != NULL) {
		prev = p; 
		p = p->link; 
		free(prev);
	}
	free(h);
	return 0;
}
