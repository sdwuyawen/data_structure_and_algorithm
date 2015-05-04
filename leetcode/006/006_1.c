/*
 * =====================================================================================
 *
 *       Filename:  006.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/28/2015 10:22:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* convert(char* s, int numRows) 
{
	int i = 0;
	int j = 0;
	int k = 0;
	int index;
	int len = strlen(s);
	char *str = malloc(len + 1);

	memset(str, 0, len + 1);

	//行
	for(i = 0; i < numRows; i ++)
	{
		//列
		for(j = 0, index =  i; ; j++)
		{
			index = (numRows - 1) * 2 * j + i;

			if(index >= len)
			{
				break;
			}

			str[k++] = s[index];

			if(i != 0 && i != numRows - 1)
			{
				if((numRows - 1 - i) * 2 + index < len)
				{
					str[k++] = s[(numRows - 1 - i) * 2 + index];
				}
			}
			
		}
	}
	str[len] = 0;
	return str;
}

int main(void)
{
	char *strsrc = "PAYPALISHIRING";
//	char *strsrc = "A";
	char *strdst;
	strdst = convert(strsrc, 1);
	printf("len = %d, %s\n", strlen(strsrc), strsrc);
	printf("len = %d, %s\n", strlen(strdst), strdst);

	return 0;
}
