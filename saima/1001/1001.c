/*
 * =====================================================================================
 *
 *       Filename:  1001.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/2015 07:31:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
	int a = 0;
	int sum = 0;
	int i = 0;

	while(scanf("%d", &a) != EOF)
	{
		sum = 0;
		for(i = 1; i <= a; i++)
		{
			sum += i;
		}
		printf("%d\n\n", sum);
	}

}
