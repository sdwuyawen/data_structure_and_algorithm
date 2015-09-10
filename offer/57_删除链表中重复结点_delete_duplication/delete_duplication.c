#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
    int value;
    struct node *next;
}list_node;

/* 删除链表中的重复结点 */
void delete_duplication(list_node **phead)
{
	if(phead == NULL || *phead == NULL)
		return;

	list_node *ppre_node = NULL;
	list_node *p_node = *phead;

	while(p_node != NULL)
	{
		list_node *p_next = p_node->next;
		int need_delete = FALSE;
		
		if(p_next != NULL && p_next->value == p_node->value)
			need_delete = TRUE;

		/* 不需要删除 */
		if(!need_delete)
		{
			ppre_node = p_node;
			p_node = p_node->next;
		}
		else
		{
			int value = p_node->value;
			list_node *p_tobedel = p_node;

			while(p_tobedel != NULL && p_tobedel->value == value)
			{
				p_next = p_tobedel->next;

				free(p_tobedel);
				p_tobedel = p_next;
			}

			/* 删除后，调整上一个节点的next指针 */
			if(ppre_node == NULL)
				*phead = p_next;
			else
				ppre_node->next = p_next;

			p_node = p_next;
		}
	}
}
