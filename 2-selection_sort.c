#include "sort.h"
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
			if (array[j] < array[minor])
			minor = j;
		/*Swap the found minimum element with the first element*/
		swap(&array[minor], &array[i]);
		print_array(array, size);
	}
}
