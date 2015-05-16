#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float coef;//系数
	int exp;	//指数
	struct node *next; //指针域
}listnode;


listnode *CreateList(int n)
{
	listnode *head = NULL;		//头结点
	listnode *p = NULL;			//当前节点
	listnode *pre = NULL;		//上一个节点

	float coef;
	int exp;
	int i;

	head = (listnode *)malloc(sizeof(listnode));
	if(head == NULL)
	{
		exit(-1);
	}

	pre = head;
	for(i = 0; i < n; i++)
	{
		printf("请输入第%d个 系数 和 指数\n", i + 1);
		scanf("%f,%d", &coef, &exp);

		p = (listnode *)malloc(sizeof(listnode));
		if(p == NULL)
		{
			exit(-1);
		}

		p->coef = coef;
		p->exp = exp;
		p->next = NULL;

		//插入节点
		pre->next = p;

		pre = p;
	}

	return(head);
}


void printlist(listnode *head)
{
	listnode *p;

	p = head->next;

	if(p == NULL)
	{
		return;
	}

	while(p->next != NULL)		//最后一个节点独立出来
	{
		printf("%1.1fX^%d + ", p->coef, p->exp);
		p = p->next;
	}
	printf("%1.1fX^%d\n", p->coef, p->exp);
}


listnode *AddPoly(listnode *head_a,listnode *head_b)	//链式相加
{
	listnode *head_c;
	listnode *pa;
	listnode *pb;
	listnode *pc;
	listnode *pre;
	listnode *p;

	head_c = (listnode *)malloc(sizeof(listnode));
	head_c->next = NULL;

	//复制list_a到list_c
	pa = head_a->next;
	pre = head_c;
	while(pa != NULL)
	{
		pc = (listnode *)malloc(sizeof(listnode));
		if(pc == NULL)
		{
			exit(-1);
		}

		pc->coef = pa->coef;
		pc->exp = pa->exp;

		//链接入链表
		pc->next = NULL;
		pre->next = pc;
		pre = pc;

		pa = pa->next;
	}

	//遍历链表b，把链表b的所有元素插入或者合并到链表c
	pb = head_b->next;
	while(pb != NULL)
	{
		//查找同幂次的节点，没有则按降幂插入
		pc = head_c->next;
		while(pc != NULL)
		{
			if(pc->exp == pb->exp)
			{
				break;
			}
			pre = pc;
			pc = pc->next;
		}

		if(pc != NULL)		//有同次幂
		{
			pc->coef += pb->coef;
		}
		else				//没有同次幂
		{
			pc = head_c->next;
			while(pc != NULL)
			{
				if(pc->exp > pb->exp)
				{
					break;
				}
				pre = pc;
				pc = pc->next;
			}

			p = (listnode *)malloc(sizeof(listnode));
			if(p == NULL)
			{
				exit(-1);
			}

			p->coef = pb->coef;
			p->exp = pb->exp;

			//链接新节点到链表c
			p->next = pc;
			pre->next = p;
		
		}

		pb = pb->next;
	}

	return(head_c);
}

int main(void)
{
	int n;
	listnode *head_a;
	listnode *head_b;
	listnode *head_c;
	
	scanf("%d", &n);
	head_a = CreateList(n);
	printlist(head_a);

	scanf("%d", &n);
	head_b = CreateList(n);
	printlist(head_b);

	head_c = AddPoly(head_a, head_b);	
	printlist(head_c);
}