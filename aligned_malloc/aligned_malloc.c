#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//分配内存管理对齐的程序
void *aligned_malloc(int size, int alignment)
{
	void *ptr = (void*)malloc(size + alignment);

	if(ptr)
	{
		void *aligned =(void *)(((long)ptr + alignment) & (~(alignment-1)));

		printf("malloc ptr = %08x, aligned = %08x\n", ptr, aligned);

		if(aligned - ptr >= sizeof(void *))
		{
			((void **)aligned)[-1] = ptr;
			return aligned;
		}
		else
		{
			printf("size and alignment illegal\n");
			free(ptr);
		}
	}

	return NULL;
}

//释放函数aligned_free
void *aligned_free(void *paligned)
{
	void *ptr = ((void **)paligned)[-1];
	printf("free ptr = %08x, paligned = %08x\n", ptr, paligned);
	free(ptr);

	return paligned;
}


int main(void)
{
	char str[2][100];
	int align = 0;

	void *ptr;

	while(1)
	{
		scanf("%s", str[0]);

		if(strcmp("malloc", str[0]) == 0)
		{
			scanf("%d", &align);

			ptr = aligned_malloc(1024, align);
		}
		else if(strcmp("free", str[0]) == 0)
		{
			aligned_free(ptr);
		}
	}

	return 0;
}

