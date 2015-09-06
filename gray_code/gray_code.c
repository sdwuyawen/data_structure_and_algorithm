#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//2
//4
//8
// void generate_gray(int *buf, int bits)
// {
// 	int count;
// 
// 	int top_num;
// 	int bot_start;
// 	int bot_end;
// 
// 	int i;
// 	int j;
// 
// 	if(bits == 1)
// 	{
// 		buf[0][0] = 0;
// 		buf[1][0] = 0;
// 	}
// 	else
// 	{
// 		generate_gray(buf, bits - 1);
// 	}
// 
// 	//�ܳ���
// 	count = pow(2, bits);
// 	//�ϰ벿����
// 	top_num = count / 2;
// 	//�ϰ벿��ʼindex
// 	bot_start = count / 2;
// 	//�°벿����index
// 	bot_end = count - 1;
// 
// 	//�ϰ벿�������һλ
// 	for(i = 0; i < top_num; i++)
// 	{
// 		for(j = bits - 1; i >= 1; j--)
// 		{
// 			buf[i][j] = buf[i][j - 1];
// 		}
// 	}
// 	//�ϰ벿�ײ�Ϊ0
// 	for(i = 0; i < top_num; i++)
// 	{
// 		buf[i][0] = 0;
// 	}
// 
// 	//�����°벿
// 	for(i = 0; i < top_num; i++)
// 	{
// 		for(j = 1; j < bits; j++)
// 		{
// 			buf[bot_end - i][j] = buf[i][j];
// 		}
// 	}
// 	//�°벿�ײ�Ϊ1
// 	for(i = bot_start; i <= bot_end; i++)
// 	{
// 		buf[i][0] = 1;
// 	}
// }


//2
//4
//8
void generate_gray(int *buf, int bits)
{
	int count;
	
	int top_num;
	int bot_start;
	int bot_end;
	
	int i;
	int j;
	
	if(bits == 1)
	{
		buf[0] = 0;
		buf[1 * bits + 0] = 0;
	}
	else
	{
		generate_gray(buf, bits - 1);
	}
	
	//�ܳ���
	count = (int)pow(2, bits);
	//�ϰ벿����
	top_num = count / 2;
	//�°벿��ʼindex
	bot_start = count / 2;
	//�°벿����index
	bot_end = count - 1;
	
//	//�ϰ벿�������һλ
//	for(i = 0; i < top_num; i++)
//	{
//		for(j = bits - 1; j >= 1; j--)
//		{
//			buf[i * bits + j] = buf[i * (bits - 1)+ j - 1];
//		}
//	}
//	//�ϰ벿�ײ�Ϊ0
//	for(i = 0; i < top_num; i++)
//	{
//		buf[i * bits] = 0;
//	}
	
	//�����°벿
	for(i = 0; i < top_num; i++)
	{
		for(j = 1; j < bits; j++)
		{
			buf[(bot_end - i) * bits + j] = buf[i * (bits - 1) + j - 1];
		}
	}
	//�°벿�ײ�Ϊ1
	for(i = bot_start; i <= bot_end; i++)
	{
		buf[i * bits + 0] = 1;
	}

	//�ϰ벿�������һλ
	for(i = 0; i < top_num; i++)
	{
		for(j = 1; j < bits; j++)
		{
			buf[i * bits + j] = buf[(bot_end - i) * bits + j];
		}
	}
	//�ϰ벿�ײ�Ϊ0
	for(i = 0; i < top_num; i++)
	{
		buf[i * bits] = 0;
	}
}


void print_gray(int bits)
{
	int i;
	int j;
	int count = (int)pow(2, bits);

	//��count�������룬ÿ��������ռ��bits��int
	int *buf = (int *)malloc(count * sizeof(int) * bits);

	generate_gray(buf, bits);

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < bits; j++)
		{
			printf("%d", buf[i * bits + j]);
		}
		printf("\n");
	}

	free(buf);
}


int main(void)
{
	int bits;

	scanf("%d", &bits);
	print_gray(bits);
	return 0;
}
