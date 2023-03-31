#include "main.h"

/**
 * decimalToBinary - converts decimals to binary
 * @num: input decimal
 * @container: binary string
 *
 * Return: binary string
 */
char *decimalToBinary(unsigned int num, char *container)
{
	int i = 0;

	if (num == 0)
	{
		container[i++] = '0';
		container[i] = '\0';
		return (container);
	}

	while (num > 0)
	{
		container[i++] = (num % 2) + '0';
		num /= 2;
	}


	container[i] = '\0';
	_strrev(container);
	return (container);
}




