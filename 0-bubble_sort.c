#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * --------------------------
 * Prototype: void bubble_sort(int *array, size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void bubble_sort(int *array, size_t size)
{
	size_t pass_index, comparison_index;

	if (array == NULL || size < 2)
		return;

	for (pass_index = 0; pass_index < size - 1; pass_index++)
	{
		/* Each pass ensures the largest element of the */
		/* unsorted portion bubbles up to its correct position */
		for (comparison_index = 0; comparison_index < size - pass_index - 1;
		comparison_index++)
		{
			/* Compare adjacent elements and swap if they are in the wrong order */
			if (array[comparison_index] > array[comparison_index + 1])
			{
				/* Swap the elements */
				swap(&array[comparison_index], &array[comparison_index + 1]);
				/* Print the array after each swap */
				print_array(array, size);
			}
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
