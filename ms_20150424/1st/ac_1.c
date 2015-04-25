#include <stdio.h>
#include <string.h>

int fibo[] = {0,1,2,3,5,8,13,21};

char str[110] = {0};
char sub_str[110] = {0};

int present_table[26] = {0};

char sub_array[10000][110] = {0};

void sort(char *a[], int count)
{
    int i,j;
	char str_temp[110];

    for(i = 0; i < count - 1; i++)//注意是i<4
    {
        for(j = 0; j < count - 1; j++)//注意是j<4,因为下面要+1和后面的那个字符串比较
        {
            if(strcmp(a[j],a[j+1])>0)//字符串比较:>0表示前面的字符串比后面的大则交换
            {
				strcpy(str_temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], str_temp);
            }
        }
    }
}

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

	char str_temp[110];

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

	//直接输出
// 	for(i = 0; i < diff_array_count; i++)
// 	{
// 		printf("%s\n", sub_array[i]);
// 	}
// 	
// 	printf("\n");
	//排序输出
//	sort(sub_array, diff_array_count);
	
    for(i = 0; i < diff_array_count - 1; i++)//注意是i<4
    {
        for(j = 0; j < diff_array_count - 1; j++)//注意是j<4,因为下面要+1和后面的那个字符串比较
        {
            if(strcmp(sub_array[j],sub_array[j+1])>0)//字符串比较:>0表示前面的字符串比后面的大则交换
            {
				strcpy(str_temp, sub_array[j]);
				strcpy(sub_array[j], sub_array[j + 1]);
				strcpy(sub_array[j + 1], str_temp);
            }
        }
    }
	for(i = 0; i < diff_array_count; i++)
	{
		printf("%s\n", sub_array[i]);
	}

	return 0;
}