#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int i, j, tmp = 0, x[3];
	for (i = 0; i < 3; i++) {
		scanf("%d", &x[i]);
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (x[i] < x[j]) {
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
		}
	}
	for (i = 0; i < 3; i++) {
		printf("%d ", x[i]);
	}
}