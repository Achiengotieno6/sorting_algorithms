#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass, i;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (pass = 0; pass < size - 1; pass++)
	{
		/* checks for swapping that occurs*/
		swapped = 0;
		for (i = 0; i < size - pass - 1; i++)
		{
			/*compare adjacent elements and swap */
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
					array[i + 1] = temp;
					swapped = 1;
					print_array(array, size);
			}
		}
		if (swapped == 0)
			return;
	}
}
