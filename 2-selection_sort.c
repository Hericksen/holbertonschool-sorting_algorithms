#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending order
 *
 * @array: array to sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_i; /* minimum element */
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_i = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_i])
				min_i = j;
		}
		if (min_i != i)
		{
			temp = array[min_i];
			array[min_i] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
