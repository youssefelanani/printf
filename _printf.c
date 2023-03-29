#include "main.h"



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
	float cp_num = num;
	bool negative = false;
	int i = 0, int_num = num, fraction = (cp_num - (int)cp_num) * 1000000;

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
		container[i++] = '-';
	container[i] = '\0';
	_strrev(container);
	return (container);
}





/**
 * _case - represents a specific condition
 * @format: input string
 * @base: value to divide with
 * @len_buff: index to append in it
 * @buff: string to carry all values
 * @temp: string for the converted valuse
 *
 * Return: void
 */
void _case(const char *format, int base, int *len_buff, char *buff, char *temp)
{
	va_list val;

	va_start(val, format);

	_itof((float)va_arg(val, int), temp, base);
	_strcpy(buff[*len_buff], temp);
	*len_buff = *len_buff + _strlen(temp);
	break;
}





/**
 * _switch - compares all format specifiers
 * @format: input string
 * @c: input char to compare
 * @len_buff: index to append in it
 * @buff: string to carry all values
 * @temp: string for the converted valuse
 *
 * Return: string and args on cmd
 */
void _switch(const char *format, char c, int *len_buff, char *buff, char *temp)
{
	va_list val;

	va_start(val, format);

	switch (_tolower(c))
	{
		case 's':
			str_arg =  va_arg(va1, char *);
			_strcpy(&buff[*len_buff], str_arg);
			*len_buff = *len_buff + _strlen(temp);
			break;
		case 'c':
			buff[len_buff] = (char)va_arg(va1, int);
			*len_buff = *len_buff + 1;
			break;
		case 'i':
			_case(format, 10, *len_buff, buff, temp);
		case 'd':
			_case(format, 10, *len_buff, buff, temp);
		case 'u':
			_case(format, 10, *len_buff, buff, temp);
		case 'f':
			_itof((float)va_arg(va1, double), temp, 10);
			_strcpy(&buff[len_buff], temp);
			*len_buff = *len_buff + _strlen(temp);
		case 'x':
			_case(format, 16, *len_buff, buff, temp);
		case 'p':
			_case(format, 16, *len_buff, buff, temp);
		case 'o':
			_case(format, 8, *len_buff, buff, temp);
		default:
			buff[len_buff] = *(format + i);
			*len_buff = *len_buff + 1;
	}
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
	char buff[100];
	char temp[20];
	char *str_arg;
	va_list val;
	int len_buff = 0;

	va_start(val, format);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			_switch(format, *(format + i), &len_buff, buff, temp);
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
