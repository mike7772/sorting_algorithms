#include "sort.h"

/**
 * counting_sort - sort array with counting method
 * @array: array to sort
 * @size: size of array
 *
 * Return: nothing
*/

void counting_sort(int *array, size_t size)
{
	int max = 0, i = 1;
	int *count = NULL, *arr_tmp = NULL;

	if (!array || size < 2)
		return;
	max = array[0];
	while (i < (int) size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	arr_tmp = malloc(sizeof(int) * size);
	if (!arr_tmp)
		return;
	count = malloc(sizeof(int) * max + 1);
	if (!count)
	{
		free(arr_tmp);
		return;
	}

	for (i = 0; i <= max; ++i)
		count[i] = 0;
	for (i = 0; i < (int) size; ++i)
		count[array[i]]++;
	for (i = 1; i <= max; ++i)
		count[i] = count[i - 1] + count[i];
	print_array(count, max + 1);
	for (i = 0; i < (int) size; ++i)
	{
		arr_tmp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int) size; ++i)
		array[i] = arr_tmp[i];

	free(count);
	free(arr_tmp);
	count = arr_tmp = NULL;
}
