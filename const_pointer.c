/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/11/2015 10:36:42 AM
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

int main(int argc, char **argv)
{
	const int i = 0; 
	int *j = (int *) &i; 
	*j = 1; 
	printf("%d,%d", i, *j);
}
