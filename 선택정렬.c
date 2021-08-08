#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int i, j, tmp = 0, index = 0, min = 9999;
	int x[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (x[j] < min) {
				min = x[j];
				index = j;
			}
		}
		tmp = x[index];
		x[index] = x[i];
		x[i] = tmp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", x[i]);
	}
}