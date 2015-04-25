#include <stdio.h>

#pragma pack(16) 
struct my_struct
{
	char a;
	int b;
    short c;
};
//#pragma pack() 

struct my_struct my_struct_A;
int main(void)
{
	char *p_char;
	unsigned long offset = (unsigned long)&my_struct_A.a;

	printf("size = %d\r\n", sizeof(struct my_struct));
	printf("&a = %d\r\n", (unsigned long)&my_struct_A.a - offset);
	printf("&b = %d\r\n", (unsigned long)&my_struct_A.b - offset);
	printf("&c = %d\r\n", (unsigned long)&my_struct_A.c - offset);
}