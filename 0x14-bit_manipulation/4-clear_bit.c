#include "main.h"

/**
 * clear_bit - sets value of a bit to 0 at a given index.
 * @n: number  of i
 * @index: starting from 0 of a bit you want
 * Return: 1 if it worked, or -1 if there is error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int k;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	k = ~(1 << index);
	*n = *n & k;

	return (1);
}
