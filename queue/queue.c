#include "stdio.h"


#define Q_SIZE	100
typedef int ElementType;


//队列的定义
typedef struct
{
	int capacity;
	int size;
	int read_index;
	int write_index;
	ElementType *data_array;
}queue_typedef;

queue_typedef queue;
ElementType queue_data_array[Q_SIZE];

/* 初始化队列 */
void q_init(void)
{
	queue_typedef *q = &queue;
	
	q->capacity = Q_SIZE;					/* 队列最大容量 */
	q->size = 0;							/* 队列当前大小 */
	q->read_index = 0;						/* read index */
	q->write_index = 0;						/* write index */
	q->data_array = queue_data_array;		/* 数据表 */	
}

/* 清空队列 */
void q_make_empty(void)
{
	queue_typedef *q = &queue;
	
	q->size = 0;							/* 队列当前大小 */
	q->read_index = 0;						/* read index */
	q->write_index = 0;						/* write index */
}

/* 查询队列是否满。满返回1，不满返回0 */
int q_is_full(void)
{
	queue_typedef *q = &queue;
	
	return(q->size == q->capacity);
}

/* 查询队列是否空。空返回1，不空返回0 */
int q_is_empty(void)
{
	queue_typedef *q = &queue;
	
	return(q->size == 0);
}

/* 队列入队，成功返回0，失败返回-1 */
int q_enqueue(ElementType value)
{
	queue_typedef *q = &queue;
	
	/* 队列满 */
	if(q_is_full())
	{
		return -1;
	}
	else
	{
		q->size++;									/* 当前队列数据个数 */
		
		q->data_array[q->write_index] = value;		/* 要写入的位置 */
		
		q->write_index = (q->write_index + 1) % q->capacity;	/* 写入指针推进1 */
		
		return 0;
	}
	return 0;
}

/* 队列出队，成功返回0，失败返回-1 */
int q_dequeue(void)
{
	queue_typedef *q = &queue;
	
	/* 队列空 */
	if(q_is_empty())
	{
		return -1;
	}
	else
	{
		q->size--;									/* 当前队列数据个数 */
		q->read_index = (q->read_index + 1) % q->capacity;	/* 读指针推进 */
		
		return 0;
	}
}

/* 队列查询，获取队首元素，成功返回0，失败返回-1 */
int q_enquiry(ElementType *data)
{
	queue_typedef *q = &queue;
	
	/* 队列空 */
	if(q_is_empty())
	{
		return -1;
	}
	else
	{
		/* 获取队首元素 */
		*data = q->data_array[q->read_index];
		
		return 0;
	}
}

int main(void)
{
	ElementType value;
	q_init();

	q_enqueue(1);
	q_enqueue(2);
	q_enqueue(3);
	q_enqueue(4);
	q_enqueue(5);

	while(q_enquiry(&value) == 0)
	{
		q_dequeue();
		printf("%d\n", value);
	}

	return 0;	
}
