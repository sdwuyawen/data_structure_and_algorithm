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
// 	//总长度
// 	count = pow(2, bits);
// 	//上半部个数
// 	top_num = count / 2;
// 	//上半部起始index
// 	bot_start = count / 2;
// 	//下半部结束index
// 	bot_end = count - 1;
// 
// 	//上半部整体后移一位
// 	for(i = 0; i < top_num; i++)
// 	{
// 		for(j = bits - 1; i >= 1; j--)
// 		{
// 			buf[i][j] = buf[i][j - 1];
// 		}
// 	}
// 	//上半部首部为0
// 	for(i = 0; i < top_num; i++)
// 	{
// 		buf[i][0] = 0;
// 	}
// 
// 	//生成下半部
// 	for(i = 0; i < top_num; i++)
// 	{
// 		for(j = 1; j < bits; j++)
// 		{
// 			buf[bot_end - i][j] = buf[i][j];
// 		}
// 	}
// 	//下半部首部为1
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
	
	//总长度
	count = (int)pow(2, bits);
	//上半部个数
	top_num = count / 2;
	//下半部起始index
	bot_start = count / 2;
	//下半部结束index
	bot_end = count - 1;
	
//	//上半部整体后移一位
//	for(i = 0; i < top_num; i++)
//	{
//		for(j = bits - 1; j >= 1; j--)
//		{
//			buf[i * bits + j] = buf[i * (bits - 1)+ j - 1];
//		}
//	}
//	//上半部首部为0
//	for(i = 0; i < top_num; i++)
//	{
//		buf[i * bits] = 0;
//	}
	
	//生成下半部
	for(i = 0; i < top_num; i++)
	{
		for(j = 1; j < bits; j++)
		{
			buf[(bot_end - i) * bits + j] = buf[i * (bits - 1) + j - 1];
		}
	}
	//下半部首部为1
	for(i = bot_start; i <= bot_end; i++)
	{
		buf[i * bits + 0] = 1;
	}

	//上半部整体后移一位
	for(i = 0; i < top_num; i++)
	{
		for(j = 1; j < bits; j++)
		{
			buf[i * bits + j] = buf[(bot_end - i) * bits + j];
		}
	}
	//上半部首部为0
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

	//共count个格雷码，每个格雷码占用bits个int
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
