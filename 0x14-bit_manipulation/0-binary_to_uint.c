#include "main.h"

/**
 * binary_to_uint - a function that converts a binary number to an unsigned int
 * @b - is pointing to a string of 0 and 1 chars
 * Return: the converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int k;
	unsigned int l;


	l = 0;
	if (!b)
		return (0);
	for (k = 0; b[k] != '\0'; k++)
	{
		if (b[k] != '0' && b[k] != '1')
			return (0);
	}
	for (k = 0; b[k] != '\0'; k++)
	{
		l <<= 1;
		if (b[k] == '1')
			l += 1;
	}
	return (l);
}
