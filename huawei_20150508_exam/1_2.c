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
			//�ж�����֮���ظ��ַ�����
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
//				str[i + 1 + rep_len - 1] = (char)0xFF;		//��ɾ�����
				flag[i + 1 + rep_len - 1] = 1;
			}
				
			i += rep_len + 1;		//��һ���ж����

			//���֮ǰһ�������֣������һ�������ж�
			if(str[i - 1] >= '0' && str[i - 1] <= '9')
//			if(last >= '0' && last <= '9')
			{
				i--;
			}

			start = i;		//�������

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