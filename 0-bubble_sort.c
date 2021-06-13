#include "sort.h"
/**
 * swap - Function that swaps two numbers in an array
 * @major: previous position
 * @minor: next position
 */
void swap(int *major, int *minor)
{
	int tmp = *major;

	*major = *minor;
	*minor = tmp;
}

/**
 * bubble_sort - Function that sorts an array of integers in
 * ascending order(Bubble sort)
 * @array: an array of integers
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
}
