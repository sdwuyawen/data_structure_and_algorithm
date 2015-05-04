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


void insertion_sort(int *A, int N)
{
	int j, P;
	int tmp;

	for(P = 1; P < N; P++)
	{
		tmp = A[P];
		for(j = P; j > 0 && A[j - 1] > tmp; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
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
		
		insertion_sort(array, count);
		
		printf("dst array:");
		for(i = 0; i < count ; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}

}
