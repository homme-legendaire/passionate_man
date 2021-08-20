#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	int index, distance;
	struct NODE* next;
}NODE;
void push(NODE* root, int index, int distance) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}
void prt(NODE* root) {
	NODE* p = root->next;
	while (p != NULL) {
		printf("%d(거리: %d) ", p->index, p->distance);
		p = p->next;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	NODE** root = NULL;
	root = (NODE**)malloc(n * sizeof(NODE*));
	for (int i = 1; i <= n; i++) {
		root[i] = (NODE*)malloc(sizeof(NODE));
		root[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		push(root[x], y, distance);
	}
	for (int i = 1; i <= n; i++) {
		printf("원소 [%d]: ", i);
		prt(root[i]);
		printf("\n");
	}
}