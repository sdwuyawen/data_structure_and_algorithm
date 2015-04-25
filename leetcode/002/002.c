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

	while(l1 != NULL || l2 != NULL || carry_flag != 0)
	{
		new = malloc(sizeof(struct ListNode));
		
		new->next = NULL;
		
		value = 0;
		value +=  l1 ? l1->val : 0;
		value +=  l2 ? l2->val : 0;
		value += carry_flag;

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

		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
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
