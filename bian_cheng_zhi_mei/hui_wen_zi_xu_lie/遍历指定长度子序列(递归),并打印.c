#include <stdio.h>

#define TRUE	1
#define FALSE	0

int isExhausted(int pointers[], int pointers_length, int length) 
{	//正在处理的子序列位置，序列总长度
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

int Seqs[] = {'a', 'b', 'c', 'd', 'e', 'f'};		//全部序列
int Pointers[] = {0, 1, 2};							//正在处理的子序列位置

void main()
{
	int i;
	int j;

	j = 0;
    while (1) 
	{
		printf("Case %d:\n", j+1);
		j++;

		for(i = 0; i < sizeof(Pointers) / sizeof(Pointers[0]); i++)
		{
			printf("%c ", Seqs[Pointers[i]]);
		}
		printf("\n\n");

        if (!isExhausted(Pointers, sizeof(Pointers) / sizeof(Pointers[0]), sizeof(Seqs) / sizeof(Seqs[0]))) 
		{						//正在处理的子序列位置，序列总长度	
            updatePointers(Pointers, sizeof(Seqs) / sizeof(Seqs[0]), sizeof(Pointers) / sizeof(Pointers[0]) - 1);	//更新正在处理的子序列指针
        } 
		else 
		{
            break;
        }
    } 
}