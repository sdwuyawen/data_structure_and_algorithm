#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
    int value;
    struct node *next;
}list_node;

/* 找到链表中环中一个节点，如果没有环则返回NULL */
list_node *meet_node(list_node *phead)
{
	list_node *pslow;
	list_node *pfast;
	
	if(phead == NULL)
		return NULL;
	/* 从第二个节点开始判断环 */
	pslow = phead->next;
	pfast = phead->next;

	while(pfast != NULL && pslow != NULL)
	{
		if(pfast == pslow)
			return pfast;

		pslow = pslow->next;
		pfast = pfast->next;
		if(pfast != NULL)
		{
			pfast = pfast->next;
		}
	}

	return NULL;
}

list_node *entry_node_of_loop(list_node *phead)
{
	list_node *meeting_node;
	int nodes_in_loop = 1;
	list_node *pnode1;
	list_node *pnode2;
	int i;

	/* 找到环中一个结点 */
	meeting_node = meet_node(phead);
	if(meeting_node == NULL)
		return NULL;

	/* 计算环的长度 */
	pnode1 = meeting_node;
	while(pnode1->next != meeting_node)
	{
		pnode1 = pnode1->next;
		nodes_in_loop++;
	}
	
	/* 从头结点开始，向后移动环的长度个结点 */
	pnode1 = phead;
	for(i = 0; i < nodes_in_loop; i++)
	{
		pnode1 = pnode1->next;
	}

	/* 找到环的入口结点 */
	pnode2 = phead;
	while(pnode1 != pnode2)
	{
		pnode1 = pnode1->next;
		pnode2 = pnode2->next;
	}
	return pnode1;

}
