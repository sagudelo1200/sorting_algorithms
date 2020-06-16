#include "sort.h"

/**
 * find_max_rad - get value max of array
 * @array: pointer to list
 * @size: size of array
 * Return: max value
 */

int find_max_rad(int *array, size_t size)
{
	int max_value = 0;

	while (size--)
		if (array[size] > max_value)
			max_value = array[size];
	return (max_value);
}

/**
 * rad_sort - radix sort
 * @array: pointer to list
 * @size: size of array
 * @num: significant digit
 * Return: None
 */

void rad_sort(int *array, size_t size, int num)
{
	int *tmp = NULL;
	int i;
	int *aux = NULL;

	aux = malloc(size * sizeof(int));
	if (aux == NULL)
		return;

	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		aux[i] = 0;

	for (i = 0; i < (int)size; i++)
	{
		aux[(array[i] / num) % 10]++;
	}

	for (i = 1; i < (int)size; i++)
	{
		aux[i] += aux[i - 1];
	}

	for (i = (int)size - 1; i >= 0; i--)
	{
		tmp[aux[(array[i] / num) % 10] - 1] = array[i];
		aux[(array[i] / num) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = tmp[i];
	}

	free(tmp);
	free(aux);
}

/**
 * radix_sort - sort array with radix method
 * @array: pointer to list
 * @size: size of array
 * Return: None
 */

void radix_sort(int *array, size_t size)
{
	int max, i;

	if (!array || size <= 1)
		return;

	max = find_max_rad(array, size);

	for (i = 1; max / i > 0; i *= 10)
	{
		rad_sort(array, size, i);
		print_array(array, size);
	}
}
