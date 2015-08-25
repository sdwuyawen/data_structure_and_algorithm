#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//分配内存管理对齐的程序
void *aligned_malloc(int size, int alignment)
{
	void *ptr = (void*)malloc(size + alignment);
	
	//alignment = 4时
	//0 -> 0
	//1 -> 4
	//2 -> 4
	//3 -> 4
	//4 -> 4
	//5 -> 8
	
	//alignment = 8时
	//0 -> 0
	//1 -> 8 
	//2 -> 8 
	//3 -> 8 
	//4 -> 8 
	//5 -> 8 
	//6 -> 8 
	//7 -> 8 
	//8 -> 8 
	//9 -> 16
	
	if(ptr)
	{
		//这里必须加上sizeof(void *)
		//例如alignment = 4时，地址为1，则对齐到4，但是1~3共3个字节无法放置指针
		//加上sizeof(void *)后，地址由1变成5，对齐到8。1~7共7个字节可以放置指针
		void *aligned =(void *)(((long)ptr + alignment - 1 + sizeof(void *)) & (~(alignment-1)));

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

