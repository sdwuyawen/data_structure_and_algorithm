#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	float coef;//ÏµÊý
	int exp;	//Ö¸Êý
	struct node *next; //Ö¸ÕëÓò
}listnode;


listnode *CreateList(int n)
{
	listnode *head = NULL;		//Í·½áµã
	listnode *p = NULL;			//µ±Ç°½Úµã
	listnode *pre = NULL;		//ÉÏÒ»¸ö½Úµã

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
		printf("ÇëÊäÈëµÚ%d¸ö ÏµÊý ºÍ Ö¸Êý\n", i + 1);
		scanf("%f,%d", &coef, &exp);

		p = (listnode *)malloc(sizeof(listnode));
		if(p == NULL)
		{
			exit(-1);
		}

		p->coef = coef;
		p->exp = exp;
		p->next = NULL;

		//²åÈë½Úµã
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

	while(p->next != NULL)		//×îºóÒ»¸ö½Úµã¶ÀÁ¢³öÀ´
	{
		printf("%1.1fX^%d + ", p->coef, p->exp);
		p = p->next;
	}
	printf("%1.1fX^%d\n", p->coef, p->exp);
}


listnode *AddPoly(listnode *head_a,listnode *head_b)	//Á´Ê½Ïà¼Ó
{
	listnode *head_c;
	listnode *pa;
	listnode *pb;
	listnode *pc;
	listnode *pre;
	listnode *p;

	head_c = (listnode *)malloc(sizeof(listnode));
	head_c->next = NULL;

	//¸´ÖÆlist_aµ½list_c
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

		//Á´½ÓÈëÁ´±í
		pc->next = NULL;
		pre->next = pc;
		pre = pc;

		pa = pa->next;
	}

	//±éÀúÁ´±íb£¬°ÑÁ´±íbµÄËùÓÐÔªËØ²åÈë»òÕßºÏ²¢µ½Á´±íc
	pb = head_b->next;
	while(pb != NULL)
	{
		//²éÕÒÍ¬ÃÝ´ÎµÄ½Úµã£¬Ã»ÓÐÔò°´½µÃÝ²åÈë
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

		if(pc != NULL)		//ÓÐÍ¬´ÎÃÝ
		{
			pc->coef += pb->coef;
		}
		else				//Ã»ÓÐÍ¬´ÎÃÝ
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

			//Á´½ÓÐÂ½Úµãµ½Á´±íc
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
