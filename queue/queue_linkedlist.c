/* 参考http://blog.csdn.net/johnnyhu90/article/details/10283103 */
/***********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define Error( str )        FatalError( str )
#define FatalError( str )   fprintf( stderr, "%s\n", str ), exit( 1 )

typedef int ElementType;
#define MAXQUEUE 10

typedef struct node
{
    ElementType data;
    struct node* nextNode; 
} Node;
typedef struct queue
{
    Node* front;    // 对首指针
    Node* rear;     // 队尾指针
    int items;      // 队列中项目个数

} *ptrQueue;
typedef ptrQueue Queue;
int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(void);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void Enqueue(ElementType x, Queue q);
ElementType Front(Queue q);
void Dequeue(Queue q);
ElementType FrontAndDequeue(Queue q);

/************************************************************************/
// 主程序
/************************************************************************/
int main(void)
{
    Queue sqQueue;
    //int maxElements = 10;

    sqQueue = CreateQueue();
    if (IsEmpty(sqQueue))
        printf("创建了空队列！");

    int value = 0;
    printf("队列中的数据为(front->rear)：\n");
    while (!IsFull(sqQueue))
    {
        Enqueue(value*value, sqQueue);  // 入队
        printf("%d ", value*value);
        value++;
    }
    printf("队列已满\n");


    ElementType frontQueue;
    frontQueue = Front(sqQueue);
    printf("队头元素为：%d\n", frontQueue);

    Dequeue(sqQueue);
    frontQueue = Front(sqQueue);
    printf("执行出队操作Dequeue之后，队头元素是：%d\n", frontQueue);
    DisposeQueue(sqQueue);

    return 0;
}

/************************************************************************/
// 是否为空
/************************************************************************/
int IsEmpty(Queue q)
{
    return q->items == 0;
}

/************************************************************************/
// 是否已满
/************************************************************************/
int IsFull(Queue q)
{
    return q->items == MAXQUEUE;
}

/************************************************************************/
// 创建队列
/************************************************************************/
Queue CreateQueue(void)
{
    Queue q;

    q = (Queue)malloc(sizeof(struct queue));
    if (NULL == q)
        Error("空间不足，队列内存分配失败！");


	q->front = NULL;
	q->rear = NULL;

//    q->front = (Node*)malloc(sizeof(Node));
//    if (NULL == q->front)
//        Error("空间不足，队列首节点内存分配失败！");
//
//    q->rear = (Node*)malloc(sizeof(Node));
//    if (NULL == q->rear)
//        Error("空间不足，队列尾节点内存分配失败！");

    q->items = 0;

    return q;
}

/************************************************************************/
// 释放队列
/************************************************************************/
void DisposeQueue(Queue q)
{
    MakeEmpty(q);
    free(q);
}

/************************************************************************/
// 使队列为空
/************************************************************************/
void MakeEmpty(Queue q)
{
    if (q == NULL)
        Error("必须先使用CreateQueue创建队列！");

    while (IsEmpty(q))
        Dequeue(q);
}

/************************************************************************/
// 入队
/************************************************************************/
void Enqueue(ElementType x, Queue q)
{
    if (IsFull(q))
        Error("队列已满！");

    Node* pnode;
    pnode = (Node*)malloc(sizeof(Node));
    if (NULL == pnode)
        Error("新节点分配内存失败！");

    pnode->data= x;
    pnode->nextNode = NULL;
    if (IsEmpty(q))
        q->front = pnode;           // 项目位于首端
    else
        q->rear->nextNode = pnode;  // 链接到队列尾端
    q->rear = pnode;                    // 记录队列尾端的位置
    q->items++;                     // 项目数加1

    return;
}

/************************************************************************/
// 出队
/************************************************************************/
void Dequeue(Queue q)
{
    if (IsEmpty(q))
        Error("队列本身为空！");
    
    Node* pnode;
    pnode = q->front;
    q->front = q->front->nextNode;
    free(pnode);
    
    q->items--;
    if (q->items == 0)
        q->rear = NULL;

    return;
}

/************************************************************************/
//  返回队列头元素
/************************************************************************/
ElementType Front(Queue q)
{
    if (!IsEmpty(q))
        return q->front->data;
    Error("队列为空\n");

    return 0;
}

/************************************************************************/
// 返回对列头元素并使对头元素出对
/************************************************************************/
ElementType FrontAndDequeue(Queue q)
{
//    ElementType x = 0;
//
//    if( IsEmpty(q) )
//        Error( "队列为空！" );
//    else
//    {
//        q->items--;
//        x = q->front->data;
//        q->front = q->front->nextNode;
//
//		if(q->front == NULL)
//			q->rear = NULL;
//    }

//    return x = 0;

	ElementType x;
	Node *pnode;

	if(q->front == NULL)
	{
		Error("Queue Empty!\n");
	}
	else
	{
		pnode = q->front;
		x = q->front->data;
		q->items--;
		q->front = q->front->nextNode;
		if(q->front == NULL)
		{
			q->rear = NULL;
		}
		free(pnode);
	}

	return x;

}
