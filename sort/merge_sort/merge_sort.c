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

/* Lpos = start of left half, Rpos = start of right half */

void Merge( int A[ ], int TmpArray[ ], int Lpos, int Rpos, int RightEnd )
{
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	/* main loop */
	while( Lpos <= LeftEnd && Rpos <= RightEnd )
		if( A[ Lpos ] <= A[ Rpos ] )
			TmpArray[ TmpPos++ ] = A[ Lpos++ ];
		else
			TmpArray[ TmpPos++ ] = A[ Rpos++ ];

	while( Lpos <= LeftEnd )  /* Copy rest of first half */
		TmpArray[ TmpPos++ ] = A[ Lpos++ ];
	while( Rpos <= RightEnd ) /* Copy rest of second half */
		TmpArray[ TmpPos++ ] = A[ Rpos++ ];

	/* Copy TmpArray back */
	for( i = 0; i < NumElements; i++, RightEnd-- )
		A[ RightEnd ] = TmpArray[ RightEnd ];
}


void MSort( int A[ ], int TmpArray[ ], int Left, int Right )
{
	int Center;

	if( Left < Right )
	{
		Center = ( Left + Right ) / 2;
		MSort( A, TmpArray, Left, Center );
		MSort( A, TmpArray, Center + 1, Right );
		Merge( A, TmpArray, Left, Center + 1, Right );
	}
}

void Mergesort( int A[ ], int N )
{
	int *TmpArray;

	TmpArray = malloc( N * sizeof( int ) );
	if( TmpArray != NULL )
	{
		MSort( A, TmpArray, 0, N - 1 );
		free( TmpArray );
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
                                                                                                               
        Mergesort(array, count);                                                                            
                                                                                                               
        printf("dst array:");                                                                                  
        for(i = 0; i < count ; i++)                                                                            
        {                                                                                                      
            printf("%d ", array[i]);                                                                           
        }                                                                                                      
        printf("\n");                                                                                          
    }                                                                                                          
                                                                                                               
}        
