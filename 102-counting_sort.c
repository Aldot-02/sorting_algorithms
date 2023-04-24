#include "sort.h"
#include <stdio.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements to allocate
 * @size: size in bytes of each element
 *
 * Return: pointer to the allocated memory,
 * or NULL if nmemb or size is 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *mem;

	if (nmemb == 0 || size == 0)
		return (NULL);

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		mem[i] = '\0';

	return ((void *)mem);
}

/**
 * counting_sort - sorts an array of integers using the counting sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int index, max_val = 0, *count_arr = NULL, *sorted_arr = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* find maximum value in array */
	for (i = 0; i < size; i++)
		if (array[i] > max_val)
			max_val = array[i];

	count_arr = _calloc(max_val + 1, sizeof(int));
	sorted_arr = _calloc(size + 1, sizeof(int));

	/* count the number of times each value appears in array */
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	/* calculate the cumulative sum of count_arr */
	for (index = 1; index <= max_val; index++)
		count_arr[index] += count_arr[index - 1];

	print_array(count_arr, max_val + 1);

	/* build the sorted array */
	for (i = 0; i < size; ++i)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}

	/* copy the sorted array back into the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(count_arr);
}
