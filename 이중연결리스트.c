#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	struct NODE* prev, * next;
	int data;
}NODE;
void getNode(NODE** p) {
	*p = (NODE*)malloc(sizeof(NODE));
}
void add(NODE* H, NODE* T, int r, int e) {
	NODE* p = NULL;
	p = H;
	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	NODE* q = NULL;
	getNode(&q);
	q->data = e;
	(p->prev)->next = q;
	q->prev = p->prev;
	p->prev = q;
	q->next = p;
}
void del(NODE* H, NODE* T, int r) {
	NODE* p = NULL;
	p = H;
	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;
}
void prt(NODE* H, NODE* T) {
	NODE* p = NULL;
	p = H->next;
	while (p != T) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main() {
	int N, i, r, e;
	char str;
	NODE* H = NULL, * T = NULL;
	getNode(&H);
	getNode(&T);
	H->next = T;
	T->prev = H;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%c", &str);
		getchar();
		if (str == 'A') {
			scanf("%d %d", &r, &e);
			getchar();
			add(H, T, r, e);
		}
		else if (str == 'D') {
			scanf("%d", &r);
			getchar();
			del(H, T, r);
		}
		else if (str == 'P') {
			prt(H, T);
		}
	}
}