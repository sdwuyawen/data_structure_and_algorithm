/*
 * =====================================================================================
 *
 *       Filename:  011.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/14/2015 08:55:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

//============================================================================
// Name        : cpp_test.cpp
// Author      : WYW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



//#include <iostream>
//#include <vector>
//#include <stack>
//#include <map>
//#include <string>
//#include <sstream>				//stringstream类型的头文件

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//using namespace std;


//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>


char* longestCommonPrefix(char **strs, int strsSize)
{
	int common_length = 0;

	int i;
	int j;

	char *str1;
	char *str2;

	char *str;

//	if(strs == NULL)
//	{
//		return NULL;
//	}

	if(strsSize != 0)
	{
		str1 = *strs;
		str2 = *(strs + 1);

		common_length = strlen(str1);

		for(j = 0; j < strsSize - 1; j++)
		{
//			if(str1 == NULL || str2 == NULL)
//			{
//				return NULL;
//			}
			common_length = common_length < strlen(str2) ? common_length : strlen(str2);
			for(i = 0; i < common_length; i++)
			{
				if(str1[i] != str2[i])
				{
					break;
				}
			}
			common_length = i;

			strs++;
			str1 = *strs;
			str2 = *(strs + 1);
		}
	}

	str = (char *)malloc(common_length + 1);
	memcpy(str, *strs, common_length);
	str[common_length] = 0x00;

//	printf("common length = %d\n", common_length);
//	printf("common str = %s\n", str);

	return str;
}


int main(void)
{
	char str[10][100];
	char *pchar[10];
	int i;
	int num;

	for(i = 0; i < 10; i++)
	{
		pchar[i] = str[i];
	}

	while(1)
	{
		scanf("%d", &num);

		for(i = 0; i < num; i++)
		{
			scanf("%s", pchar[i]);
		}

		longestCommonPrefix(pchar, num);
	}
	return 0;
}

