#include <stdio.h>

/*
 * 假如有一组数为3，12，24，36，55，68，75，88要查给定的值24.可设三个变量front，mid，end分别指向数据的上界，中间和下界，mid=（front+end）/2.
 * 1.开始令front=0（指向3），end=7（指向88），则mid=3（指向36）。因为mid>x，故应在前半段中查找。
 * 2.令新的end=mid-1=2，而front=0不变，则新的mid=1。此时x>mid，故确定应在后半段中查找。
 * 3.令新的front=mid+1=2，而end=2不变，则新的mid=2，此时a[mid]=x，查找成功。
 * 如果要查找的数不是数列中的数，例如x=25，当第三次判断时，x>a[mid]，按以上规律，令front=mid+1，即front=3，出现front>end的情况，表示查找不成功。
 * 例：在有序的有N个元素的数组中查找用户输进去的数据x。
 * 算法如下：
 * 1.确定查找范围front=0，end=N-1，计算中项mid=（front+end）/2。
 * 2.若a[mid]=x或front>=end,则结束查找；否则，向下继续。
 * 3.若a[mid]<x,说明待查找的元素值只可能在比中项元素大的范围内，则把mid+1的值赋给front，并重新计算mid，转去执行步骤2；若a[mid]>x，说明待查找的元素值只可能在比中项元素小的范围内，则把mid-1的值赋给end，并重新计算mid，转去执行步骤2。
*/

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

//递归算法
int recurbinary(int *a,int key,int low,int high)
{
	int mid;
	if(low > high)
		return -1;
	mid = (low + high) / 2;
	if(a[mid] == key) return mid;
	else if(a[mid] > key)
		return recurbinary(a, key, low, mid - 1);
	else
		return recurbinary(a, key, mid + 1, high);
}

//非递归算法
int binary( int *a, int key, int n )
{
	int left = 0, right = n - 1, mid = 0;
	mid = ( left + right ) / 2;
	while( left < right && a[mid] != key )
	{
		if( a[mid] < key )
			left = mid + 1;
		else if( a[mid] > key )
			right = mid - 1;
		mid = ( left + right ) / 2;
	}
	if( a[mid] == key )
		return mid;
	return -1;
}
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,12,13,45,67,89,99,101,111,123,134,565,677};
	int b[] = { 677, 1, 7, 11, 67 };
	int i;
	for( i = 0; i < ARRAY_SIZE(a); i++ )
	{
		printf("%d\n", recurbinary(a, a[i], 0, ARRAY_SIZE(a) - 1));
		printf("%d\n", recurbinary(a, 10, 0, ARRAY_SIZE(a) - 1));
		//printf( "%d\n", binary( a, 45, sizeof(a)/sizeof(a[0])));
	}
	return 0;
}
