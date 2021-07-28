#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sort(int* data, int start, int end) {
	int p = 0, i = 0, j = 0, tmp = 0;
	if (start >= end) return;
	p = start;
	i = start + 1;
	j = end;
	while (i <= j) {
		while (data[i] <= data[p]) i++;
		while (data[j] >= data[p] && j > start) j--;
		if (i>j){
			tmp = data[j];
			data[j] = data[p];
			data[p] = tmp;
		}
		else {
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
	}
	sort(data, start, j - 1);
	sort(data, j + 1, end);
}
int main() {
	int data[10] = { 5,3,4,9,10,2,8,1,7,6 }, num = 10;
	sort(data, 0, num - 1);
	for (int i = 0; i < num; i++) printf(" %d", data[i]);
}