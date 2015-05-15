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
		string str;

		while(num != 0)
		{
			if(num >= 1000)
			{
				str += "M";
				num -= 1000;		
			}
			else if(num >= 900)
			{
				str += "CM";
				num -= 900;		
			}
			else if(num >= 500)
			{
				str += "D";
				num -= 500;		
			}
			else if(num >= 400)
			{
				str += "CD";
				num -= 400;		
			}
			else if(num >= 100)
			{
				str += "C";
				num -= 100;		
			}


			else if(num >= 90)
			{
				str += "XC";
				num -= 90;		
			}
			else if(num >= 50)
			{
				str += "L";
				num -= 50;		
			}
			else if(num >= 40)
			{
				str += "XL";
				num -= 40;		
			}
			else if(num >= 10)
			{
				str += "X";
				num -= 10;		
			}


			else if(num >= 9)
			{
				str += "IX";
				num -= 9;		
			}
			else if(num >= 5)
			{
				str += "V";
				num -= 5;		
			}
			else if(num >= 4)
			{
				str += "IV";
				num -= 4;		
			}
			else if(num >= 1)
			{
				str += "I";
				num -= 1;		
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
