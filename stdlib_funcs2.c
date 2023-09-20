#include "shell.h"

/**
 * _strchr - function that finds the character we are seaching
 * @str: the string we are using to parse for the character
 * @c: the character we are searching
 * Return: returns the character on success and NULL if it fails
 */
char *_strchr(char *str, int c)
{
	char *ptr;

	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == c)
			return (ptr);
	}
	return (NULL);
}


/**
 * _puts - prints a string followed by a new line
 * @str: pointer variable.
 */
void _puts(char *str)
{
	for (; *str != '\0'; str++)
		putchar(*str);
}
/**
 * _strdup - dupplicates string
 * @org: pointer to string to be duplicated
 * Return: pointer to duplicated string
 */

char *_strdup(char *org)
{
	int org_size;
	static char *dup;
	char *dup_offset;

	/* Allocate memory for duplicate */
	org_size = strlen(org);
	dup = malloc(sizeof(char) * (org_size + 1));
	if (dup == NULL)
		return ((char *)NULL);

	/* Copy string */
	dup_offset = dup;
	while (*org)
	{
		*dup_offset = *org;
		dup_offset++;
		org++;
	}
	*dup_offset = '\0';

	return (dup);
}
