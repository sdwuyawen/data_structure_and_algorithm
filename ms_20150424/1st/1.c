#include <stdio.h>
#include <string.h>

int fibo[] = {0,1,2,3,5,8,13,21};

char str[110] = {0};
char sub_str[110] = {0};

int present_table[26] = {0};

char sub_array[10000][110] = {0};

int main(void)
{
	int i;
	int j;
	int k;
	int m;

	int str_len;
	int sub_str_len;
	int diff_char_count = 0;
	int diff_array_count = 0;

	int fibo_len = sizeof(fibo) / sizeof(fibo[0]);

	scanf("%s", str);
	str_len = strlen(str);
	
	diff_array_count = 0;
	for(i = 0; i < str_len; i++)
	{
		for(j = i; j < str_len; j++)
		{
			sub_str_len = j - i + 1;
			memcpy(sub_str, &str[i], sub_str_len);
			sub_str[sub_str_len] = 0x00;


			memset(present_table, 0, sizeof(present_table));
			for(k = 0; k < sub_str_len; k++)
			{
				present_table[sub_str[k] - 'a'] = 1;
			}
			
			//不同字符数
			diff_char_count = 0;
			for(k = 0; k < 26; k++)
			{
				if(present_table[k] != 0)
				{
					diff_char_count++;
				}
			}

			//不同字符数是否是fibo
			for(k = 0; k < fibo_len; k++)
			{
				if(diff_char_count == fibo[k])		//符合条件
				{
					for(m = 0; m < diff_array_count; m++)
					{
						if(strcmp(sub_str, &sub_array[m][0]) == 0)	//有相同的，不再插入
						{
							break;
						}
					}

					if(m == diff_array_count)						//没有相同的，插入
					{
						strcpy(&sub_array[diff_array_count][0], sub_str);
						diff_array_count++;
					}			
				}
			}

		}
	}

	for(i = 0; i < diff_array_count; i++)
	{
		printf("%s\n", sub_array[i]);
	}

	return 0;
}