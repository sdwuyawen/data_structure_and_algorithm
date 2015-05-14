//============================================================================
// Name        : cpp_test.cpp
// Author      : WYW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
//#include <stack>
#include <map>
#include <string>
#include <sstream>				//stringstream类型的头文件

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
    int romanToInt(string s)
    {
    	unsigned int threshold[] = {1000, 500, 100, 50, 10, 5, 1};
    	string str_thre[] = {"M", "D",  "C", "L", "X", "V", "I" };

    	unsigned int len = s.length();
    	unsigned int i;
    	int sum = 0;
    	int value1, value2;

    	//char转string
    	stringstream stream;
    	string str;

    	map<string, int> mp;
    	map<string, int>::iterator it = mp.end();

    	//构建哈希表
    	for(i = 0; i < sizeof(str_thre)/sizeof(str_thre[0]); i++)
    	{
//    		mp[str_thre[i]] = threshold[i];
    		mp.insert(make_pair(str_thre[i], threshold[i]));
    	}

    	for(i = 0; i < len - 1; )
    	{
    		stream.str("");					//清空stream
    		stream << s.at(i);
    		it = mp.find(stream.str());
    		if(it != mp.end())
    		{
    			value1 = it->second;
    		}

    		stream.str("");					//清空stream
    		stream << s.at(i + 1);
    		it = mp.find(stream.str());
			if(it != mp.end())
			{
				value2= it->second;
			}
    		if(value1 >= value2)
    		{
    			sum += value1;
    			i++;
    		}
    		else
    		{
    			sum += value2 - value1;
    			i += 2;
    		}
    	}

    	//检测最后一个字符是否尚未处理
    	if(i == len - 1)
    	{
    		stream.str("");					//清空stream
    		stream << s.at(i);
    		it = mp.find(stream.str());
			if(it != mp.end())
			{
				sum += it->second;
			}
    	}

    	return sum;
    }
};



int main(void)
{
	string str;
	Solution solution;

	while(1)
	{
		cin >> str;
		cout << solution.romanToInt(str);
	}

	return 0;
}


