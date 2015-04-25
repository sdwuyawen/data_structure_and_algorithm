#include <stdio.h>
#include <string.h>

char input[10010] = {0};
char input_trans[20020] = {0};

char value(char x)
{
	char val;

	val = x - 'a' + 1;

	return val;
}

int main(void)
{
	unsigned __int64 srclen = 0;
	unsigned __int64 translen = 0;
	unsigned __int64 continus_count = 0;
	unsigned __int64 sum = 0;

	unsigned __int64 i;
	unsigned __int64 j;

	unsigned int T;
	unsigned int T_count;

	scanf("%d", &T);
	for(T_count = 0; T_count < T; T_count++)
	{
		scanf("%s", input);
		srclen = strlen(input);
		
		j = 0;
		memset(input_trans, 0, sizeof(input_trans));
		for(i = 0; i < srclen; i++)
		{
			if(input[i] >= 'a' && input[i] <= 'z')
			{
				input_trans[j] = input[i];
				j++;
			}
			else if(input[i] >= 'A' && input[i] <= 'Z')
			{
				input_trans[j] = input[i] - 'A' + 'a';
				j++;
				input_trans[j] = input[i] - 'A' + 'a';
				j++;
			}
		}
		
		sum = 0;
		translen = strlen(input_trans);			//小写的总长度
//		printf("translen=%d\n", translen);
		for(i = 0; i < translen; )
		{
			continus_count = 1;
			while(i + continus_count < translen && input_trans[i] == input_trans[i + continus_count])
			{
				continus_count++;				//连续字符个数
			}
			sum += continus_count * continus_count * value(input_trans[i]);
			
			i += continus_count;
		}
		
		printf("%I64u\n", sum);
	}

	return 0;
}