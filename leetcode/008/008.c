/*
 * =====================================================================================
 *
 *       Filename:  007.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/02/2015 05:14:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  WYW
 *   Organization:
 *
 * =====================================================================================
 */
#include <string.h>
#include <stdio.h>

int myAtoi(char* str)
{
	long long x = 0;
	int temp;
	int negative_flag = 0;
	int i = 0;
	int len;

	unsigned long long max_s32_negative = 0x80000000;
	unsigned long long max_s32_positive = 0x7FFFFFFF;

	len = strlen(str);

	if(len == 0)
	{
		return 0;
	}

	while(str[i] == ' ')
	{
		i++;
	}

	if(str[i] == '-')
	{
		i++;
		negative_flag = 1;
	}
	else if(str[i] == '+')
	{
		i++;
		negative_flag = 0;
	}

	while(str[i] != 0x00)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			temp = str[i] - '0';
			i++;

			x *= 10;
			x += temp;

			if(negative_flag == 0)
			{
				if(x > max_s32_positive)
				{
					x = max_s32_positive;
					break;
				}
			}
			else
			{
				if(x > max_s32_negative)
				{
					x = max_s32_negative;
					break;
				}
			}
		}
		else
		{
			break;
		}

	}

	if(negative_flag == 1)
	{
		x = 0 - x;
	}

	return (int)x;
}

int main(void)
{
	char x[100];
	int y;

	while(1)
	{
		scanf("%s", x);
		y = myAtoi(x);
		printf("x = %s, y = %d\n", x, y);
	}
}

