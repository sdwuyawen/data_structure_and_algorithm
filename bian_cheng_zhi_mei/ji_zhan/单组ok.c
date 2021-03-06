#include <stdio.h>

__int64 A[1010][2] = {0};
__int64 B[110][2] = {0};
unsigned __int64 sum;
unsigned __int64 sum_min = 0xFFFFFFFFFFFFFFFF;

unsigned __int64 cost_B;
unsigned __int64 cost_B_min = 0xFFFFFFFFFFFFFFFF;

__int64 x_min, y_min;



int main(void)
{
	unsigned int T;

	unsigned int N;			//列数
	unsigned int M;			//行数
	unsigned int A_count;			//用户行数
	unsigned int B_count;			//公司行数

	__int64 i;
	__int64 j;
	__int64 k;

	__int64 temp1, temp2;
	__int64 temp3, temp4;

	scanf("%d %d %d %d", &N, &M, &A_count, &B_count);

	for(i = 0; i < A_count; i++)
	{
		scanf("%d %d", &A[i][0], &A[i][1]);
	}

	for(i = 0; i < B_count; i++)
	{
		scanf("%d %d", &B[i][0], &B[i][1]);
	}

	//遍历，寻找最小值
	for(i = 1; i <= M; i++)		//基站所在行
	{
		for(j = 1; j <= N; j++)	//基站所在列
		{
			sum = 0;

			printf("i = %I64u, j = %I64u\n", i, j);

			for(k = 0; k < A_count; k++)
			{
				temp1 = A[k][0] - i;
				temp2 = A[k][1] - j;
				sum += temp1 * temp1 + temp2 * temp2;
			}
			
			cost_B_min = 0xFFFFFFFFFFFFFFFF;
			for(k = 0; k < B_count; k++)
			{
				if(B[k][0] >= i)
				{
					temp3 = B[k][0] - i;
				}
				else
				{
					temp3 = i - B[k][0];
				}

				if(B[k][1] >= j)
				{
					temp4 = B[k][1] - j;
				}
				else
				{
					temp4 = j - B[k][1];
				}

				cost_B = temp3 + temp4;

				if(cost_B < cost_B_min)
				{
					cost_B_min = cost_B;
				}
			}

			sum += cost_B_min;

			if(sum < sum_min)
			{
				sum_min = sum;

				x_min = i;
				y_min = j;

				printf("sum_min = %I64u, x_min = %I64d, y_min = %I64d\n", sum_min, x_min, y_min);
			}
		}
	}

	printf("sum_min = %I64u, x_min = %I64d, y_min = %I64d\n", sum_min, x_min, y_min);

}