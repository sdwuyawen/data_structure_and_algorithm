/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/05/2015 08:36:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int longest_dijian(int x)
{
	char str[100] = {0};
	char str_dst[100] = {0};
	int y = 0;
	int len = 0;
	int factor = 1;
	int i,j;

	int start = 0;
	int end = 0;

	int max_num1 = 0;	//最大递减数
	int max_num2 = 0;	//递减数中各位之和最大的数
	int max_num2_sum = 0;	//递减数各位之和最大值
	int num2_sum = 0;		//递减数各位之和
	int num2_len = 0;

	int num;

	if(x < 0)
	{
		x = 0 - x;
	}

	y = x;
	while(y != 0)
	{
		len++;
		y /= 10;
	}

	for(i = 0; i < len - 1; i++)
	{
		factor *= 10;
	}

	y = x;
	for(i = 0; i < len; i++)
	{
		str[i] = y / factor + '0';

		y = y % factor;
		factor /= 10;
	}

	//针对大于等于10的数
	for(i = 0; i < len - 1; i++)
	{
		if(str[i + 1] < str[i])
		{
			end = i + 1;
		}
		else			//获取新的起点
		{
			memcpy(str_dst, &str[start], i - start + 1);
			str_dst[i - start + 1] = 0x00;
//			printf("%s\n", str_dst);

			start = i + 1;

			num = atoi(str_dst);
//			printf("num = %d\n", num);

			//获取最大递减数
			if(max_num1 < num)
			{
				max_num1 = num;
			}
			//获取最大递减数中各位之和最大的数
			num2_sum = 0;
			num2_len = strlen(str_dst);
			for(j = 0; j < num2_len; j++)
			{
				num2_sum += str_dst[j] - '0';
			}

			if(max_num2_sum < num2_sum)
			{
				max_num2_sum = num2_sum;
				max_num2 = num;
			}
		}
	}

	//获取一直到结尾的数
//	if(start != len - 1)
	{
		memcpy(str_dst, &str[start], len - start + 1);
		str_dst[len - start + 1] = 0x00;
//		printf("%s\n", str_dst);

		num = atoi(str_dst);
//		printf("num = %d\n", num);

		//获取最大递减数
		if(max_num1 < num)
		{
			max_num1 = num;
		}

		//获取最大递减数中各位之和最大的数
		num2_sum = 0;
		num2_len = strlen(str_dst);
		for(j = 0; j < num2_len; j++)
		{
			num2_sum += str_dst[j] - '0';
		}

		if(max_num2_sum < num2_sum)
		{
			max_num2_sum = num2_sum;
			max_num2 = num;
		}
	}

//	printf("str = %s, len = %d\n", str, len);

//	printf("max_num1 = %d\n", max_num1);
//	printf("max_num2 = %d\n", max_num2);

	printf("%d\n", max_num1 + max_num2);

	return 0;
}

int main(void)
{
	int val;
	int len;

//	while(1)
	{
		scanf("%d", &val);
		len = longest_dijian(val);
	}

	return 0;

}
