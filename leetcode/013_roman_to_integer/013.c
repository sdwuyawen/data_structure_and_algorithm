//============================================================================
// Name        : cpp_test.cpp
// Author      : WYW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



//#include <iostream>
//#include <stack>
//#include <map>

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

//using namespace std;


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int romanToInt(char* s)
{
	unsigned int len = strlen(s);
	unsigned int i;
	unsigned int sum = 0;
	unsigned char *ss = (unsigned char *)s;

	unsigned int hash[200] = {0};

	unsigned int threshold[] = {1000, 500, 100, 50, 10, 5, 1};
	unsigned char str_thre[] = {'M', 'D',  'C', 'L', 'X', 'V', 'I' };

	//构建哈希表
	for(i = 0; i < sizeof(threshold)/sizeof(threshold[0]); i++)
	{
		hash[str_thre[i]] = threshold[i];
	}

	for(i = 0; i < len - 1; )
	{
		if(hash[ss[i]] >= hash[ss[i+1]])
		{
			sum += hash[ss[i]];
			i++;
		}
		else
		{
			sum += hash[ss[i+1]] - hash[ss[i]];
			i += 2;
		}
	}

	//检测最后一个字符是否尚未处理
	if(i == len - 1)
	{
		sum += hash[ss[i]];
	}

	return sum;
}


int main(void)
{
	char str[1000];
	int ret;

	while(1)
	{
		scanf("%s", str);
		ret = romanToInt(str);
		printf("%s = %d\n", str, ret);
	}

	return 0;
}


