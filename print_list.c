#include <stdio.h>
#include "sort.h"

/**
 * print_list - A function that prints a list of integers
 *
 * @list: The list of integers to be printed
 */
void print_list(const listint_t *list)
{
    int j;

    j = 0;
    while (list)
    {
        if (j > 0)
            printf(", ");
        printf("%d", list->n);
        ++j;
        list = list->next;
    }
    printf("\n");
}
