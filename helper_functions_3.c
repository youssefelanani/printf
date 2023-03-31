#include "main.h"


/**
 * _abs - get the absolute value of integer
 * @num: input number
 *
 * Return: absolute of num
 */
unsigned int _abs(int num)
{
	unsigned int val = 0;

	if (num < 0)
		num = -num;
	val = num;
	return (val);
}




/**
 * _switch_1 - compares (s, i, d, u) format specifiers
 * @c: input char to compare
 * @va1: next value type in the variadic function
 * @len_buff: index to append in it
 * @buff: string to carry all values
 * @temp: string for the converted valuse
 *
 * Return: string and args on cmd
 */
void _switch_1(char c, va_list va1, int *len_buff, char *buff, char *temp)
{
	char *str_arg;

	switch (c)
	{
		case 's':
			str_arg =  va_arg(va1, char *);
			_strcpy(&buff[*len_buff], str_arg);
			*len_buff = *len_buff + _strlen(str_arg);
			break;
		case 'i':
			_itof((int)va_arg(va1, int), temp, 10);
			_strcpy(&buff[*len_buff], temp);
			*len_buff = *len_buff + _strlen(temp);
			break;
		case 'd':
			_itof((int)va_arg(va1, int), temp, 10);
			_strcpy(&buff[*len_buff], temp);
			*len_buff = *len_buff + _strlen(temp);
			break;
		case 'u':
			_itou(va_arg(va1, int), temp, 10);
			_strcpy(&buff[*len_buff], temp);
			*len_buff = *len_buff + _strlen(temp);
			break;
		case 'b':
			decimalToBinary(va_arg(va1, int), temp);
			_strcpy(&buff[*len_buff], temp);
			*len_buff = *len_buff + _strlen(temp);
			break;
	}
}




/**
 *  _switch_2 - handles only the case that the specifier is
 *				working if its case not matter as c and x
 * @c: input char to compare
 * @va1: next value type in the variadic function
 * @len_buff: index to append in it
 * @buff: string to carry all values
 * @temp: string for the converted value
 *
 * Return: absolute of num
 */
void _switch_2(char c, va_list va1, int *len_buff, char *buff, char *temp)
{
	bool flag = false;

	flag = _islower(c);
	switch (_tolower(c))
	{
		case 'c':
			buff[*len_buff] = (char)va_arg(va1, int);
			*len_buff = *len_buff + 1;
			break;
		case 'x':
			_toupper(_itou((int)va_arg(va1, int), temp, 16), flag);
			_strcpy(&buff[*len_buff], temp);
			*len_buff = *len_buff + _strlen(temp);
			break;
	}
}

/**
 * default_switch_3 - contains part to avoid adding any specifiers found in
 *                    _switch_1
 * @format: input string
 * @i: iterator for the format string
 * @len_buff: index to append in it
 * @buff: string to carry all values
 *
 * Return: void
 */
void default_switch_3(const char *format, int *i, int *len_buff, char *buff)
{
	char _switch_1[9] = {'s', 'c', 'C', 'i', 'd', 'u', 'x', 'X', 'b'};
	bool matched = false;
	int x = 0;

	for (; x < 9; x++)
	{
		if (*(_switch_1 + x) == *(format + *i))
		{
			matched = true;
			break;
		}
	}
	if (matched == false)
	{
		if (*(format + *i) != '%')
		{
			buff[*len_buff] = *(format + *i - 1);
			*len_buff = *len_buff + 1;
		}
		buff[*len_buff] = *(format + *i);
		*len_buff = *len_buff + 1;
	}
}




/**
 * _switch_3 - compares (f, p, o) format specifiers
 * @format: input string
 * @i: iterator for the format string
 * @va1: next value type in the variadic function
 * @len_buff: index to append in it
 * @buff: string to carry all values
 * @temp: string for the converted value
 *
 * Return: void
 */
void _switch_3(const char *format, int *i, va_list va1, int *len_buff,
		char *buff, char *temp)
{
	switch (*(format + *i))
	{
		case 'f':
				_itof((float)va_arg(va1, double), temp, 10);
				_strcpy(&buff[*len_buff], temp);
				*len_buff = *len_buff + _strlen(temp);
				break;
		case 'p':
				_itou(va_arg(va1, int), temp, 16);
				_strcpy(&buff[*len_buff], temp);
				*len_buff = *len_buff + _strlen(temp);
				break;
		case 'o':
				_itou((int)va_arg(va1, int), temp, 8);
				_strcpy(&buff[*len_buff], temp);
				*len_buff = *len_buff + _strlen(temp);
				break;
		default:
			default_switch_3(format, i, len_buff, buff);
			break;
	}
}
