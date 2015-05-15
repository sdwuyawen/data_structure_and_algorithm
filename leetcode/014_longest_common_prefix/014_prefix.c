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

	char *str_prefix;
	char *str;

	char *str_ret;

//	if(strs == NULL)
//	{
//		return NULL;
//	}

	if(strsSize != 0)
	{
		str_prefix = *strs;
//		str = *(++strs);

		common_length = strlen(str_prefix);

		//待比较的字符串位置
		for(j = 1; j < strsSize; j++)
		{
//			if(str1 == NULL || str2 == NULL)
//			{
//				return NULL;
//			}
			str = *(++strs);
			common_length = common_length < strlen(str) ? common_length : strlen(str);
			for(i = 0; i < common_length; i++)
			{
				if(str_prefix[i] != str[i])
				{
					break;
				}
			}
			common_length = i;

//			//共需要比较N-1次，最后一次比较时不再移动指针到下一个字符串
//			if(j <= strsSize - 1)
//			{
//				str = *(++strs);
//			}
		}
	}

	str_ret = (char *)malloc(common_length + 1);
	memcpy(str_ret, str_prefix, common_length);
	str_ret[common_length] = 0x00;

//	printf("common length = %d\n", common_length);
//	printf("common str = %s\n", str_ret);

	return str_ret;
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

//		for(i = 0; i < num; i++)
//		{
//			scanf("%s", pchar[i]);
//		}

		str[0][0] = 0x00;
		str[1][0] = 0x00;
		str[2][0] = 0x00;

		longestCommonPrefix(pchar, 3);
	}
	return 0;
}

