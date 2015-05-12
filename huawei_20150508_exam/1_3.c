#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
x@y = (x-1)*(y+1)

x#y = (2x+5)*(3y+60)

x$y = (x+1)*(2x+3)*(y-1)*(2y-3)

x&y = (x+y+1)*(y-9)+(x+7)/(y-8)
*/

int cal_at(int x, int y)
{
	int val;

	val = (x-1)*(y+1);

	return val;
}

int cal_jinghao(int x, int y)
{
	int val;

	val = (2*x+5)*(3*y+60);

	return val;
}

int cal_dollar(int x, int y)
{
	int val;

	val = (x+1)*(2*x+3)*(y-1)*(2*y-3);

	return val;
}

int cal_yu(int x, int y)
{
	int val;

	val = (x+y+1)*(y-9)+(x+7)/(y-8);

	return val;
}

int main(void)
{
	char str[1100] = {0};
	char str_preprocess[1100] = {0};

	char num_A[1100] = {0};
	char num_B[1100] = {0};

	int val_A;
	int val_B;

	int str_len_src;
	int len = 0;

	int value = 0;

	int i = 0;
	int j = 0;
	int k = 0;

	int last;

	scanf("%s", str);

	str_len_src = strlen(str);

	//去掉空格，获取长度
	for(i = 0; i < str_len_src;)
	{
		if(str[i] != ' ')
		{
			str_preprocess[j++] = str[i];
			len++;
		}
		i++;
	}

	for(i = 0; i < len; i++)
	{
		if(str_preprocess[i] >= '0' &&  str_preprocess[i] <= '9')
		{

		}
		else
		{
			break;
		}
	}

	memcpy(num_A, str_preprocess, i);
	num_A[i] = 0x00;
	val_A = atoi(num_A);

	last = i;

	i++;
	for(; i < len; i++)
	{
		if(str_preprocess[i] >= '0' &&  str_preprocess[i] <= '9')
		{

		}
		else
		{
			break;
		}
	}

	memcpy(num_B, &str_preprocess[last + 1], i - (last + 1) + 1);
	num_B[i - (last + 1) + 1] = 0x00;
	val_B = atoi(num_B);

	if(str_preprocess[last] == '@')
	{

		value = cal_at(val_A, val_B);
	}
	else if(str_preprocess[last] == '#')
	{
		value = cal_jinghao(val_A, val_B);
	}
	else if(str_preprocess[last] == '$')
	{
		value = cal_dollar(val_A, val_B);
	}
	else if(str_preprocess[last] == '&')
	{
		value = cal_yu(val_A, val_B);
	}

	printf("%d", value);

	return 0;
}