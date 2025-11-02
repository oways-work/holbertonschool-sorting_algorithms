#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition (pivot).
 * @size: The full size of the array (for printing).
 *
 * Return: The final index of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;
	int temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			/* Only swap if i and j are different */
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	/*
	 * After the loop, swap the pivot (at array[high])
	 * into its correct position (at array[i]).
	 * Only swap if the pivot is not already in place.
	 */
	if (array[i] != array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - The recursive engine for Quick Sort.
 * @array: The array to sort.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The full size of the array (for printing).
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		/* Find the pivot index */
		pivot_index = lomuto_partition(array, low, high, size);

		/* Recurse on the left sub-array (elements before pivot) */
		quick_sort_recursive(array, low, pivot_index - 1, size);

		/* Recurse on the right sub-array (elements after pivot) */
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: Implements the Lomuto partition scheme.
 * Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/*
	 * We cast size - 1 to int because indices can
	 * be < 0 in the recursive calls (e.g., pivot_index - 1).
	 */
	quick_sort_recursive(array, 0, (int)size - 1, size);
}
