#include <stdio.h>
#include <string.h>

int print_num(unsigned char *buf, int len)
{
	int i = len - 1;

	while(i > 0)
	{
		if(buf[i] == 0)
		{
			i--;
		}
		else
		{
			break;
		}
	}

	while(i >= 0)
	{
		printf("%d", buf[i]);
		i--;
	}

	return 0;
}

//大数a-大数b，要求a>=b
void big_num_minus(char *str_a, char *str_b)
{
	char num1[1010] = {0}, num2[1010] = {0};
	char result[1010] = {0};

	int length_a;
	int length_b;
	int max_length;

	int i;
	int borrow_bit = 0;

	length_a = strlen(str_a);
	length_b = strlen(str_b);

	for(i = 0; i < length_a; i++)
	{
		num1[i] = str_a[length_a - i - 1] - '0';
	}

	for(i = 0; i < length_b; i++)
	{
		num2[i] = str_b[length_b - i - 1] - '0';
	}

	//[0]保存数据最低位
	max_length = length_a > length_b ? length_a : length_b;

	for(i = 0; i < max_length; i++)
	{
		if(num1[i] >= num2[i] + borrow_bit)
		{
			result[i] = num1[i] - num2[i] - borrow_bit;
			borrow_bit = 0;
		}
		else
		{
			result[i] = num1[i] + 10 - num2[i] - borrow_bit;
			borrow_bit = 1;
		}
	}

	print_num(result, max_length);


	



}

int main(void)
{
	unsigned int i,j;
	unsigned int T;
	unsigned int sum_bit;
	unsigned int length1[20], length2[20];
	unsigned int max_length[20];
	unsigned char str1[1001], str2[1001];
	
	unsigned char num1[20][1001] = {0}, num2[20][1001] = {0};
	unsigned char num_sum[20][1001];

	scanf("%s %s", str1, str2);
	big_num_minus(str1, str2);
	/*
	scanf("%d", &T);

	for(j = 0; j < T; j++)
	{
		scanf("%s %s", str1, str2);
		
		length1[j] = strlen(str1);
		for(i = 0; i < length1[j]; i++)
		{
			num1[j][i] = str1[length1[j] - 1 - i] - '0';
		}
		
		length2[j] = strlen(str2);
		for(i = 0; i < length2[j]; i++)
		{
			num2[j][i] = str2[length2[j] - 1 - i] - '0';
		}
		
		sum_bit = 0;
		max_length[j] = (length1[j] > length2[j] ? length1[j] : length2[j]);
		for(i = 0; i < max_length[j] ; i++)
		{
			sum_bit = num1[j][i] + num2[j][i] + sum_bit / 10;
			num_sum[j][i] = sum_bit % 10;
		}
		if(sum_bit >= 10)
		{
			num_sum[j][i] = sum_bit % 10;
			max_length[j] += 1;
		}	
	}

	for(j = 0; j < T; j++)
	{
		printf("Case %d:\n", j+1);
		print_num(num1[j], length1[j]);
		printf(" + ");
		print_num(num2[j], length2[j]);
		printf(" = ");
		print_num(num_sum[j], max_length[j]);
		printf("\n");
		if(j < T - 1)
		{
			printf("\n");
		}
	}	*/

	return 0;
}
