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
//			���ڴ����������λ�ã�   �����г��ȣ�		�����ܳ���
int isExhausted(int pointers[], int pointers_length, int length) 
{	
    int i;
	for (i = pointers_length - 1; i >= 0; i--)					//������ָ�붼˳��ָ��pointers��ĩβ֮�󣬲Ż᷵��TRUE
	{
        if (pointers[i] != length - (pointers_length - i)) 
		{
            return FALSE;
        }
    }
    return TRUE;
}
//				���ڴ����������λ�ã������ܳ��ȣ�Ҫ���µ�ָ������
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

char Seqs[1010] = {0};										//ȫ������
char sub_seq[1010] = {0};										//���ж�������
int Pointers[1010] = {0};							//���ڴ����������λ��

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

	scanf("%d", &T);					//��������

	for(T_count = 0; T_count < T; T_count++)
	{
		scanf("%s", Seqs);					//��ȡ�������ַ���
		seq_len = strlen(Seqs);				//�������ַ�������

		hui_wen_subseq_count = 0;
		
		for(k = 1; k <= seq_len; k++)			//Ҫ����������г���
		{
			for(m = 0; m < k; m++)
			{
				Pointers[m] = m;				//��ʼ��������������λ��
			}	
			
			while (1) 
			{
				for(i = 0; i < k; i++)			//��ӡ������������
				{
					sub_seq[i] = Seqs[Pointers[i]];
				}
				sub_seq[i] = 0;
				
				if(is_hui_wen(sub_seq, strlen(sub_seq)) == TRUE)
				{
					hui_wen_subseq_count++;
				}
				
				if (!isExhausted(Pointers, k, seq_len))
				{				//���ڴ����������λ�ã������ܳ���	
					updatePointers(Pointers, seq_len, k - 1);	//�������ڴ����������ָ��
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