/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/05/2015 08:36:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

void Swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort( int A[ ], int N )
{
	int j, P;
	int Tmp;

	for( P = 1; P < N; P++ )
	{
		Tmp = A[ P ];
		for( j = P; j > 0; j-- )
		{
			if(A[ j - 1 ] > Tmp)
			{
				A[ j ] = A[ j - 1 ];
			}
			else
				break;
		}

		A[ j ] = Tmp;
	}
}

/* Return median of Left, Center, and Right */
/* Order these and hide the pivot */

int Median3( int A[ ], int Left, int Right )
{
	int Center = ( Left + Right ) / 2;

	if( A[ Left ] > A[ Center ] )
		Swap( &A[ Left ], &A[ Center ] );
	if( A[ Left ] > A[ Right ] )
		Swap( &A[ Left ], &A[ Right ] );
	if( A[ Center ] > A[ Right ] )
		Swap( &A[ Center ], &A[ Right ] );

	/* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */

	Swap( &A[ Center ], &A[ Right - 1 ] );  /* Hide pivot */
	return A[ Right - 1 ];                /* Return pivot */
}

#define Cutoff ( 3 )

void Qsort( int A[ ], int Left, int Right )
{
	int i, j;
	int Pivot;

	if( Left + Cutoff <= Right )
	{
		Pivot = Median3( A, Left, Right );
		i = Left; j = Right - 1;
		for( ; ; )
		{
			while( A[ ++i ] < Pivot ){ }
			while( A[ --j ] > Pivot ){ }
			if( i < j )
				Swap( &A[ i ], &A[ j ] );
			else
				break;
		}
		Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */

		Qsort( A, Left, i - 1 );
		Qsort( A, i + 1, Right );
	}
	else  /* Do an insertion sort on the subarray */
		InsertionSort( A + Left, Right - Left + 1 );
}

/* This code doesn't work; it's Figure 7.15. */
#if 0
i = Left + 1; j = Right - 2;
for( ; ; )
{
	while( A[ i ] < Pivot ) i++;
	while( A[ j ] > Pivot ) j--;
	if( i < j )
		Swap( &A[ i ], &A[ j ] );
	else
		break;
}
#endif

void Quicksort( int A[ ], int N )
{
	Qsort( A, 0, N - 1 );
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

		Quicksort(array, count);

		printf("dst array:");
		for(i = 0; i < count ; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}

}

