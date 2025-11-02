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

	/* Outer loop: one for each element to be placed correctly */
	for (i = 0; i < size - 1; i++)
	{
		/* Find the index of the minimum element in the unsorted part */
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		/*
		 * If the minimum element is not already at its
		 * correct position (i), swap them.
		 */
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			/* Print the array after the swap */
			print_array(array, size);
		}
	}
}

