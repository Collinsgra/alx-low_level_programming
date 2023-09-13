#include "search_algos.h"
/**
 * linear_search - performs linear search
 * @array: Provided array
 * @size: Provided size
 * @value: value
 * Return: index of value, else -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array || size == 0)
		return (-1);

	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}

	return (-1);
}
