/*
 * =====================================================================================
 *
 *       Filename:  004.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/28/2015 04:36:24 PM
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

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	double last = 0.0;
	double prev = 0.0;

	int i = 0;
	int j = 0;
	int len = nums1Size + nums2Size;

	if(len < 2)
	{
		if(nums1Size == 0 && nums2Size == 0)
		{
			return 0;
		}
		else if(nums1Size != 0)
		{
			return nums1[0];
		}
		else if(nums2Size != 0)
		{
			return nums2[0];
		}
	}

	while(i + j <= len / 2)
	{
		prev = last;
		if(i >= nums1Size)
		{
			last = nums2[j++];
		}
		else if(j >= nums2Size)
		{
			last = nums1[i++];
		}
		else if(nums1[i] < nums2[j])
		{
			last = nums1[i++];
		}
		else
		{
			last = nums2[j++];
		}
	}

	if(len % 2 == 0)
	{
		return (prev + last) / 2.0;
	}
	else
	{
		return last;
	}
}

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
int main(void)
{
	int array1[] = {1, 2, 3, 7, 9, 10};
	int array2[] = {4, 5, 6, 8};
	
	double result;
	int i;

	result = findMedianSortedArrays(array1, ARRAY_SIZE(array1), array2, ARRAY_SIZE(array2));
	
	for(i = 0; i < ARRAY_SIZE(array1); i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n");

	for(i = 0; i < ARRAY_SIZE(array2); i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");

	printf("result = %f\n", result);

	return 0;

}
