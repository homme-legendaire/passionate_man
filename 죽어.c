	#pragma warning (disable:4996)
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <time.h>
	#include <Windows.h>
	void SWAP(int x, int y, int z) {
		z = x;
		x = y;
		y = z;
	}
	int sorted[100001];
	int partition(int list[], int left, int right)
	{
		int pivot = list[left], tmp = 0, low = left, high = right + 1;

		do {
			do
				low++;
			while (low <= right && list[low] < pivot);

			do
				high--;
			while (high >= left && list[high] > pivot);
			if (low < high) SWAP(list[low], list[high], tmp);
		} while (low < high);

		SWAP(list[left], list[high], tmp);
		return high;
	}
	void QuickSort(int list[], int left, int right)
	{
		if (left < right)
		{
			int q = partition(list, left, right);
			QuickSort(list, left, q - 1);
			QuickSort(list, q + 1, right);
		}
	}
	void merge(int list[], int left, int mid, int right)
	{
		int i, j, k, l;
		i = left, j = mid + 1; k = left;

		while (i <= mid && j <= right)
		{
			if (list[i] <= list[j])
				sorted[k++] = list[i++];
			else
				sorted[k++] = list[j++];
		}

		if (i > mid)
			for (l = j; l <= right; l++)
				sorted[k++] = list[l];
		else
			for (l = i; l <= right; l++)
				sorted[k++] = list[l];

		for (l = left; l <= right; l++)
			list[l] = sorted[l];
	}
	void mergeSort(int list[], int left, int right)
	{
		int mid;
		if (left < right)
		{
			mid = (left + right) / 2;
			mergeSort(list, left, mid);
			mergeSort(list, mid + 1, right);
			merge(list, left, mid, right);
		}
	}
	int main() {
		int n;
		scanf("%d", &n);
		for (int L = 0; L < 10; L++) {
			int * a = NULL, * b = NULL, * sorted = NULL, cnt = 0;
			LARGE_INTEGER ticksPerSec, start, end, diff;
			a = (int*)malloc(n * sizeof(int));
			b = (int*)malloc(n * sizeof(int));
			sorted = (int*)malloc(n * sizeof(int));
			srand(time(NULL));
			for (int i = 0; i < n; i++) {
				a[i] = rand();
				b[i] = a[i];
			}

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			mergeSort(a, 0, n - 1);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("%.9f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			QuickSort(b, 0, n - 1);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("%.9f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			free(a);
			free(b);
		}
	}