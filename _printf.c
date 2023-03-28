#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>


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




/**
 * _itof - converts integers and floats to strings
 * @num: input value
 * @container: empty list to add values in it
 * @base:
 *
 * Return: string
 */
char *_itof(float num, char *container, int base)
{
	int i = 0;
	int int_num = num;
	float cp_num = num;
	bool negative = false;
	int fraction = (cp_num - (int)cp_num) * 1000000;


	if (num == 0)
	{
		container[i++] = '0';
		container[i] = '\0';
		return (container);
	}

	if (num < 0 && base == 10)
	{
		negative = true;
		num = -num;
		int_num = -int_num;
		fraction = -fraction;

	}

	if (num > (int)num)
	{

		while (fraction != 0 && base == 10)
		{
			int rem = fraction % base;

			container[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			fraction = fraction / base;
		}
		container[i++] = '.';
	}

	while (int_num != 0)
	{
		int rem = int_num % base;

		container[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		int_num = int_num / base;
	}


	if (negative)
	{
		container[i++] = '-';
	}

	container[i++] = '\0';
	_strrev(container);
	return (container);
}



/**
 * _printf - prints anuthing normal printf function do
 * @format: input string
 *
 * Return: string and args on cmd
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int len_buff = 0;
	char buff[100];
	char temp[20];
	char *str_arg;
	va_list va1;

	va_start(va1, format);

	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			switch (_tolower(*(format + i)))
			{
			case 's':
				{
					str_arg =  va_arg(va1, char *);
					_strcpy(&buff[len_buff], str_arg);
					len_buff += _strlen(str_arg);
					break;
				}
			case 'c':
				{
					buff[len_buff] = (char)va_arg(va1, int);
					len_buff++;
					break;
				}
			case 'i':
				{
					_itof(va_arg(va1, int), temp, 10);
					_strcpy(&buff[len_buff], temp);
					len_buff += _strlen(temp);
					break;
				}
			case 'd':
				{
					_itof(va_arg(va1, int), temp, 10);
					_strcpy(&buff[len_buff], temp);
					len_buff += _strlen(temp);
					break;
				}
			case 'u':
				{
					_itof(va_arg(va1, int), temp, 10);
					_strcpy(&buff[len_buff], temp);
					len_buff += _strlen(temp);
					break;
				}
			case 'f':
				{
					_itof((float)va_arg(va1, double), temp, 10);
					_strcpy(&buff[len_buff], temp);
					len_buff += _strlen(temp);
					break;
				}
			case 'x':
				{
					_itof((float)va_arg(va1, int), temp, 16);
					_strcpy(&buff[len_buff], temp);
					len_buff += _strlen(temp);
					break;
				}
			case 'p':
				{
					_itof((float)va_arg(va1, int), temp, 16);
					_strcpy(&buff[len_buff], temp);
					len_buff += _strlen(temp);
					break;
				}
			case 'o':
				{
					_itof((float)va_arg(va1, int), temp, 8);
					_strcpy(&buff[len_buff], temp);
					len_buff += _strlen(temp);
					break;
				}
			default:
				buff[len_buff] = *(format + i);
				len_buff++;
			}
		}
		else
		{
			buff[len_buff] = *(format + i);
			len_buff++;
		}
		i++;
	}
	buff[len_buff] = '\0';
	write(1, buff, len_buff);
	return (len_buff);
}

