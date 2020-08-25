#include "sorting.h"

int* quicksort(int* arr, int l, int r) {
	if (l < r) {
		int pi = partition(arr, l, r);

		quicksort(arr, l, pi - 1);
		quicksort(arr, pi + 1, r);
	}
	return arr;
}
int partition(int* arr, int l, int r) {
	int pivot = arr[r];
	int temp = 0;
	int i = l - 1;

	for (int j = l; j <= r - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;

	return i + 1;
}