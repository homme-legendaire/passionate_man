#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int x[9] = { 7,6,5,8,3,5,9,1,6 }, c = 0, root = 0, tmp = 0;
	for (int i = 1; i < 9; i++) {
		c = i;
		while (c != 0) {
			root = (c - 1) / 2;
			if (x[root] < x[c]) {
				tmp = x[root];
				x[root] = x[c];
				x[c] = tmp;
			}
			c = root;
		}
	}
	for (int i = 0; i < 9; i++) {
		printf("%d ", x[i]);
	}
}