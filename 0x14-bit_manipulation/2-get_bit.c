#include "main.h"

/**
 * get_bit - returns the value of bit
 * @n - checking bits
 * Return: value of bit at index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int htm;
	unsigned long int sec;


	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	htm = 1 << index;
	sec = n & htm;
	if (sec == htm)
		return (1);


	return (0);
}
