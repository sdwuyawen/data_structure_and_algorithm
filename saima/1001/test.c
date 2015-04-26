/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2015 11:30:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <stdio.h>

int main(void)
{
	int x,y;
	while(scanf("%d %d", &x, &y) != EOF)
	{
		printf("%d\n", x+y);
	}
}
