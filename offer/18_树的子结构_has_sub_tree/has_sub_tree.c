#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int value;
	struct node *lchild;
	struct node *rchild;
}tree_node;

/* 判断从proot1和proot2为根的树中，proot1是否包含proot1 */
int does_tree1_has_tree2(tree_node *proot1, tree_node *proot2)
{
	if(proot2 == NULL)
		return TRUE;

	if(proot1 == NULL)
		return FALSE;

	if(proot1->value != proot2->value)\
		return FALSE;

	return does_tree1_has_tree2(proot1->lchild, proot2->lchild)
			&& does_tree1_has_tree2(proot1->rchild, proot2->rchild);
}

/* 判断proot2是否包含在proot1中 */
int has_sub_tree(tree_node *proot1, tree_node *proot2)
{
	int result = FALSE;

	if(proot1 != NULL && proot2 != NULL)
	{
		if(proot1->value == proot2->value)
			result = does_tree1_has_tree2(proot1, proot2);
		
		if(result == FALSE)
			result = has_sub_tree(proot1->lchild, proot2);

		if(result == FALSE)
			result = has_sub_tree(proot1->rchild, proot2);
	}

	return result;
}

int main()
{
	return 0;
}
