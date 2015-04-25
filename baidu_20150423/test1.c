#include "stdio.h"



void memcpy(unsigned char *src, unsigned char *dst, unsigned int len)
{
    unsigned int i;
    
    for(i = 0; i < len; i++)
    {
        *(dst + i) = *(src + i);
    }
}


void sort(int *array, int len)
{
    int i;
    int j;
    int temp;
    
    for(i = 0; i < len - 1; i++)
    {
        for(j = 0; j < len - 1 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//迭代
int add(int a, int b)
{
    int val1;
    int val2;
    
	int temp1 = a;
	int temp2 = b;

    while(1)
    {

        val1 = temp1 ^ temp2;
        val2 = temp1 & temp2;
        
		if(val2 == 0)
        {
            break;
        }

		temp1 = val1;	
        temp2 = val2 << 1;
    }
    
    return val1;
}


int main(void)
{
	int a;
	int b;

	while(1)
	{
		scanf("%d %d", &a, &b);
		printf("a + b = %d\n", add(a, b));
	}
	
	return 0;
}
