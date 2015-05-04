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
#include <stdlib.h>
#include <stdio.h>

int reverse(int x)
{
	long long y = 0;
	int temp;
	int negative_flag = 0;

	unsigned long long max_s32_negative = 0x80000000;
	unsigned long long max_s32_positive = 0x7FFFFFFF;

	if(x < 0)
	{
		x = 0 - x;

		negative_flag = 1;
	}

	while(x != 0)
	{
		temp = x % 10;		//取出最低位

		y *= 10;
		y += temp;

		x /= 10;

		if(negative_flag == 0)
		{
			if(y > max_s32_positive )
			{
				y = 0;
				break;
			}
		}
		else
		{
			if(y > max_s32_negative )
			{
				y = 0;
				break;
			}
		}

	}

	if(negative_flag == 1)
	{
		y = 0 - y;
	}

	return (int)y;
}

int main(void)
{
	int x;
	int y;

	while(1)
	{
		scanf("%d", &x);
		y = reverse(x);
		printf("x = %d, y = %d\n", x, y);
	}
}

