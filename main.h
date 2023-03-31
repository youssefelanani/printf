#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _print(const char *s);
char _tolower(char s);
int _islower(char c);
void _toupper(char *s, int flag);
void _strrev(char *s);
void _itof_loop(int *rem, int *loop_val, int base, char *container, int *i);
char *_itof(double num, char *container, int base);
char *_itou(unsigned int num, char *container, int base);
unsigned int _abs(int num);
void _switch_1(char c, va_list va1, int *len_buff, char *buff, char *temp);
void _switch_2(char c, va_list va1, int *len_buff, char *buff, char *temp);
void default_switch_3(const char *format, int *i, int *len_buff, char *buff);
void _switch_3(const char *format, int *i, va_list va1, int *len_buff,
		char *buff, char *temp);
int _printf(const char *format, ...);
char *decimalToBinary(unsigned int num, char *container);

#endif
