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
#include <stdlib.h>

/*
 * 1
 * 11
 * 121
 *
 * 1221
 * 22
 *
 * 12321 len=5		3
 * 232
 * 3
 *
 * 123321 len=6		3
 * 1234321 len=7	4
 *
 *
 * */
int isPalindrome(int x)
{
	int len = 0;
	int num = 0;
	int factor = 1;
	int i;

	if(x < 0)
	{
		return 0;
	}
	else if(x == 0)
	{
		return 1;
	}

	num = x;
	while(num != 0)
	{
		len++;
		num /= 10;
	}

//	printf("len = %d\n", len);

	for(i = 0; i < len - 1; i++)
	{
		factor *= 10;
	}

//	printf("factor = %d\n", factor);

	num = x;
	while(len >= 2)
	{
		if(num / factor != num % 10)
		{
			return 0;
		}
		else
		{
			len -= 2;
			num = num % factor;
			num = num / 10;
			factor /= 100;
		}
	}

	return 1;
}

/*
int isPalindrome(int x)
{
	int len;
	int i;
	int factor_big;
	int factor_little;
	int num_big;
	int num_little;

	num_big = x;
	while(num_big != 0)
	{
		len++;
		num_big /= 10;
	}

	factor_big = 1;
	i = len;
	while(--i)
	{
		factor_big *= 10;
	}

	num_little = 10;

	for(i = 0; i < (len + 1) / 2; i++)
	{

	}

	return 0;
}*/

int main(void)
{
	int x;
	int y;

	while(1)
	{
		scanf("%d", &x);
		y = isPalindrome(x);
		printf("x = %d, y = %d\n", x, y);
	}
}

