/*
 * =====================================================================================
 *
 *       Filename:  013.c
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
#include <stdlib.h>

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
			else if(num >= 800)
			{
				str += "DCCC";
				num -= 800;		
			}
			else if(num >= 700)
			{
				str += "DCC";
				num -= 700;		
			}
			else if(num >= 600)
			{
				str += "DC";
				num -= 600;		
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
			else if(num >= 300)
			{
				str += "CCC";
				num -= 300;		
			}
			else if(num >= 200)
			{
				str += "CC";
				num -= 200;		
			}
			else if(num >= 100)
			{
				str += "C";
				num -= 100;		
			}
		}	
	}
};
