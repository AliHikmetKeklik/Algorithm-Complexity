#include <stdio.h>
#include <time.h>
#include <unistd.h>
int selection_sort(int x[], int length) {
	int temp;
	int min;
	for (int i = 0; i < length - 1; i++) {
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (x[j] < x[min]) {
				min = j;
			}
		}
		temp = x[i];
		x[i] = x[min];
		x[min] = temp;
	}
	return *x;
}
int insertion_sort(int x[], int length) {
	int i, key, j;
	for (i = 1; i < length; i++) {
		key = x[i];
		j = i - 1;
		while (j >= 0 && x[j] > key) {
			x[j + 1] = x[j];
			j = j - 1;
		}
		x[j + 1] = key;
	}
	return *x;
}
int bubble_sort(int x[], int length)
{
	int temp;
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (x[j] > x[j + 1]) {
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
	return *x;
}
int quick_sort(int x[], int first, int last) {
	int i, j, pivot, temp;
	if (first < last) {
		pivot = first;
		i = first;
		j = last;
		while (i < j) {
			while (x[i] <= x[pivot] && i < last)
				i++;
			while (x[j] > x[pivot])
				j--;
			if (i < j) {
				temp = x[j];
				x[j] = x[i];
				x[i] = temp;
			}
		}
		temp = x[j];
		x[j] = x[pivot];
		x[pivot] = temp;
		quick_sort(x, first, j - 1);
		quick_sort(x, j + 1, last);
	}
	return *x;
}
void print(int x[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
}
int main() {
	int x[10000];
	int size = sizeof(x) / sizeof(x[0]);
	double time_insertion = 0.0, time_quick = 0.0, time_selection = 0.0, time_bubble = 0.0;
	//	
	printf("Size = %d\n", size);
	clock_t begin_b = clock();
	bubble_sort(x, size);
	clock_t end_b = clock();
	time_bubble += (double)(end_b - begin_b) / CLOCKS_PER_SEC;
	printf("Bubble time = %f\n", time_bubble);
	//
	clock_t begin_i = clock();
	insertion_sort(x, size);
	clock_t end_i = clock();
	time_insertion += (double)(end_i - begin_i) / CLOCKS_PER_SEC;
	printf("Insertion time = %f\n", time_insertion);
	//
	clock_t begin_q = clock();
	quick_sort(x, 0, size - 1);
	clock_t end_q = clock();
	time_quick += (double)(end_q - begin_q) / CLOCKS_PER_SEC;
	printf("Quick time = %f\n", time_quick);
	//
	clock_t begin_s = clock();
	selection_sort(x, size);
	clock_t end_s = clock();
	time_selection += (double)(end_s - begin_s) / CLOCKS_PER_SEC;
	printf("Selection time = %f\n", time_selection);

	return 0;
}
