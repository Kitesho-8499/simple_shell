#include "shell.h"

/**
 * unsignedNumberToString - As the name implies
 * @number: Unsigned number
 * @base: base of number
 * @buf: pointer
 * Return: Nothing
 */

void unsignedNumberToString(uint64_t number, int base, char *buf)
{
	char tmp[65];
	int rem, i = 0, j = 0;

	if (number == 0)
	{
		*buf++ = '0';
		*buf = '\0';
		return;
	}

	while (number)
	{
		rem = number % base;
		if (rem >= 10)
			tmp[i++] = 'a' + (rem - 10);
		else
			tmp[i++] = '0' + rem;

		number /= base;
	}
	for (j = i - 1; j >= 0; j--)
		*buf++ = tmp[j];
	*buf = '\0';
}

/**
 * numberToString - As the name implies
 * @number: Unsigned number
 * @base: base of number
 * @buf: pointer
 * Return: Nothing
 */

void numberToString(int64_t number, int base, char *buf)
{
	if (number < 0)
	{
		buf[0] = '-';
		number *= -1;
	}
	unsignedNumberToString(number, base, buf);
}
/**
 * free_buffer - function that frees array of pointers
 * @argv: array of pointers
 * Return: nothing
 */

void free_buffer(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
