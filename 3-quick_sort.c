#include "sort.h"

/**
* quick_sort - sort array using quick
* @array: array
* @size: Size of array
*
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
	{
		return;
	}
	iterator(array, 0, size - 1);
}

/**
* iterator - recursive function
* @array: array
* @index_lowest: index lowest
* @index_highest: index highest
*
*/

void iterator(int *array, int index_lowest, int index_highest)
{
	int position;

	if (index_lowest < index_highest)
	{
		position = partition(array, index_lowest, index_highest);
		iterator(array, index_lowest, position - 1);
		iterator(array, position + 1, index_highest);
	}
}

/**
* partition - partition scheme for quicksort algorithm
* @array: array
* @index_lowest: index lowest
* @index_highest: index highest
* Return: index of pivot
*
*/

int partition(int *array, int index_lowest, int index_highest)
{
	int index, j, position, temp;
	static int size, k;

	if (k == 0)
		size = index_highest + 1, k++;

	position = array[index_highest];
	index = index_lowest;

	for (j = index_lowest; j < index_highest; j++)
	{
		if (array[j] <= position)
		{
			if (index != j)
			{
				temp = array[index];
				array[index] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			index++;
		}
	}
	if (index != index_highest)
	{
		temp = array[index];
		array[index] = array[index_highest];
		array[index_highest] = temp;
		print_array(array, size);
	}
	return (index);
}
