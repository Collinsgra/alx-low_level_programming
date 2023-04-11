#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip to get from one number to another
 * @n: the first number
 * @m: the second number
 * Return: number of bits that needs to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int nairobi, kenya;
	unsigned int p, k;

	p = 0;
	kenya  = 1;
	nairobi = n ^ m;
	for (k = 0; k < (sizeof(unsigned long int) * 8); k++)
	{
		if (kenya == (nairobi & kenya))
			p++;
		kenya <<= 1;
	}

	return (p);
}
