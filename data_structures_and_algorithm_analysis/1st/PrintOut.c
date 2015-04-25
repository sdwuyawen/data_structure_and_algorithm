/*
 * =====================================================================================
 *
 *       Filename:  PrintOut.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2015 09:40:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void PrintDigit(unsigned int N)
{
	printf("%d", N);
}
void PrintOut(unsigned int N)
{
	if(N >= 10)
	{
		PrintOut(N/10);
	}
	
	PrintDigit(N%10);

}
int main(void)
{
	PrintOut(1234);

	return 0;
}

