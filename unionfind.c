#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getParent(int* parent, int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent, parent[x]);
}
int unionParent(int* parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
int findParent(int* parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}
int main() {
	int parent[11];
	for (int i = 0; i < 11; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("%d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 6);
	printf("%d", findParent(parent, 1, 5));
}