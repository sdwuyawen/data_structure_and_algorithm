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

#define LeftChild(x)	(2 * (x) + 1)

void swap(int *a, int *b)
{
	int num;

	num = *a;
	*a = *b;
	*b = num;
}

void perc_down( int A[ ], int i, int N )
{
	int Child;
	int Tmp;

	for( Tmp = A[ i ]; LeftChild( i ) < N; i = Child )
	{
		Child = LeftChild( i );
		if( Child != N - 1 && A[ Child + 1 ] > A[ Child ] )
			Child++;
		if( Tmp < A[ Child ] )
			A[ i ] = A[ Child ];
		else
			break;                                                                                   
	}                                                                                                
	A[ i ] =Tmp;                                                                                     
}                                                                                                    

void heap_sort( int A[ ], int N )                                                                  
{                                                                                                    
	int i;                                                                                           

	for( i = N / 2; i >= 0; i-- )  /* BuildHeap */                                                   
		perc_down( A, i, N );                                                                         
	for( i = N - 1; i > 0; i-- )                                                                     
	{                                                                                                
		swap( &A[ 0 ], &A[ i ] );  /* DeleteMax */                                                   
		perc_down( A, 0, i );                                                                         
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

		heap_sort(array, count);

		printf("dst array:");
		for(i = 0; i < count ; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}

}
