#include "sort.h"
#include <stdio.h>

/**
 * find_max - Find the maximum value in an array
 * Return: The maximum value in the array
 * --------------------------
 * prototype: int find_max(int *array, size_t size);
 * --------------------------
 * @array: The array of integers to find the maximum value in
 * @size: The size of the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
*/
int find_max(int *array, size_t size)
{
	size_t index;
	int max_value = 0;

	for (index = 0; index < size; index++)
	{
		if (max_value < array[index])
			max_value = array[index];
	}

	return (max_value);
}


/**
 * initialize_zero_array - Initialize an array of integers
 * Return: A pointer to the array
 * --------------------------
 * prototype: int *initialize_zero_array(int size);
 * --------------------------
 * @size: The size of the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
*/
int *initialize_zero_array(int size)
{
	int *array_ptr = NULL;
	int i;

	array_ptr = malloc((size) * sizeof(int));

	for (i = 0; i < size; i++)
		array_ptr[i] = 0;

	return (array_ptr);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the counting sort algorithm
 * --------------------------
 * Prototype: void counting_sort(int *array, size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * -------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int max_value = 0;
	int *count_array = NULL, *sorted_array = NULL;

	if (size < 2)
		return;
	max_value = find_max(array, size);/* Find the maximum value in the array */
	/* Create and initialize count array */
	count_array = initialize_zero_array(max_value + 1);
	if (!count_array)
		return;
	/* Count occurrences of each value */
	for (i = 0; i < size; i++)
	{
		count_array[array[i]] += 1;
	}
	/* Cumulative count to determine the sorted positions */
	for (i = 0; (int)i < max_value; i++)
	{
		count_array[i + 1] = count_array[i] + count_array[i + 1];
	}
	print_array(count_array, max_value + 1);
	/* Create sorted array */
	sorted_array = malloc(size * sizeof(int));
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	/* Build the sorted array */
	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}
	/* Transfer sorted values back to the original array */
	for (j = 0; j < size; j++)
		array[j] = sorted_array[j];
	free(sorted_array);
	free(count_array);
}
