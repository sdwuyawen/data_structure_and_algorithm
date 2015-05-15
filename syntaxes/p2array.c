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
//#include <string.h>
//#include <stdlib.h>

//using namespace std;


//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>



char a[3][4] = {{0, 1, 2 ,3},
				{4, 5, 6 ,7},
				{8, 9, 10 ,11},};

char *pchar = &a[0][0];
char (*p2array)[4] = a;


char *b[][2] =
{
		{
			"str0",
			"str1",
		},
		{
			"str2",
			"str3",
		},
};

char **ppchar = &b[0][0];

int main(void)
{
	printf("%s", *ppchar++);
	printf("%s", *ppchar++);
	printf("%s", *ppchar++);
	printf("%s", *ppchar++);

	return 0;
}


