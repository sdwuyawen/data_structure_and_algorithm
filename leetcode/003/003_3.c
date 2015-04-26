/*
 * =====================================================================================
 *
 *       Filename:  003.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2015 05:20:39 PM
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

int lengthOfLongestSubstring(char* s) 
{
	int i;
	int j;
	int k;
	int len = strlen(s);
	int max_sublen = 0;
	int hash_table[200];

	for(i = 0; i < len; i++)		//起始位置
	{
		for(j = i; j < len; j++)	//终止位置
		{
			//判断子串是否有相同字符[i], [j]
			memset(hash_table, 0, sizeof(hash_table));
			for(k = i; k <= j; k++)
			{
				if(hash_table[s[k]] != 0)
				{
					break;
				}
				else
				{
					hash_table[s[k]] = 1;
				}
			}

			if(k > j)
			{
				if(max_sublen < j - i + 1)
				{
					max_sublen = j - i + 1;
				}
			}
			else
			{
				break;	
			}
		}
	}	

	return max_sublen;
}

int main(void)
{
	char str[100];

	while(1)
	{
		scanf("%s", str);
		printf("max_sub_len = %d\n", lengthOfLongestSubstring(str));
	}

	return 0;
}
