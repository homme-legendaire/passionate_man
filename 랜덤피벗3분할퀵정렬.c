#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int a, b;
int findPivot(int* L, int l, int r) {
	srand(time(NULL));
	int i = l + (rand() % (r - l + 1));
	return i;
}
void partition(int* A, int start, int end) {
	int k = findPivot(A, start, end);
	int tmp = A[k];
	int c = 0;
	A[k] = A[end];
	A[end] = tmp;
	int pivot = A[end];
	int rose = start;
	for (int i = start; i < end; i++) {
		if (A[i] < pivot) {
			tmp = A[rose];
			A[rose] = A[i];
			A[i] = tmp;
			rose++;
		}
	}
	tmp = A[rose];
	A[rose] = A[end];
	A[end] = tmp;
	a = c = rose;
	while (1) {
		if (A[c] != A[a]) {
			b = c - 1;
			break;
		}
		c++;
	}
}
void QuickSort(int* A, int start, int end) {
	if (start < end) {
		partition(A, start, end);
		QuickSort(A, start, a - 1);
		QuickSort(A, b + 1, end);
	}
}
int main() {
	int n, * a = NULL, cnt = 0;
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf(" %d", a[i]);
	}
}