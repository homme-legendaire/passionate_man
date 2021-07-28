#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int num = 9, heap[9] = { 7,6,5,8,3,5,9,1,6 };
	for (int i = 1; i < num; i++) {
		int c = i;
		while (c != 0) {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			c = root;
		}
	}
	for (int i = num - 1; i >= 0; i--) {
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		int root = 0;
		int c = 1;
		while (c < i) {
			c = 2 * root + 1;
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			if (heap[root] < heap[c] && c < i) {
				int tmp = heap[root];
				heap[root] = heap[c];
				heap[c] = tmp;
			}
			root = c;
		}
	}
	for (int i = 0; i < num; i++) printf("%d ", heap[i]);
}