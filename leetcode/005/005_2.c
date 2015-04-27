/*
 * =====================================================================================
 *
 *       Filename:  005.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2015 09:53:39 PM
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

char* longestPalindrome(char* s) 
{
	int i = 0;
	int j = 0;
	int len = 0;
	int max_len = 0;
	int start = 0;
	int end = 0;
	char *str;

	len = strlen(s);

	//判断以i为中心的子字符串，[i - j] 到 [i + j]
	for(i = 0; i < len; i++)
	{
		//从子串中心向两边判断,子串长度是奇数
		for(j = 0; i - j >= 0 && i + j < len; j++)
		{
			if(s[i - j] == s[i + j])
			{
				if(max_len < 2 * j + 1)
				{
					max_len = 2 * j + 1;
					start = i - j;		//子串起始位置
					end = i + j;		//子串终止位置
				}
			}
			else
			{
				break;
			}
		}
	}
	
	//判断以i和i+1为中心的子字符串，[i - j] 到 [i + j + 1]
	for(i = 0; i < len; i++)
	{
		//从子串中心向两边判断，字串长度是偶数
		for(j = 0; i - j >= 0 && i + j + 1 < len; j++)
		{
			if(s[i - j] == s[i + j + 1])
			{
				if(max_len < 2 * j + 2)
				{
					max_len = 2 * j + 2;
					start = i - j;
					end = i + j + 1;
				}
			}
			else
			{
				break;
			}
		}
	}

//	printf("str = %s\n", s);
//	printf("maxlen = %d\n", max_len);

	str = malloc(max_len + 1);
	memcpy(str, s + start, max_len);
	str[max_len] = 0;

	return str;
}

int main(void)
{
	longestPalindrome("abcddcabcd");	
	longestPalindrome("abcdcabcd");	

	return 0;
}
