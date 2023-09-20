#include "shell.h"

/**
 * _strcat - appends src string to dest string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: dest string
 */

char *_strcat(char *dest, char *src)
{
	int len1;
	int len2;
	int i;

	len1 = _strlen(dest);
	len2 = _strlen(src);

	for (i = 0; i <= len2; i++)
		dest[len1 + i] = src[i];

	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: Argument is a string
 * Return: length of the string
 */

int _strlen(const char *s)
{
	int i;
	int len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - copies the string pointed to src to dest including \0
 * @src: pointer to source string
 * @dest: destination buffer
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	return (aux);
}

/**
 * _strncmp - A function that works exactly like strcmp
 * @s1: First string
 * @s2: Second string
 * @n: How many bytes to comapare atmost
 * Return: int
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	int status;

	status = strncmp(s1, s2, n);
	return (status);
}

/**
 * _strcmp - A function that works exactly like strcmp
 * @s1: First string
 * @s2: Second string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
