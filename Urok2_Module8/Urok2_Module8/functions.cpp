#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<string.h>
#include<time.h>

void swapString(char *first, char *second)
{
	char tmp;
	while (second > first)
	{
		tmp = *first;
		*first++ = *second;
		*second-- = tmp;
	}
}