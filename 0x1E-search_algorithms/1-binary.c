#include "search_algos.h"
/**
 * _print - prints values
 * @array: array provided as parameter
 * @side_l: side_l index of array
 * @side_r: side_r index of array
 * Return: void
 */
void _print(int *array, int side_l, int side_r)
{

	while (side_l <= side_r)
	{
		if (side_l < side_r)
			printf("%d, ", array[side_l]);
		else
			printf("%d", array[side_l]);
		side_l = side_l + 1;
	}
	printf("\n");
}
/**
 * binary_search - performs binary search
 * @array: Provided array
 * @size: size
 * @value: value
 * Return: index value else-1
 */
int binary_search(int *array, size_t size, int value)
{
	int start, finn, ft;

	if (array == NULL)
		return (-1);

	start = 0;
	finn = (int)size - 1;
	while (start <= finn)
	{
		printf("Searching in array: ");
		_print(array, start, finn);
		ft = (double)((start + finn) / 2);
		if (array[ft] == value)
			return ((int)ft);
		else if (value > array[ft])
			start = ft + 1;
		else
			finn = ft - 1;
	}
	return (-1);
}
