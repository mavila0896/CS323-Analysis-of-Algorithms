// C program to implement dual pivot QuickSort
#include <stdio.h>

int partition(int* arr, int low, int high, int* lp);

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MultiPivotQuickSort(int* arr, int low, int high)
{
	if (low < high) {
		// lp means left pivot, and rp means right pivot.
		int lp, rp; 
		rp = partition(arr, low, high, &lp);
		MultiPivotQuickSort(arr, low, lp - 1);
		MultiPivotQuickSort(arr, lp + 1, rp - 1);
		MultiPivotQuickSort(arr, rp + 1, high);
	}
}

int partition(int* arr, int low, int high, int* lp)
{
	if (arr[low] > arr[high])
		swap(&arr[low], &arr[high]);
	// p is the left pivot, and q is the right pivot.
	int j = low + 1;
	int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
	while (k <= g) {

		// if elements are less than the left pivot
		if (arr[k] < p) {
			swap(&arr[k], &arr[j]);
			j++;
		}

		// if elements are greater than or equal 
		// to the right pivot
		else if (arr[k] >= q) {
			while (arr[g] > q && k < g)
				g--;
			swap(&arr[k], &arr[g]);
			g--;
			if (arr[k] < p) {
				swap(&arr[k], &arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;

	// bring pivots to their appropriate positions.
	swap(&arr[low], &arr[j]);
	swap(&arr[high], &arr[g]);

	// returning the indeces of the pivots.
	*lp = j; // because we cannot return two elements 
			// from a function.

	return g;
}

// Driver code
int main()
{
	int arr[] = { 11, 10, 9, 8, 2, 6, 5, 4, 3, 1 };
	MultiPivotQuickSort(arr, 0, 7);
	printf("Sorted array: ");
	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
