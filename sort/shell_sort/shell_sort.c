/*
 * =====================================================================================
 *
 *       Filename:  shell_sort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2015 04:04:22 PM
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

void shell_sort(int A[], int N)                                                                 
{                                                                                                    
	int i, j, increment;                                                                             
	int tmp;                                                                                 

	for(increment = N / 2; increment > 0; increment /= 2)                                          
	{
		for(i = increment; i < N; i++)                                                             
		{                                                                                            
			tmp = A[i];                                                                            
			for(j = i; j >= increment; j -= increment)                                             
			{
				if(A[j - increment] > tmp)                                                       
					A[j] = A[j - increment];                                                     
				else                                                                                 
					break;                                                                           
			}
			A[j] = tmp;                                                                            
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

        shell_sort(array, count);

        printf("dst array:");
        for(i = 0; i < count ; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

}      
