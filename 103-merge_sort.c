#include "sort.h"

void merge(int *array, int start, int middle, int end, int *temp);
void merge_sort_recursion(int *array, int start, int end, int *temp);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

/**
 * merge - Merges two sorted arrays
 * --------------------------
 * Prototype: void merge(int *array, int start, int middle, int end,
 * int *temp);
 * --------------------------
 * @array: The array to be sorted
 * @start: Lowest index of split
 * @middle: Middle index of split
 * @end: high index of split
 * @temp: temp array for merging
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void merge(int *array, int start, int middle, int end, int *temp)
{
	int idx1, idx2, mergedIdx;		 /* Indices for traversing arrays */
	int leftSize, rightSize;		 /* Sizes of temporary sub-arrays */
	int debugCounter;				 /* Counter for debugging and printing */
	int tempLeft[1024], tempRight[1024]; /* Temp sub-arrays for left and right*/

	idx1 = start, idx2 = middle + 1, mergedIdx = leftSize = rightSize = 0;
	/* Merge sub-arrays until one is exhausted */
	while (idx1 <= middle && idx2 <= end)
	{
		if (array[idx1] <= array[idx2])
			temp[mergedIdx] = tempLeft[leftSize] =
			    array[idx1],
			mergedIdx++, idx1++, leftSize++;
		else
			temp[mergedIdx] = tempRight[rightSize] =
			    array[idx2],
			mergedIdx++, idx2++, rightSize++;
	}
	/* Copy any remaining elements of the left subarray */
	while (idx1 <= middle)
		temp[mergedIdx] = tempLeft[leftSize] =
		    array[idx1],
		mergedIdx++, idx1++, leftSize++;

	/* Copy any remaining elements of the right subarray */
	while (idx2 <= end)
		temp[mergedIdx] = tempRight[rightSize] =
		    array[idx2],
		mergedIdx++, idx2++, rightSize++;

	/* Print the left sub-array */
	printf("[left]: ");
	for (debugCounter = 0; debugCounter < leftSize; debugCounter++)
		if (debugCounter == 0)
			printf("%d", tempLeft[debugCounter]);
		else
			printf(", %d", tempLeft[debugCounter]);

	/* Print the right sub-array */
	printf("\n[right]: ");
	for (debugCounter = 0; debugCounter < rightSize; debugCounter++)
		if (debugCounter == 0)
			printf("%d", tempRight[debugCounter]);
		else
			printf(", %d", tempRight[debugCounter]);

	/* Copy merged sub-array back to the original array */
	printf("\n[Done]: ");
	for (idx1 = start; idx1 <= end; idx1++)
	{
		array[idx1] = temp[idx1 - start], printf("%d", array[idx1]);
		if (idx1 != end)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * merge_sort_recursion - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * --------------------------
 * Prototype: void merge_sort_recursion(int *array,
 * int start, int end, int *temp);
 * --------------------------
 * @array: The array to be sorted
 * @start: Lowest index of split
 * @end: high index of split
 * @temp: temp array for merging
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void merge_sort_recursion(int *array, int start, int end, int *temp)
{
	int middle;

	if (start < end)
	{
		middle = ((end + start - 1) / 2);

		merge_sort_recursion(array, start, middle, temp);
		merge_sort_recursion(array, middle + 1, end, temp);

		printf("Merging...\n");

		merge(array, start, middle, end, temp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * --------------------------
 * Prototype: void merge_sort(int *array, size_t size);
 * --------------------------
 * @array: The array to be sorted
 * @size: The size of the array
 * --------------------------
 * By Youssef Hassane & Ahmed Abdelhamid
 */

void merge_sort(int *array, size_t size)
{

	int *theBuffer;
	int theSizeOfBuffer = sizeof(int) * (size + 1);

	if (array == NULL || size < 2)
		return;

	theBuffer = malloc(theSizeOfBuffer);

	if (theBuffer == NULL)
		return;

	merge_sort_recursion(array, 0, size - 1, theBuffer);

	free(theBuffer);
}
