#if 0

#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	int N;

	int i, j, k;
	int i_max, j_max;
	int array[100010];
	int sum;
	int sum_max;

	scanf("%d", &T);

	for(k = 0; k < T; k++)
	{
		scanf("%d", &N);

		for(i = 0; i < N; i++)
		{
			scanf("%d", &array[i]);
		}
		
		sum_max = 0x00;
		for(i = 0; i < N; i++)
		{
			sum = 0;
			for(j = i; j < N; j++)
			{
				sum += array[j];
				if(sum > sum_max)
				{
					sum_max = sum;
					i_max = i;
					j_max = j;
				}
			}
		}
		
		printf("Case %d:\n", k + 1);
		printf("%d %d %d\n", sum_max, i_max + 1, j_max + 1);	

		if(k != T - 1)
		{
			printf("\n");
		}
	}
}

#endif


#if 1

#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	int N;
	
	int i, j, k;
	int i_start, i_start_last, i_end;
	int array[100010];
	int sum;
	int sum_max;
	
	scanf("%d", &T);
	
	for(k = 0; k < T; k++)
	{
		scanf("%d", &N);
		
		for(i = 0; i < N; i++)
		{
			scanf("%d", &array[i]);
		}
		
		sum_max = (int)0x80000000;
		sum = 0;
		i_start = 0;
		i_start_last = 0;
		i_end = 0;

		for(i = 0; i < N; i++)
		{
			sum += array[i];

			if(sum > sum_max)
			{
				sum_max = sum;
				i_start = i_start_last;
				i_end = i;
			}
			if(sum < 0)
			{
				sum = 0;
				i_start_last = i + 1;
			}
		}
		
		printf("Case %d:\n", k + 1);
		printf("%d %d %d\n", sum_max, i_start + 1, i_end + 1);	
		
		if(k != T - 1)
		{
			printf("\n");
		}
	}
}

#endif

#if 0

#include <stdio.h>
#include <string.h>

static long maxSubSum3(int *a);
static long max3(long a, long b, long c);
long maxSumRec(int *a, int left, int right);

int main(void)
{
	int T;
	int N;
	
	int i, j, k;
	int i_start, i_start_last, i_end;
	int array[100010];
	int sum;
	int sum_max;
	
	scanf("%d", &T);
	
	for(k = 0; k < T; k++)
	{
		scanf("%d", &N);
		
		for(i = 0; i < N; i++)
		{
			scanf("%d", &array[i]);
		}

		sum_max = maxSumRec(array, 0, N - 1);
		
		printf("Case %d:\n", k + 1);
		printf("%d %d %d\n", sum_max, i_start + 1, i_end + 1);	
		
		if(k != T - 1)
		{
			printf("\n");
		}
	}
}

//递归法，复杂度是O(nlogn) 
long maxSumRec(int a[], int left, int right) 
{ 
	int center; 
	long maxLeftSum; 
	long maxRightSum; 
	long maxLeftBorderSum = 0, leftBorderSum = 0; 
	long maxRightBorderSum = 0, rightBorderSum = 0; 
	int i,j;

	if (left == right) 
	{ 
		if (a[left] > 0) 
			return a[left]; 
		else 
			return 0; 
	} 
	center = (left + right) / 2; 
	maxLeftSum = maxSumRec(a, left, center); 
	maxRightSum = maxSumRec(a, center+1, right); 
	
	//求出以左边对后一个数字结尾的序列最大值 
	maxLeftBorderSum = 0, leftBorderSum = 0; 
	for (i = center; i >= left; i--) 
	{ 
		leftBorderSum += a[i]; 
		if (leftBorderSum > maxLeftBorderSum) 
			maxLeftBorderSum = leftBorderSum; 
	} 
	
	//求出以右边对后一个数字结尾的序列最大值 
	maxRightBorderSum = 0, rightBorderSum = 0; 
	for (j = center+1; j <= right; j++) 
	{ 
		rightBorderSum += a[j]; 
		if (rightBorderSum > maxRightBorderSum) 
			maxRightBorderSum = rightBorderSum; 
	} 
	
	return max3(maxLeftSum, maxRightSum,  
		maxLeftBorderSum + maxRightBorderSum); 
} 


//求出三个long中的最大值 
long max3(long a, long b, long c) 
{ 
	if (a < b) 
	{ 
		a = b; 
	} 
	if (a > c) 
		return a; 
	else 
		return c; 
}

#endif