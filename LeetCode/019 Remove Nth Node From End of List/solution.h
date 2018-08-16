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
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.
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
	//has a head pointer
	/*
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode* p = head->next, *pre = head;
		ListNode* q = p->next;
		for (auto i = 1; i < n-1; ++i)
			q = q->next;
		for (; q->next;) {
			pre = p;
			p = p->next;
			q = q->next;
		}
		pre->next = p->next;
		p->next = NULL;
		return head;
	}*/
	//no head pointer
		ListNode * removeNthFromEnd(ListNode* head, int n) {
			ListNode* p = head, *pre = head;
			ListNode* q = p;
			for (auto i = 0; i < n - 1; ++i)
				q = q->next;
			for (; q->next != NULL;) {
				pre = p;
				p = p->next;
				q = q->next;
			}
			//if(!p) {pre->next = NULL;}
			if (p == pre) { head = pre->next; return head; }

			{pre->next = p->next; p = NULL; }

			return head;
		}
};
