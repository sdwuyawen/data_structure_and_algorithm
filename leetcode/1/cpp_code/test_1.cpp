/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2015 12:45:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


vector<int> twoSum(vector<int> &numbers, int target) 
{
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
    	int length = numbers.size();
		map<int,int> mp;
		for(int i = 0; i < length; ++i)
			mp[numbers[i]] = i;
		map<int,int>::iterator it = mp.end();
		for(int i = 0; i < length; ++i)
		{
			it = mp.find(target - numbers[i]);
			if(it != mp.end())
			{
				res.push_back(min(i+1,it->second +1));
				res.push_back(max(i+1,it->second +1));
				break;
			}
		}
		return res;
}


int main()
{
	vector<int> num;
	vector<int> res;
	
	num.push_back(10);
	num.push_back(12);
	num.push_back(13);
	num.push_back(14);

	res = twoSum(num, 27);

	for(int i = 0; i < res.size(); i++)
	{
		cout << i << ": " << res.at(i) << endl;
	}
//	cout << res.at(0) << endl;
//	cout << res.at(1) << endl;



	return 0;
}



