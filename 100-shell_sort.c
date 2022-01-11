#include "sort.h"

/**
 * shell_sort - sort array with shell method
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
*/

void shell_sort(int *array, size_t size)
{
	int in = 0, out = 0, range = 1, aux = 0;

	if (!array || size < 2)
		return;

	while (range < (int) size / 3)
		range = range * 3 + 1;

	while (range > 0)
	{
		out = range;
		while (out < (int) size)
		{
			aux = array[out];
			in = out;

			while (in > range - 1 && array[in - range] >= aux)
			{
				array[in] = array[in - range];
				in = in - range;
			}

			array[in] = aux;
			out++;
		}
		print_array(array, size);
		range = (range - 1) / 3;
	}
}
