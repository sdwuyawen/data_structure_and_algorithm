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
	int len = strlen(s);
	int max_sublen = 0;
	int hash_table[200];
	int start = 0;

	memset(hash_table, -1, sizeof(hash_table));
	for(i = 0; i < len; i++)		//起始位置
	{
		if(hash_table[s[i]] >= start)	//已经重复
		{
			max_sublen = max_sublen >= i - start ? max_sublen : i - start;
			start = hash_table[s[i]] + 1;
		}
		hash_table[s[i]] = i;
	}	

	//处理abcd这种情况，max_sublen没有更新过
	max_sublen = max_sublen >= len - start ? max_sublen : len - start;

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
