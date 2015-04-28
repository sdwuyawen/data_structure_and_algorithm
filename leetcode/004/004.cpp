/*
 * =====================================================================================
 *
 *       Filename:  004.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  04/28/2015 06:56:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

//返回a和b中从小到大第k个数
double findKth(int a[], int m, int b[], int n, int k)
{
	//always assume that m is equal or smaller than n
	if (m > n)
		return findKth(b, n, a, m, k);
	//a中已经空，则b中从小到大第k个数就是a和b中的从小到大第k个数
	if (m == 0)
		return b[k - 1];
	//a和b中都非空，且返回从小到大第1个数，则返回a和b中的最小值
	if (k == 1)
		return min(a[0], b[0]);

	//divide k into two parts
	int pa = min(k / 2, m), pb = k - pa;
	//如果A[k/2 - 1] < B[k/2 - 1]，则从小到大第k个数不在A[0]到A[k/2 - 1]中
	if (a[pa - 1] < b[pb - 1])
		return findKth(a + pa, m - pa, b, n, k - pa);
	//如果A[k/2 - 1] > B[k/2 - 1]，则从小到大第k个数不在B[0]到B[k/2 - 1]中
	else if (a[pa - 1] > b[pb - 1])
		return findKth(a, m, b + pb, n - pb, k - pb);
	else
		return a[pa - 1];
}

class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		//总个数是奇数，则返回第total/2 - 1小的数。例如，一共5个数，则返回从小到大第3个数
		if (total & 0x1)
			return findKth(A, m, B, n, total / 2 + 1);
		//总个数是偶数，则返回第total/2小和total/2 + 1小的数。例如，一共4个数，则返回从小到大第2和第3个数的平均值
		else
			return (findKth(A, m, B, n, total / 2)
					+ findKth(A, m, B, n, total / 2 + 1)) / 2;
	}
};

