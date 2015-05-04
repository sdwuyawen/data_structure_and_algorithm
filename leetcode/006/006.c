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
//		for(j = 0, index =  i; ; j++)

		j = 0;
		while(1)
		{
			if(numRows == 1)	//只有一行时，不符合下面的规律
			{
				index = j;
			}
			else
			{
				index = (numRows - 1) * 2 * j + i;
			}
			
			j++;

			if(index >= len)
			{
				break;
			}

			str[k++] = s[index];

			//不是第0行或最后一行，则插入中间斜边的元素
			if(i != 0 && i != numRows - 1)
			{
				if((numRows - 1 - i) * 2 + index < len)
				{
					str[k++] = s[(numRows - 1 - i) * 2 + index];
				}
			}
			
		}
	}
//	str[len] = 0;
	return str;
}

int main(void)
{
//	char *strsrc = "PAYPALISHIRING";
	char *strsrc = "A";
	char *strdst;
	strdst = convert(strsrc, 3);
	printf("len = %d, %s\n", strlen(strsrc), strsrc);
	printf("len = %d, %s\n", strlen(strdst), strdst);

	return 0;
}
