/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/24/2015 03:30:34 PM
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

		quick_sort(array, 0, count - 1);

		printf("dst array:");
		for(i = 0; i < count ; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}

}

