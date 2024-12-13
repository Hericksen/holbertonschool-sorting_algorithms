#include "sort.h"
/**
* swap - swap the integer
*
* @array: array to print
* @size: size of the array
* @xp: integer to swap
* @yp: integer to swap
* Return: index of the pivot element
*/
void swap(int *xp, int *yp, int *array, size_t size)
{
	int temp = *xp;

	*xp = *yp;
	*yp = temp;
	print_array(array, size);
}
/**
* lomuto_partition - partition schema ( choosing pivot )
*
* @array: array to print
* @low: smallest element
* @high: biggest element
* @size: size of the array
* Return: index of the pivot element
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j;

	if (low < 0 || high < 0 || low >= (int)size || high >= (int)size)
		return (low);

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j], array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high], array, size);
	}

	return (i + 1);
}
/**
* quick_sort_custom - function that sorts an array of integers in ascending
*
* @array: array to print
* @low: variable for custom quick sort
* @high: variable for custom quick sort
* @size: size of the array
*/
void quick_sort_custom(int *array, int low, int high, size_t size)
{
	if (low < 0 || high < 0 || low >= (int)size || high >= (int)size)
		return;

	if (low < high)
	{
		int idx = lomuto_partition(array, low, high, size);

		quick_sort_custom(array, low, idx - 1, size);
		quick_sort_custom(array, idx + 1, high, size);
	}
}
/**
* quick_sort - function that sorts an array of integers in ascending
*
* @array: array to print
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_custom(array, 0, size - 1, size);

}
