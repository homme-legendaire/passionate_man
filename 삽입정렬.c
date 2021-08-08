#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int i, j, tmp = 0;
	int x[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 9; i++) {
		j = i;
		while (x[j] > x[j + 1]) {
			tmp = x[j];
			x[j] = x[j + 1];
			x[j + 1] = tmp;
			j--;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", x[i]);
	}
}