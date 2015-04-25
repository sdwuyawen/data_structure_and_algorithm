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
#include <string.h>

//快速排序
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;  
            if(i < j) 
				s[i++] = s[j];
			
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;  
            if(i < j) 
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int j;
    int k;

    int *index;
	int *array;

	int temp;

	array = malloc(sizeof(int) * numsSize);
    index = malloc(sizeof(int) * 2);
	memset(index, 0, sizeof(int) * 2);

	memcpy(array, nums, sizeof(int) * numsSize);

/*  for(i = 0; i < numsSize; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}
*/


	quick_sort(nums, 0 , numsSize - 1);

    for(i = 0, j = numsSize - 1; i != j; )
    {
		if(nums[i] + nums[j] == target)
		{
			
//			printf("nums[%d] = %d\n", i, nums[i]);
//			printf("nums[%d] = %d\n", j, nums[j]);
			
			for(k = 0; k < numsSize; k++)
			{
				if(array[k] == nums[i])
				{
					index[0] = k + 1;
					break;
				}
			}

			for(k = 0; k < numsSize; k++)
			{
				if(array[k] == nums[j])
				{
					index[1] = k + 1;

					if(index[1] != index[0])
					{
						break;
					}
				}
			}

			if(index[0] > index[1])
			{
				temp = index[0];
				index[0] = index[1];
				index[1] = temp;
			}

			*returnSize = 2;

			return index;
		}
		else if(nums[i] + nums[j] < target)
		{
			i++;
		}
		else if(nums[i] + nums[j] > target)
		{
			j--;
		}
	}

    *returnSize = 0;

    return NULL;
}


//int num[] = {2, 11, 7, 15};
//int num[] = {0 , 4, 3 ,0};
int num[] = {-1,-2,-3,-4,-5};
int main(void)
{
	int returnsize;
	int i;
	int *pret_val;

	pret_val = twoSum(num, sizeof(num)/sizeof(num[0]), -8, &returnsize);

	for(i = 0; i < sizeof(num)/sizeof(num[0]); i++)
	{
		printf("num[%d] = %d\n", i, num[i]);
	}

	
	for(i = 0; i < returnsize; i ++)
	{
		printf("#%d = %d\n", i, pret_val[i]);
	}

	return 0;

}
