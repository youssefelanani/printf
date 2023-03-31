#include "main.h"


/**
 * _islower - check if char is lowercase
 * @c: input character
 *
 * Return: 1 if lowercase, else 0
 */
int _islower(char c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	return (0);
}



/**
 * _toupper - converts string to uppercase
 * @s: input character
 * @flag: if 1 so change it to uppercase, else not
 *
 * Return: void
 */
void _toupper(char *s, int flag)
{
	int i = 0;

	while (*(s + i) != '\0' && flag == 0)
	{
		if (_islower(*(s + i)))
			*(s + i) = *(s + i) - 32;

		i++;
	}
}




/**
 * _itof_loop - do the convertion loop for _itoa and _itof
 * @rem: value to do the conversion
 * @loop_val: value to create loop
 * @base: determine the value type (decimal, octal, hexa)
 * @container: empty list to add values in it
 * @i: iterator for the container string
 *
 * Return: void
 */
void _itof_loop(int *rem, int *loop_val, int base, char *container, int *i)
{
	while (*loop_val != 0)
	{
		*rem = *loop_val % base;
		container[*i] = (*rem > 9) ? (*rem - 10) + 'a' : *rem + '0';
		*loop_val = *loop_val / base;
		*i = *i + 1;
	}
}

/**
 * _itof - converts integers and floats to strings
 * @num: input value
 * @container: empty list to add values in it
 * @base: determine the value type (decimal, octal, hexa)
 *
 * Return: string
 */
char *_itof(double num, char *container, int base)
{
	int i = 0;
	int int_num = num;
	double cp_num = num;
	bool negative = false;
	int fraction = (cp_num - (int)cp_num) * 1000000;
	int rem = 0;

	if (num == 0)
	{
		container[i++] = '0';
		container[i] = '\0';
		return (container);
	}
	if (num < 0)
	{
		negative = true;
		num = -num;
		int_num = -int_num;
		fraction = -fraction;
	}
	if (num > (int)num)
	{
		_itof_loop(&rem, &fraction, base, container, &i);
		container[i++] = '.';
	}

	rem = 0;
	_itof_loop(&rem, &int_num, base, container, &i);

	if (negative)
		container[i++] = '-';

	container[i++] = '\0';
	_strrev(container);
	return (container);
}





/**
 * _itou - converts integers and floats to strings
 * @num: input value
 * @container: empty list to add values in it
 * @base:
 *
 * Return: string
 */
char *_itou(unsigned int num, char *container, int base)
{
	int i = 0;

	if (num == 0)
	{
		container[i++] = '0';
		container[i] = '\0';
		return (container);
	}

	while (num != 0)
	{
		int rem = num % base;

		container[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	container[i++] = '\0';
	_strrev(container);
	return (container);
}
