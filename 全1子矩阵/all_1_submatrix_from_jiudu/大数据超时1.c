#include <stdio.h>

char matrix[1010][1010] = {0};

void pre_process(int m, int n)
{
	int i;
	int j;

	for(i = 0; i < m; i++)		//rows
	{
		for(j = 1; j < n; j++)	//from column 1
		{
			if(matrix[i][j] == 1)
			{
				matrix[i][j] += matrix[i][j-1];
			}
		}
	}
}

unsigned int search_up_down(int row, int column, int m, int n)
{
	int i;
	unsigned int count = 0;
	
	count = 1;

	for(i = row - 1; i >= 0; i--)
	{
		if(matrix[i][column] >= matrix[row][column])
		{
			count ++;
		}
		else
		{
			break;
		}
	}
	
	for(i = row + 1; i < m; i++)
	{
		if(matrix[i][column] >= matrix[row][column])
		{
			count ++;
		}
		else
		{
			break;
		}
	}
	
	return(matrix[row][column] * count);
}


unsigned int search_max_submatrix(int m, int n)
{
	int i;
	int j;
	int max = 0;
	int value = 0;
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(matrix[i][j] >= 1)						//预处理后，原来是1的位置都>=1
			{
				value = search_up_down(i, j, m, n);
				if(max < value)
				{
					max = value;
				}
			}	
		}
	}
	return max;
}

int main(void)
{
	unsigned int m  = 0;
	unsigned int n = 0;

	unsigned int i,j;

	unsigned int max_one_count = 0;

	unsigned int T_count = 0;
	unsigned int T;

//	for(T_count = 0; T_count < T; T_count++)
//	{
//		printf("input #%d\n", T_count + 1);
		while(scanf("%d %d", &m, &n) != EOF)
		{
			for(i = 0; i < m; i++)
			{
				for(j = 0; j < n; j++)
				{
					scanf("%d", &matrix[i][j]);
				}
			}
			
			pre_process(m, n);					//把每个1元素，替换成它之前连续1的个数
			
			max_one_count = search_max_submatrix(m, n);
			
			printf("%d\n", max_one_count);
		}
//	}


	return 0;
}