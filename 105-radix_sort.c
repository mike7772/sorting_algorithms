#include "sort.h"

/**
 * radix_sort - sort array with radix method
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
*/

void radix_sort(int *array, size_t size)
{
	int i, j, x, y, cantRep, max, div = 1, t = 0;
	int buckets[10][1000];

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];

	for (i = 0; i < 10; ++i)
		for (j = 0; j < 1000; ++j)
			buckets[i][j] = -1;

	cantRep = getCantRep(max);

	for (i = 0; i < cantRep; ++i)
	{
		for (j = 0; j < (int) size; ++j)
		{
			for (y = 0; buckets[(array[j] / div) % 10][y] != -1; y++)
				;
			buckets[(array[j] / div) % 10][y] = array[j];
		}
		div = div * 10;
		t = 0;
		for (x = 0; x < 10; ++x)
		{
			for (y = 0; buckets[x][y] != -1; y++)
			{
				array[t] = buckets[x][y];
				buckets[x][y] = -1;
				t++;
			}
		}
		print_array(array, size);
	}
}

/**
 * getCantRep - Returns the number of digits of the largest number in the array
 * @num: The largest number
 *
 * Return: Number of digits of the num
*/

int getCantRep(int num)
{
	bool flag = true;
	int cont = 0;

	while (flag)
	{
		flag = false;
		if (num > 0)
		{
			num = num / 10;
			cont++;
			flag = true;
		}
	}
	return (cont);
}
