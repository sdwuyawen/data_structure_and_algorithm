#include <stdio.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

int is_hui_wen(char str[], int len)
{
	int i;

	for(i = 0; i <= (len - 1) / 2; i++)
	{
		if(str[i] != str[len - 1 - i])
		{
			return FALSE;
		}
	}

	return TRUE;
}
//			正在处理的子序列位置，   子序列长度，		序列总长度
int isExhausted(int pointers[], int pointers_length, int length) 
{	
    int i;
	for (i = pointers_length - 1; i >= 0; i--)					//当所有指针都顺序指向pointers的末尾之后，才会返回TRUE
	{
        if (pointers[i] != length - (pointers_length - i)) 
		{
            return FALSE;
        }
    }
    return TRUE;
}
//				正在处理的子序列位置，序列总长度，要更新的指针索引
void updatePointers(int pointers[], int length, int curPos) 
{	
    if (pointers[curPos] + 1 <= length - 1) 
	{
        pointers[curPos]++;
    } 
	else 
	{
        updatePointers(pointers, length - 1, curPos - 1);
        pointers[curPos] = pointers[curPos - 1] + 1;
    }
    return;
}

char Seqs[1010] = {0};										//全部序列
char sub_seq[1010] = {0};										//待判断子序列
int Pointers[1010] = {0};							//正在处理的子序列位置

int main(void)
{
	int T;
	int T_count;

	int i;
	int j;
	int k;
	int m;

	int seq_len = 0;
	int hui_wen_subseq_count = 0;

	scanf("%d", &T);					//数据组数

	for(T_count = 0; T_count < T; T_count++)
	{
		scanf("%s", Seqs);					//读取待处理字符串
		seq_len = strlen(Seqs);				//待处理字符串长度

		hui_wen_subseq_count = 0;
		
		for(k = 1; k <= seq_len; k++)			//要处理的子序列长度
		{
			for(m = 0; m < k; m++)
			{
				Pointers[m] = m;				//初始化待处理子序列位置
			}	
			
			while (1) 
			{
				for(i = 0; i < k; i++)			//打印待处理子序列
				{
					sub_seq[i] = Seqs[Pointers[i]];
				}
				sub_seq[i] = 0;
				
				if(is_hui_wen(sub_seq, strlen(sub_seq)) == TRUE)
				{
					hui_wen_subseq_count++;
				}
				
				if (!isExhausted(Pointers, k, seq_len))
				{				//正在处理的子序列位置，序列总长度	
					updatePointers(Pointers, seq_len, k - 1);	//更新正在处理的子序列指针
				} 
				else 
				{
					break;
				}
			} 
		}	
		hui_wen_subseq_count %= 100007;
		printf("Case #%d: %d\n", T_count + 1,hui_wen_subseq_count);
	}
	
	return 0;
}