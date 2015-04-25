#include <stdio.h>
#include <string.h>

int print_num(unsigned char *buf, int len, int negative_flag)
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

	if(negative_flag == 1)
	{
		printf("-");
	}

	while(i >= 0)
	{
		printf("%d", buf[i]);
		i--;
	}

	printf("\n");

	return 0;
}

//大数a-大数b，要求a>=b
void big_num_minus(char *str_a, char *str_b)
{
	char num_a[1010] = {0}, num_b[1010] = {0};
	char result[1010] = {0};

	int length_a;
	int length_b;
	int max_length;

	int i;
	int borrow_bit = 0;

	char *num1;		//指向较大数
	char *num2;		//指向较小数

	int negative_flag = 0;

	length_a = strlen(str_a);
	length_b = strlen(str_b);

	for(i = 0; i < length_a; i++)
	{
		num_a[i] = str_a[length_a - i - 1] - '0';
	}

	for(i = 0; i < length_b; i++)
	{
		num_b[i] = str_b[length_b - i - 1] - '0';
	}

	if(length_a > length_b)
	{
		num1 = num_a;
		num2 = num_b;

		negative_flag = 0;
	}
	else if(length_a < length_b)
	{
		num1 = num_b;
		num2 = num_a;

		negative_flag = 1;
	}
	else						//a和b长度相等，需要判断哪个大
	{
		//从最高位开始判断
		for(i = length_a - 1; i >= 0; i--)
		{
			if(num_a[i] == num_b[i])
			{
				continue;
			}
			else if(num_a[i] > num_b[i])
			{
				num1 = num_a;
				num2 = num_b;

				negative_flag = 0;
				break;
			}
			else if(num_a[i] < num_b[i])
			{
				num1 = num_b;
				num2 = num_a;

				negative_flag = 1;
				break;
			}
		}

		if(i < 0)				//两数完全相同
		{
			num1 = num_a;
			num2 = num_b;

			negative_flag = 0;
		}
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

	print_num(result, max_length, negative_flag);


}

int main(void)
{
	unsigned char str1[1001], str2[1001];

	scanf("%s %s", str1, str2);
	big_num_minus(str1, str2);


	return 0;
}
