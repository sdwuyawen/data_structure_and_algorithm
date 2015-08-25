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
void q_init(void);

/* 清空队列 */
void q_make_empty(void);

/* 查询队列是否满。满返回1，不满返回0 */
int q_is_full(void);

/* 查询队列是否空。空返回1，不空返回0 */
int q_is_empty(void);

/* 队列入队，成功返回0，失败返回-1 */
int enqueue(ElementType value);

/* 队列出队，成功返回0，失败返回-1 */
int q_dequeue(void);

/* 队列查询，获取队首元素，成功返回0，失败返回-1 */
int q_enquiry(ElementType *data);

