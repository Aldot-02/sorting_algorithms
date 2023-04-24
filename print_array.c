#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - A function that prints an array of integers
 *
 * @array: The array for being printed
 * @size: The Nbr of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t j;

    j = 0;
    while (array && j < size)
    {
        if (j > 0)
            printf(", ");
        printf("%d", array[j]);
        ++j;
    }
    printf("\n");
}
