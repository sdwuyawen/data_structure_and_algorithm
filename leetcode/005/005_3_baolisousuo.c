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
	int k = 0;

	int len = 0;
	int sub_len = 0;
	int max_len = 0;
	int start = 0;
	int end = 0;
	char *str;

	len = strlen(s);

	//子串从[i]到[j]
	for(i = 0; i < len; i++)
	{
		for(j = i; j < len; j++)
		{
			//判断该字串是否是回文串
			sub_len = j - i + 1;
			for(k = 0; k <= (sub_len - 1) / 2; k++)
			{
				if(s[i + (k)] == s[i + (sub_len - 1 - k)])
				{
					
				}
				else
				{
					break;
				}
			}

			if(k > (sub_len - 1) / 2)
			{
				if(max_len < sub_len)
				{
					max_len = sub_len;
					start = i;
					end = j;
				}
			}
		}
	}
	


	printf("str = %s\n", s);
	printf("maxlen = %d\n", max_len);

	str = malloc(max_len + 1);
	memcpy(str, s + start, max_len);
	str[max_len] = 0;

	return str;
}

int main(void)
{
	longestPalindrome("abcddcabcd");	
	longestPalindrome("abcdcabcd");	
	longestPalindrome("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");	

	return 0;
}
