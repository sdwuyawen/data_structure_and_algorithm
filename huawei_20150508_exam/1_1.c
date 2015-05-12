#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int len = 0;
	char str[100];

	scanf("%s", str);

	if(strcmp(str, "int") == 0)
	{
		len = sizeof(int);
	}
	else if(strcmp(str, "long") == 0)
	{
		len = sizeof(long);
	}
	else if(strcmp(str, "long int ") == 0)
	{
		len = sizeof(long int);
	}
	else if(strcmp(str, "short") == 0)
	{
		len = sizeof(short);
	}
	else if(strcmp(str, "short int") == 0)
	{
		len = sizeof(short int);
	}
	else if(strcmp(str, "char") == 0)
	{
		len = sizeof(char);
	}
	else if(strcmp(str, "float") == 0)
	{
		len = sizeof(float);
	}
	else if(strcmp(str, "bool") == 0)
	{
		len = sizeof(bool);
	}
	else if(strcmp(str, "double") == 0)
	{
		len = sizeof(double);
	}

	printf("%d", len);

	return 0;
}