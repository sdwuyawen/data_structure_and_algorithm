#include <stdio.h>
#include <string.h>

int num[510];
char str[510];

int str_len = 0;

int table[10][20] = 
{
	//	0
	{	
		0, -1,
	},
	//	1
	{
		1,2,3,4,5,6,7,8,9,0,-1,
	},
	//	2
	{
		2,3,5,6,8,9,0,-1,
	},
	//	3
	{
		3,6,9,-1,
	},
	//	4
	{
		4,5,6,7,8,9,0,-1
	},
	//	5
	{
		5,6,8,9,0,-1
	},
	//	6
	{
		6,9,-1,
	},
	//	7
	{
		7,8,9,0,-1
	},
	//	8
	{
		0,8,9,-1,
	},
	//	9
	{
		9,-1
	},

};



int main(void)
{
	int T = 0;
	int T_count = 0;
	int i;
	int j;

	int borrow_bit = 0;
	int not_match = 0;

	scanf("%d", &T);

	for(T_count = 0; T_count < T; T_count++)
	{
		scanf("%s", str);
		str_len = strlen(str);

		for(i = 0; i < str_len; i++)
		{
			num[i] = str[i] - '0';
		}
/*
		for(i = 0; i < str_len; i++)
		{
			printf("%d", num[i]);
		}
		printf("\n");
*/

		//num[0]是第一个按下的键(最高位)
		//num[str_len - 1]是最后一个按下的键(最低位)

		while(1)
		{
			not_match = 0;
			for(i = 0; i < str_len - 1 && not_match == 0; i++)
			{
				for(j = 0; j < 20; j++)
				{
					if(table[num[i]][j] == -1)
					{
						not_match = 1;
						break;
					}
					else
					{
						if(num[i + 1] == table[num[i]][j])	//符合，继续判断
						{
							break;
						}
					}
				}
			}
			
			if(not_match == 0)								//匹配，找到
			{
				break;
			}
			else
			{
				//大数减1
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
					else
					{
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
						
				}		
			}
		}

		for(i = 0; i < str_len; i++)
		{
			printf("%d", num[i]);
		}
		printf("\n");
	}


	
	return 0;
}