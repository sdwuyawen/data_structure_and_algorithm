/*
 * =====================================================================================
 *
 *       Filename:  013.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2015 02:29:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	string intToRoman(int num) 
	{
		int threshold[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string str_thre[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		string str;
		int i;

		for(i = 0; i < sizeof(threshold) / sizeof(threshold[0]); i++)
		{
			while(num >= threshold[i])
			{
				str += str_thre[i];
				num -= threshold[i];
			}
		}

		return str;		
	}
};

int main(void)
{
	class Solution solution;
	int value;
	string str;

	while(1)
	{
		cin >> value;

		str = solution.intToRoman(value);	

		cout << str << endl;
	}


	return 0;
}
