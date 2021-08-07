#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	int data, id;
	struct NODE* lc, * rc;
}NODE;
void getNode(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
void Edge(int e, int id, NODE* curr, NODE* left, NODE* right) {
	curr->data = e;
	curr->id = id;
	curr->lc = left;
	curr->rc = right;
}
void preorder(NODE* p) {
	if (p != NULL) {
		printf("%d ", p->data);
		if (p->lc != NULL) preorder(p->lc);
		if (p->rc != NULL) preorder(p->rc);
	}
}
void inorder(NODE* p) {
	if (p != NULL) {
		if (p->lc != NULL) inorder(p->lc);
		printf("%d ", p->data);
		if (p->rc != NULL) inorder(p->rc);
	}
}
void postorder(NODE* p) {
	if (p != NULL) {
		if (p->lc != NULL) postorder(p->lc);
		if (p->rc != NULL) postorder(p->rc);
		printf("%d ", p->data);
	}
}
void finder(NODE* p, int N, int M) {
	if (p != NULL) {
		if (p->id == M) {
			if (N == 1) preorder(p);
			if (N == 2) inorder(p);
			if (N == 3) postorder(p);
		}
		finder(p->lc, N, M);
		finder(p->rc, N, M);
	}
}
void main() {
	NODE* F1, * F2, * F3, * F4, * F5, * F6, * F7, * F8;
	int N, M;
	getNode(&F1);
	getNode(&F2);
	getNode(&F3);
	getNode(&F4);
	getNode(&F5);
	getNode(&F6);
	getNode(&F7);
	getNode(&F8);
	Edge(20, 1, F1, F2, F3);
	Edge(30, 2, F2, F4, F5);
	Edge(50, 3, F3, NULL, F6);
	Edge(70, 4, F4, NULL, NULL);
	Edge(90, 5, F5, NULL, NULL);
	Edge(120, 6, F6, F7, F8);
	Edge(130, 7, F7, NULL, NULL);
	Edge(80, 8, F8, NULL, NULL);
	scanf("%d %d", &N, &M);
	if (M > 0 && M < 9) finder(F1, N, M);
	else printf("-1");
}