#include "sort.h"
/**
* swap - swap the integer
*
* @array: array to print
* @size: size of the array
* @low: integer to swap
* @high: integer to swap
* Return: index of the pivot element
*/
void swap(int low, int high, int *array, size_t size)
{
	int temp = array[low];

	if (array[low] != array[high])
	{
	array[low] = array[high];
	array[high] = temp;
	print_array(array, size);
	}
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
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(i, j, array, size);
			i++;
		}
	}
		swap(i, high, array, size);

	return (i);
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
