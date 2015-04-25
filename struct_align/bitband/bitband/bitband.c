#include <stdio.h>
struct BF2
{
	char f1 : 3;
	short f2 : 4;
	char f3 : 5;
};

typedef struct BitArea1
{
	char c:4;
	short l:10;
}BITAREA1;



int main(void)
{
	printf("sizeof(struct BitArea1) = %d\n", sizeof(struct BitArea1));
	printf("sizeof(struct BF2) = %d\n", sizeof(struct BF2));
}
