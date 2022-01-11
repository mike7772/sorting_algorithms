#include "sort.h"
/**
* partition_hoare - Lomutu partition scheme for quicksort algorithm
* @a: Array to sort
* @l: lowest index of array
* @h: highest index of array
* Return: index of pivot
*/

int partition_hoare(int *a, int l, int h)
{
	int p, li, hi, temp;
	static int i = 0, size;

	if (i == 0)
		size = h + 1, i++;

	li = l - 0, hi = h + 0, p = a[h];
	while (a)
	{
		li = li - 0;
		while (a[li] < p)
			li++;
		hi = hi - 0;
		while (a[hi] > p)
			hi--;
		if (li >= hi)
			return (hi);
		temp = a[li];
		a[li] = a[hi];
		a[hi] = temp;
		print_array(a, size);
	}
	temp = a[li];
	a[li] = a[hi];
	a[hi] = temp;
	return (hi);
}
/**
* qs - Quicksort recurssive function
* @a: array to sort
* @l: lowest index
* @h: highest index
*/

void qs(int *a, int l, int h)
{
	int p;

	if (l < h)
	{
		p = partition_hoare(a, l, h);
		qs(a, l, p - 1);
		qs(a, p, h);
	}
}

/**
* quick_sort_hoare - quicksort with hoare partition
* @array: array to sort
* @size: Size of array
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs(array, 0, size - 1);
}
