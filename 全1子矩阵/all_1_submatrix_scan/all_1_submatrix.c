#include <stdio.h>

char matrix[1010][1010] = {0};

unsigned int is_all_one(unsigned int s1, unsigned int s2, unsigned int e1, unsigned int e2, unsigned int *count)
{
	unsigned int x;
	unsigned int y;

	*count = 0;

	for(y = s1; y <= e1; y++)
	{
		for(x = s2; x <= e2; x++)
		{
			if(matrix[y][x] != 1)
			{
				return 0;
			}
			(*count)++;
		}
	}

	return 1;
}

int main(void)
{
	unsigned int m  = 0;
	unsigned int n = 0;

	unsigned int i,j,k,h;

	unsigned int one_count = 0;
	unsigned int max_one_count = 0;

	unsigned int T_count = 0;
	unsigned int T;

//	scanf("%d", &T);

	while(scanf("%d %d", &m, &n) != EOF)
	{
//	for(T_count = 0; T_count < T; T_count++)
//	{
//		printf("input #%d\n", T_count + 1);
//		scanf("%d %d", &m, &n);
		
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		
		max_one_count = 0;
		for(i = 0; i < m; i++)				//起始行坐标
		{
			for(j = 0; j < n; j++)			//起始列坐标
			{
				for(k = i; k < m; k++)		//终止行坐标
				{
					for(h = j; h < n; h++)	//终止列坐标
					{
						if(is_all_one(i, j, k, h, &one_count) == 1)
						{
							if(max_one_count < one_count)
							{
								max_one_count = one_count;
							}
						}
					}
				}
			}
		}
		
		printf("%d\n", max_one_count);
//	}
	}


	return 0;
}