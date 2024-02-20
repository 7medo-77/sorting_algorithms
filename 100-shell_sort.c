#include "sort.h"
#include <unistd.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * --------------------------
 * Prototype: void shell_sort(int *array, size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void shell_sort(int *array, size_t size)
{
	/* Initialize the interval for comparison */
	size_t interval = 1;
	/* Indexes for the elements to be compared */
	ssize_t current, comparer;
	/* Temporary variable to hold the value being sorted */
	int currentValue;
	/* Establish the maximum interval based on the Knuth's sequence */
	while (interval < size / 3)
		interval = interval * 3 + 1;
	if (array == NULL || size < 2)
		return;
	/* Main loop that continues until the interval is reduced to 0 */
	while (interval > 0)
	{
		/* Insertion sort modified to use the current interval */
		for (current = (ssize_t)interval; current < (ssize_t)size; current++)
		{
			/* Temporarily store the value at the current index */
			currentValue = array[current];
			comparer = current;

			/* Shift elements that are greater than the current value */
			while (
				comparer >= (ssize_t)interval &&
				array[comparer - interval] > currentValue
			)
			{
				array[comparer] = array[comparer - interval];
				comparer -= interval;
			}

			/* Place the current value in its correct location within the interval */
			array[comparer] = currentValue;
		}
		/* Display the array after each interval pass */
		print_array(array, size);
		/* Reduce the interval for the next pass */
		interval = (interval - 1) / 3;
	}
}
