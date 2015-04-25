/*
 * =====================================================================================
 *
 *       Filename:  2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2015 11:10:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *head = NULL;
	struct ListNode *new = NULL;
	struct ListNode *last = NULL;

	int carry_flag = 0;
	int value;

	while(l1 != NULL && l2 != NULL)
	{
		new = malloc(sizeof(struct ListNode));
		
		new->val = 0;	
		new->next = NULL;
		
		value = l1->val + l2->val + carry_flag;
		new->val = value % 10;
		carry_flag = value / 10; 
			
		if(head == NULL)		//头节点
		{
			head = new;
		}
		else
		{
			last->next = new;
		}

		last = new;

		l1 = l1->next;
		l2 = l2->next;
	}

	if(l1 == NULL)
	{
		while(l2 != NULL)
		{
			new = malloc(sizeof(struct ListNode));
			
			new->val = 0;	
			new->next = NULL;
			
			value = l2->val + carry_flag;
			new->val = value % 10;
			carry_flag = value / 10; 
				
			if(head == NULL)		//头节点
			{
				head = new;
			}
			else
			{
				last->next = new;
			}

			last = new;

			l2 = l2->next;
		}
	}

	
	if(l2 == NULL)
	{
		while(l1 != NULL)
		{
			new = malloc(sizeof(struct ListNode));
			
			new->val = 0;	
			new->next = NULL;
			
			value = l1->val + carry_flag;
			new->val = value % 10;
			carry_flag = value / 10; 
				
			if(head == NULL)		//头节点
			{
				head = new;
			}
			else
			{
				last->next = new;
			}

			last = new;

			l1 = l1->next;
		}
	}

	//如果在加完之后有进位，则需要处理最高位
	//比如[5] + [5] = [0] [1]
	if(carry_flag != 0)
	{
		new = malloc(sizeof(struct ListNode));
			
		new->val = 0;	
		new->next = NULL;
		
		value = carry_flag;
		new->val = value % 10;
		carry_flag = value / 10; 
			
		if(head == NULL)		//头节点
		{
			head = new;
		}
		else
		{
			last->next = new;
		}

		last = new;

	}

	return head;
}


int main(void)
{
	struct ListNode *head_a0 = malloc(sizeof(struct ListNode));
	struct ListNode *head_a1 = malloc(sizeof(struct ListNode));
	struct ListNode *head_a2 = malloc(sizeof(struct ListNode));
	struct ListNode *head_b0 = malloc(sizeof(struct ListNode));
	struct ListNode *head_b1 = malloc(sizeof(struct ListNode));
	struct ListNode *head_b2 = malloc(sizeof(struct ListNode));
	
	struct ListNode *result;


	head_a0->next = NULL;
	head_a1->next = NULL;
	head_a2->next = NULL;
	head_b0->next = NULL;
	head_b1->next = NULL;
	head_b2->next = NULL;


	head_a0->val = 2;
	head_a1->val = 4;
	head_a2->val = 3;

	head_b0->val = 5;
	head_b1->val = 6;
	head_b2->val = 4;

	head_a0->next = head_a1;
	head_a1->next = head_a2;
	head_a2->next = NULL;
	
	head_b0->next = head_b1;
	head_b1->next = head_b2;
	head_b2->next = NULL;

	result = addTwoNumbers(head_a0, head_b0);

	while(result != NULL)
	{
		printf("%d ", result->val);
		result = result->next;
	}

}
