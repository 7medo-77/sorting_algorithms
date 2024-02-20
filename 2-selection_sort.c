#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * --------------------------
 * Prototype: void selection_sort(int *array, size_t size);
 * --------------------------
 * @array: The array of integers to be sorted in-place
 * @size: The number of elements within the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void selection_sort(int *array, size_t size)
{
	size_t current_index, next_index, index_of_min_value;

	if (array == NULL || size < 2)
		return;

	/* Iterate over array to move the minimum of the unsorted part to the start */
	for (current_index = 0; current_index < size - 1; current_index++)
	{
		index_of_min_value = current_index;
		/* Find index of minimum value in the unsorted part of the array */
		for (next_index = current_index + 1; next_index < size; next_index++)
		{
			if (array[next_index] < array[index_of_min_value])
			{
				index_of_min_value = next_index;
			}
		}
		/* Swap the found minimum element with */
		/* the first element of the unsorted part */
		if (index_of_min_value != current_index)
		{
			swap(&array[index_of_min_value], &array[current_index]);

			print_array(array, size);
		}
	}
}

/**
 * swap - Swaps two integers
 * --------------------------
 * Prototype: void swap(int *a, int *b)
 * --------------------------
 * @firstElement: First integer
 * @secondElement: Second integer
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void swap(int *firstElement, int *secondElement)
{
	int temporaryVariable = *firstElement;

	*firstElement = *secondElement;
	*secondElement = temporaryVariable;
}
