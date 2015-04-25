#include <stdio.h>

char matrix[1010][1010] = {0};
int upperbound[1010][1010] = {0};

//proc_col�Ե�col�м���ÿ��x[i][col]��upperbound�����upperbound���ǣ��ڵ�ǰ�У�
//����x[i][col]�������ķ������еĺͣ������[0 3 4 3 5 2 1]������6����upperbound����
//3 + 4 + 3 + 5 + 2 + 1 = 18������0Ԫ�أ�����Ҫupperbound
void proc_col(int col, int m, int n) 
{
	int i;
	int sum = 0, j;
	int k;

    for (i = 0; i < m; i++) 
	{
        if (matrix[i][col] == 0) 
		{
            continue;
        }
        sum = 0, j = i;
        while (j < m && matrix[j][col] > 0) 
		{
            sum += matrix[j][col];
            j++;
        }
        for (k = i; k < j; k++) 
		{
            upperbound[k][col] = sum;
        }
        i = j;//֮��i����++�����ǲ���������Ҫ��ֵ����Ϊ��ʱx[j][]=0���ڽ���
    }
}
//���м���upperbound
void calc_upper(int m, int n)
{
	int col = 0;

    for (col = 0; col < n; col++) 
	{
        proc_col(col, m, n);
    }
}

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
	int value = 0;
	
	value = matrix[row][column];
	count = 1;

	for(i = row - 1; i >= 0; i--)
	{
		if(matrix[i][column] >= value)
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
		if(matrix[i][column] >= value)
		{
			count ++;
		}
		else
		{
			break;
		}
	}
	
	return(value * count);
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
			if(matrix[i][j] >= 1)						//Ԥ�����ԭ����1��λ�ö�>=1
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


	while(scanf("%d %d", &m, &n) != EOF)
	{
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		
		pre_process(m, n);					//��ÿ��1Ԫ�أ��滻����֮ǰ����1�ĸ���
//		calc_upper(m,n);
		
		max_one_count = search_max_submatrix(m, n);
		
		printf("%d\n", max_one_count);
	}


	return 0;
}