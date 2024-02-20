#include "sort.h"
#include <unistd.h>

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * --------------------------
 * Prototype: void quick_sort(int *array, size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - Recursively sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * --------------------------
 * Prototype: void quick_sort_recursion(int *array, ssize_t low, ssize_t high,
 * size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the original array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */
void quick_sort_recursion(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot_index = partition(array, low, high, size);

		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - Partitions an array of integers in ascending order
 * using the Quick sort algorithm
 * Return: the index of the pivot
 * --------------------------
 * Prototype: size_t partition(int *array, ssize_t low, ssize_t high,
 * size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @low: The lowest index of the partitions
 * @high: The highest index of the partition
 * @size: The size of the original array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
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
