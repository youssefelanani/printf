#include "main.h"

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest
 * @dest: the copied list
 * @src: original list
 *
 * Return: none
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (src[i] != '\0')
	{
		i++;
	}

	for (; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}




/**
 * _strlen - gets the length of the string
 * @s: input string
 *
 * Return: length of string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}




/**
 * _print - prints normal strings
 * @s: input string
 *
 * Return: string on cmd
 */
int _print(const char *s)
{
	return (write(1, s, _strlen(s)));
}



/**
 * _tolower - gets the lower case of any character
 * @s: input string
 *
 * Return: string on cmd
 */
char _tolower(char s)
{
	if (s >= 65 && s <= 90)
	{
		s = s + 32;
	}
	return (s);
}




/**
 * _strrev - reverses a string
 * @s: input string
 *
 * Return: void
 */
void _strrev(char *s)
{
	int i = 0;
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	for (; i < len / 2; i++)
	{
		char swap = *(s + i);
		*(s + i) = *(s + len - 1 - i);
		*(s + len - 1 - i) = swap;
	}
}
