#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void heap(int* x, int a, int N) {
	x[N - 1] = a;
	for (int i = 1; i < N; i++) {
		int c = i;
		while (c != 0) {
			int root = (c - 1) / 2;
			if (x[root] < x[c]) {
				int tmp = x[root];
				x[root] = x[c];
				x[c] = tmp;
			}
			c = root;
		}
	}
}
int main() {
	int x[100] = { 0 }, a, N = 0;
	while (1) {
		scanf("%d", &a);
		if (a == 0) break;
		N++;
		if (N == 1) x[0] = a;
		else heap(x, a, N);
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", x[i]);
	}
}