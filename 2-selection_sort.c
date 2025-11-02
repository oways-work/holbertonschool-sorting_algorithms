#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: Prints the array after each time two elements are swapped.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Outer loop: iterates through the array to place elements */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the current element is the minimum */
		min_idx = i;

		/* Inner loop: find the index of the actual minimum element */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		/*
		 * If the minimum element was found at an index
		 * different from i, then swap them.
		 */
		if (min_idx != i)
		{
			/* Swap the elements */
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			/* Print array after swap */
			print_array(array, size);
		}
	}
}
