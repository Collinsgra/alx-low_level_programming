#include "main.h"

/**
 * set_bit - the value of a bit to 1
 * @index: starting from 0 of the bit setted
 * @n: pointer num of i
 * Return: 1 if it worked, or -1 if any errors
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int k;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	k = 1 << index;
	*n = *n | k;

	return (1);
}
