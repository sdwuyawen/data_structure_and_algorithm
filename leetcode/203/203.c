/*
 * =====================================================================================
 *
 *       Filename:  203.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/23/2015 03:25:46 PM
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

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

*/
struct ListNode 
{
	int val;
	struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode *list;
    struct ListNode *pre;
    struct ListNode *temp;
    struct ListNode *head_new = head;

    if(head == NULL)
        return NULL;

    pre = NULL;
    list = head;

    while(list != NULL)
    {
        if(list->val == val)
        {
            if(list == head_new)                //is list head
            {
                temp = list;
                head_new = list->next;
                pre = NULL;
                list = list->next;
                
                free(temp);
            }
            else
            {
                temp = list;
                pre->next = list->next;
                list = list->next;
                free(temp);
            }
        }
        else
        {
            pre = list;
            list = list->next;
        }
    }
    return head_new;
}

struct ListNode* insertElements(struct ListNode* head, int val) 
{

	struct ListNode *list;
	struct ListNode *temp;

	list = malloc(sizeof(struct ListNode));
	list->val = val;

	temp = head->next;
	head->next = list;
	list->next = temp;
}

struct ListNode* printList(struct ListNode* head) 
{
	struct ListNode *list;
	list = head;
	int i = 0;

	while(list != NULL)
	{
		printf("node %d: %d\n", i++,list->val);
		list = list->next;
	}
}


int main(void)
{
	struct ListNode *listhead;
	
	listhead = malloc(sizeof(struct ListNode));
	listhead->next = NULL;

	insertElements(listhead, 1);
	insertElements(listhead, 2);
	insertElements(listhead, 3);
	insertElements(listhead, 4);
	insertElements(listhead, 5);
	insertElements(listhead, 6);

	listhead = listhead->next;

	printList(listhead);

	printf("delete 3\n");
	listhead = removeElements(listhead, 3);
	printList(listhead);

	
	printf("delete 6\n");
	listhead = removeElements(listhead, 6);
	printList(listhead);
	
	printf("delete 1\n");
	listhead = removeElements(listhead, 1);
	printList(listhead);
	


	return 0;

}
