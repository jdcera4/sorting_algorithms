#include "sort.h"

/**
 * swap - Function that swaps two numbers in an array
 * @major: previous position
 * @minor: next position
 * @array: an array of integers
 * @size: the size of the array
 */
void swap(int *major, int *minor, int *array, size_t size)
{
	int tmp = *major;

	*major = *minor;
	*minor = tmp;
	print_array(array, size);
}
/**
 * selection_sort - Function that sorts an array of integers in
 * ascending order (Selection sort)
 * @array: an array of integers
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minor;
	/*One by one move boundary of unsorted subarray*/
	for (i = 0; i < size - 1; i++)
	{
		/*Find the minimum element in unsorted array*/
		minor = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minor])
			{
				minor = j;
			}
		}
		if (minor != i)
			swap(&array[minor], &array[i], array, size);
	}
}
