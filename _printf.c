#include "main.h"

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
	char buff[1024];
	char temp[20];

	va_list va1;

	va_start(va1, format);

	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			i++;
			_switch_1(*(format + i), va1, &len_buff, buff, temp);
			_switch_2(*(format + i), va1, &len_buff, buff, temp);
			_switch_3(format, &i, va1, &len_buff, buff, temp);
		}
		else
		{
			buff[len_buff++] = *(format + i);
		}
		i++;
	}
	buff[len_buff] = '\0';
	write(1, buff, len_buff);
	return (len_buff);
}
