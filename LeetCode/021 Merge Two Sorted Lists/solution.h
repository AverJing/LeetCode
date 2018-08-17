/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

	Input: 1->2->4, 1->3->4
	Output: 1->1->2->3->4->4
*/
#pragma once

#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*
	ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *header = NULL, **p;
		for (p = &header; l1 && l2; p = &(*p)->next)
		{
			if (l1->val <= l2->val)
			{
				*p = new ListNode(l1->val);
				l1 = l1->next;
			}
			else
			{
				*p = new ListNode(l2->val);
				l2 = l2->next;
			}
		}
		for (ListNode *leave = l1 ? l1 : l2; leave; leave = leave->next, p = &(*p)->next)
			*p = new ListNode(leave->val);
		return header;
	}*/

	//It's cool. Although there is not a head pointer, we can use the head pointer.
	//Then we will delete it. Well, well. fantasy
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode res(0);

		ListNode* temp = &res;

		while (l1 && l2) {
			if (l1->val > l2->val) {
				temp->next = l2;
				l2 = l2->next;
			}
			else {
				temp->next = l1;
				l1 = l1->next;
			}
			temp = temp->next;
		}

		temp->next = l1 ? l1 : l2;

		return res.next;

	}
};
