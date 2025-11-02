#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: Prints the array after each time two elements are swapped.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Flag to check if any swap happened in this pass */

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print array after swap */
				print_array(array, size);
				swapped = 1; /* Mark that a swap occurred */
			}
		}

		/* If no swaps occurred in the inner loop, array is sorted */
		if (swapped == 0)
			break;
	}
}
