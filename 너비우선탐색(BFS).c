#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int front, rear;
int map[100][100], queue[100], visit[100];
void BFS(int v, int vertex) {
	int i;
	visit[v] = 1;
	printf("%d ", v);
	queue[rear++] = v;
	while (front < rear) {
		v = queue[front++];
		for (i = 1; i <= vertex; i++) {
			if (map[v][i] == 1 && !visit[i]) {
				visit[i] = 1;
				printf("%d ", i);
				queue[rear++] = i;
			}
		}
	}
}
int main() {
	int vertex, number;
	int one, two;
	scanf("%d %d", &number, &vertex);
	for (int i = 0; i < number; i++) {
		scanf("%d %d", &one, &two);
		map[one][two] = map[two][one] = 1;
	}
	BFS(0, vertex);
}