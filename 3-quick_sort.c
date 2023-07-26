#include "sort.h"

/**
 * swap_int - swaps two elements in an array
 * @a: the first element
 * @b: the second element
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * quicksort_helper - Recursive function that performs quick sort
 * @array: Pointer to the array to be sorted
 * @size: the size of the array
 * @low: Index of the first element in the partition.
 * @high: Index of the last element in the partition
 */

void quicksort_helper(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, size, low, high);
		quicksort_helper(array, low, size, pivot_idx - 1);
		quicksort_helper(array, size, pivot_idx + 1, high);
	}
}

/**
 * lomuto_partition - scheme for Quick sort
 * @array: Pointer to the array to be sorted.
 * @size: the size of the array
 * @low: Index of the first element in the partition.
 * @high: Index of the last element in the partition.
 * Return: Index of the pivot element after partitioning.
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_int(&array[i], &array[j]);

				print_array(array, size);
			}
			i++;
		}
	}
	/*place pivot at correct position*/
	if (pivot != array[i])
	{
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_helper(array, size, 0, size - 1);
}
