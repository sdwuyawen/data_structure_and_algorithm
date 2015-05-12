#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//  33zzhhhhaaa44455pppin
//  33zhhhhaaa445ppin
int main(void)
{
	int len = 0;

	char rep_char = 0;
	int rep_len = 0;

	int cpy_len = 0;

	char str[110] = {0};
	char dst[110] = {0};
	char flag[110] = {0};

	char last;

	int dst_pos = 0;
	
	int i = 0;
	int j = 0;

	int start = 0;

	scanf("%s", str);

	len = strlen(str);

	for(i = 0; i < len; )
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			//判断数字之后重复字符长度
			rep_len = 1;
			for(j = i + 1; j < len && j + 1 < len; j++)
			{
				if(str[j] == str[j + 1])
				{
					rep_len++;
				}
				else
				{
					break;
				}
			}

			last = str[i + 1 + rep_len - 1];
			if(rep_len >= 2)
			{
//				str[i + 1 + rep_len - 1] = (char)0xFF;		//待删除标记
				flag[i + 1 + rep_len - 1] = 1;
			}
				
			i += rep_len + 1;		//下一个判断起点

			//如果之前一个是数字，则回退一个继续判断
			if(str[i - 1] >= '0' && str[i - 1] <= '9')
//			if(last >= '0' && last <= '9')
			{
				i--;
			}

			start = i;		//调整起点

//			printf("len = %d\n", rep_len);
		}
		else
		{
			i++;
		}	
	}

	dst_pos = 0;
	for(i = 0; i < len;)
	{
		if(flag[i] == 0)
		{
			dst[dst_pos++] = str[i];
		}
		i++;
	}

	printf("%s", dst);

	return 0;
}