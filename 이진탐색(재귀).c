#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void merge(int* a, int* sorted, int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}
void mergeSort(int* a, int* sorted, int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, sorted, m, middle);
		mergeSort(a, sorted, middle + 1, n);
		merge(a, sorted, m, middle, n);
	}
}
int binarySearch(int* a, int t, int m, int n) {
	if (m > n) return 5;
	int middle = (m + n) / 2;
	if (a[middle] == t) return middle;
	else if (a[middle] > t) return binarySearch(a, t, m, middle - 1);
	else return binarySearch(a, t, middle + 1, n);
}
int main() {
	int N, * a = NULL, * sorted = NULL, M, b, x = 0;
	scanf("%d", &N);
	a = (int*)malloc(N * sizeof(int));
	sorted = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	mergeSort(a, sorted, 0, N - 1);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &b);
		x = binarySearch(a, b, 0, N - 1);
		if (x <= 4) printf("%d ", x);
		else printf("- ");
	}
}