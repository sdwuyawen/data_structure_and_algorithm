#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int value;
	struct node *next;
}list_node;

/* 逆置链表 */
list_node *reverse_list(list_node *phead)
{
	list_node *new_head = NULL;
	list_node *pprev = NULL;
	list_node *pnext = NULL;
	list_node *pnode = phead;

	while(pnode != NULL)
	{
		pnext = pnode->next;

		if(pnext == NULL)
		{
			new_head = pnode;
		}

		pnode->next = pprev;

		pprev = pnode;
		pnode = pnext;
	}
}

int main(void)
{
	return 0;
}

