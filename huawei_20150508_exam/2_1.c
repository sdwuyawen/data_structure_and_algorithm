#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	char str[100] = {0};
	unsigned char num[100] = {0};

	unsigned int val_pre;

	int len;
	int i;
	int pos;

	scanf("%s", str);

	len = strlen(str);

	
	if(len % 2 == 0)		//ż����
	{
		pos = 0;
		for(i = 0; i < len;)
		{
			num[pos] = (str[i++] - '0') << 4;
			num[pos] |= (str[i++] - '0');
			pos++;
		}
	}
	else					//������
	{
		num[0] = str[0] - '0';

		pos = 1;
		for(i = 1; i < len;)
		{
			num[pos] = (str[i++] - '0') << 4;
			num[pos] |= (str[i++] - '0');
			pos++;
		}
	}

	//pos��Ҫ�����λ��
	for(i = 0; i < pos; i++)
	{
		printf("%d", num[i]);
	}






	return 0;
}