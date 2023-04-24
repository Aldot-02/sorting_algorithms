#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - The Lomuto partition scheme.
 * @array: The integer array to sort.
 * @lo: The low end of the partition.
 * @hi: The high end of the partition.
 * @size: The size of the integer array.
 *
 * Return: The partition index.
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != hi)
	{
		swap_ints(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursion - The recursive quicksort function.
 * @array: The integer array to sort.
 * @lo: The low end of the partition.
 * @hi: The high end of the partition.
 * @size: The size of the integer array.
 */
void quick_sort_recursion(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quick_sort_recursion(array, lo, p - 1, size);
		quick_sort_recursion(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *             using the quicksort algorithm.
 * @array: The integer array to sort.
 * @size: The size of the integer array.
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}
