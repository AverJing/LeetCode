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
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
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
	ListNode* swapPairs(ListNode* head) {
		ListNode *p = head;
		int temp;
		while (p) {
			if (p->next) {
				temp = p->val;
				p->val = p->next->val;
				p->next->val = temp;
				p = p->next;
			}
			if (p)
				p = p->next;
		}
		return head;
	}
};
