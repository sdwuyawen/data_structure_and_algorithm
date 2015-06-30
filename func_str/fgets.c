/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/30/2015 10:09:59 AM
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
#include <string.h>

int main(void)
{
	int i;
	char buf[100];

	fgets(buf, sizeof(buf), stdin);
	buf[sizeof(buf) - 1] = 0x00;

	for(i = 0; i < strlen(buf); i++)
	{
		printf("%02x ", buf[i]);
	}
}
