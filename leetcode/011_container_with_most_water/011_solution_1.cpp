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



#include <iostream>
#include <vector>
//#include <stack>
//#include <map>
//#include <string>
//#include <sstream>				//stringstream类型的头文件

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

using namespace std;


//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
		int l = 0;
		int r = height.size() - 1;
		int k;

		int ret = 0;

		while(l < r)
		{
			ret = max(ret, (r - l) * min(height[l], height[r]));

			if(height[l] < height[r])		//从左侧开始向里推进
			{
				k = l;
				while(k < r && height[k] <= height[l])
				{
					k++;
				}

				l = k;
			}
			else							//从右侧开始推进
			{
				k = r;
				while(k > l && height[k] <= height[r])
				{
					k--;
				}

				r = k;
			}

		}

    	return ret;
    }
};


int main(void)
{
	Solution solution;
	vector<int> heights;
	int input;
	int value;

//	while(1)
	{
		while(cin >> input)
		{
			heights.push_back(input);
		}

		value = solution.maxArea(heights);

		cout << value;
	}

	return 0;
}


