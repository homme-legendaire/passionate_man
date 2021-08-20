#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int arr[100][100], visit[100];
void DFS(int data,int vertex) {
	visit[data] = 1;
	printf("%d ", data);
	for (int i = 1; i <= vertex; i++) {
		if (visit[i] == 0 && arr[data][i] == 1) {
			DFS(i, vertex);
		}
	}
}
int main() {
	int vertex, number;
	int one, two;
	scanf("%d %d", &number, &vertex);
	for (int i = 0; i < number; i++) {
		scanf("%d %d", &one, &two);
		arr[one][two] = arr[two][one] = 1;
	}
	DFS(0, vertex);
}