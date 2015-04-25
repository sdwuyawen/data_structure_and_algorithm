#include <stdio.h>
#include <string.h>

int num[510];
char str[510];

int str_len = 0;


int main(void)
{
	int T = 0;
	int i;
	int borrow_bit = 0;

	scanf("%s", str);
	str_len = strlen(str);

	for(i = 0; i < str_len; i++)
	{
		num[i] = str[i] - '0';
	}

	for(i = 0; i < str_len; i++)
	{
		printf("%d", num[i]);
	}
	printf("\n");

	//num[0]是第一个按下的键(最高位)
	//num[str_len - 1]是最后一个按下的键(最低位)

	borrow_bit = 0;
	for(i = str_len - 1; i >= 0; i--)
	{
		if(borrow_bit == 1)		//有借位
		{
			borrow_bit = 0;

			if(num[i] == 0)			//借位
			{
				num[i] = 9;
				borrow_bit = 1;
			}
			else
			{
				num[i]--;
				break;
			}
		}

		if(num[i] == 0)			//借位
		{
			num[i] = 9;
			borrow_bit = 1;
		}
		else
		{
			num[i]--;
			break;
		}
	}

	for(i = 0; i < str_len; i++)
	{
		printf("%d", num[i]);
	}
	printf("\n");
	
	return 0;
}