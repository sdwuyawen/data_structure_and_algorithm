/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2015 02:39:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>


//冒泡排序1
void bubble_sort1(int a[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{	
			if (a[j - 1] > a[j])
			{		
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

//冒泡排序2
void bubble_sort2(int a[], int n)
{
	int i, j;
	int temp;
	int flag;

	for (i = 0; i < n; i++)
	{
		flag = 0;
		
		for (j = 1; j < n - i; j++)
		{	
			if (a[j - 1] > a[j])
			{		
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

				flag = 1;
			}
		}

		//如果有一趟没有发生交换，则之后的所有趟也不会发生交换，排序完成
		if(flag == 0)
		{
			break;
		}

	}
}


int main(void)
{
	int array[100];
	int i;
	int count;

	while(1)
	{
		scanf("%d", &count);

		for(i = 0; i < count ; i++)
		{
			scanf("%d", array + i);
		}

		printf("src array:");
		for(i = 0; i < count ; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");

		bubble_sort2(array, count);

		printf("dst array:");
		for(i = 0; i < count ; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}

}
