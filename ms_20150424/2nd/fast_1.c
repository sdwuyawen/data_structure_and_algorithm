#include <stdio.h>
#include <string.h>

#define TRUE	1
#define FALSE	0 

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
		9,8,7,6,5,4,3,2,1,0,-1,
	},
	//	2
	{
		9,8,6,5,3,2,0,-1,
	},
	//	3
	{
		9,6,3,-1,
	},
	//	4
	{
		9,8,7,6,5,4,0,-1,
	},
	//	5
	{
		9,8,6,5,0,-1,
	},
	//	6
	{
		9,6,-1,
	},
	//	7
	{
		9,8,7,0,-1
	},
	//	8
	{
		9,8,0,-1,
	},
	//	9
	{
		9,-1
	},

};

void big_num_minus_one(int *num, int len)
{
	int borrow_bit = 0;
	int i;

	borrow_bit = 0;
	for(i = len - 1; i >= 0; i--)
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

int is_num_ok(int *num, int len, int *err_pos)
{
	int not_match = 0;
	int i;
	int j;

	not_match = 0;
	for(i = 0; i < len - 1 && not_match == 0; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if(table[num[i]][j] == -1)
			{
				not_match = 1;
				*err_pos = i;								//不匹配的位的序号
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
	
	if(not_match == 0)								//匹配
	{
		return TRUE;
	}
	else											//不匹配
	{
		return FALSE;
	}
}

int main(void)
{
	int T = 0;
	int T_count = 0;
	int i;

	int borrow_bit = 0;
	int not_match = 0;
	int smaller = 0;
	int error_pos = -1;
	int error_pos_pre = -1;
	int first_time = 1;

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

		smaller = 0;
		error_pos = -1;
		error_pos_pre = -1;
		first_time = 1;

		while(1)
		{
			if(is_num_ok(num, str_len, &error_pos) != TRUE)
			{
				if(first_time == 1)			
				{
					first_time = 0;
					error_pos_pre = error_pos;
				}

				if(error_pos > error_pos_pre)
				{
					smaller = 1;
					error_pos_pre = error_pos;
				}

				//还没有减小过，则用减1方案
				if(smaller == 0)
				{
// 					printf("smaller == 0\n");
// 					for(i = 0; i < str_len; i++)
// 					{
// 						printf("%d", num[i]);
// 					}
// 					printf("\n");

					//error是不符合要求的位置之前的位置
					big_num_minus_one(num, error_pos + 1 + 1);
					
				}
				else		//之前的位已经减小过，则本位选最大可用值		
				{
// 					printf("smaller == 1\n");
// 					for(i = 0; i < str_len; i++)
// 					{
// 						printf("%d", num[i]);
// 					}
// 					printf("\n");
					printf("pos = %d, num[pos] = %d\n", error_pos, num[error_pos]);
					num[error_pos + 1] = table[num[error_pos]][0];
				}
			}
			else
			{
				break;
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
