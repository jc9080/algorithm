#include <stdio.h>

// Quick Sort: O(nlog)

void quickSort(int* array, int start, int end);

int main(void)
{
	int number = 10;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	quickSort(array, 0, number - 1);

	for (int i = 0; i < number; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}

void quickSort(int* array, int start, int end)
{
	if (start >= end) //if there is only one element in a subarray, return
	{
		return;
	}

	int pivot = start;
	int i = start + 1; //starts from the most left element
	int j = end; //starts from the most right element
	int temp;

	while (i <= j) //while i is less than j, meaning not crossing each other
	{
		while (i <= end && array[i] <= array[pivot]) //until we find an element that is greater than pivot value, go right
		{
			i++;
		}
		while (j > start && array[j] >= array[pivot]) //until we find an element that is smaller than pivot value, go left
		{
			j--;
		}
		if (i > j)
		{
			temp = array[j];
			array[j] = array[pivot];
			array[pivot] = temp;
		}
		else
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	quickSort(array, start, j - 1);
	quickSort(array, j + 1, end);
}