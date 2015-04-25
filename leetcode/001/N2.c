/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/2015 08:55:32 AM
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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
	int i;
	int j;

	int *index;

	index = malloc(sizeof(int) * 2);

	for(i = 0; i < numsSize; i++)
	{
		for(j = i + 1; j < numsSize; j++)
		{
//			printf("i = %d, j = %d\n", i, j);
			
			if(nums[i] + nums[j] == target)
			{
				index[0] = i;
				index[1] = j;
				
				*returnSize = 2;

				return index;
			}
		}
	}

	*returnSize = 0;

	return NULL;
}

int num[] = {2, 11, 7, 15};
int main(void)
{
	int returnsize;
	int i;
	int *pret_val;

	pret_val = twoSum(num, sizeof(num)/sizeof(num[0]), 9, &returnsize);

	for(i = 0; i < returnsize; i ++)
	{
		printf("#%d = %d\n", i, pret_val[i]);
	}

	return 0;

}
