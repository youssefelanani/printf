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
void _strrev(char *s);
int _printf(const char *format, ...);

#endif
