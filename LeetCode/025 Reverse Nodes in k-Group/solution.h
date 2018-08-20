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
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (!head || !head->next || k < 2) return head;
		ListNode pre(0);
		pre.next = head;

		for (ListNode *front = &pre, *back = &pre; true; front = head, back = head) {
			for (int count = k; count > 0; --count)
				if (!(back = back->next)) return pre.next;

			for (head = front->next; front->next != back; ) {
				ListNode *next = front->next;
				front->next = next->next;
				next->next = back->next;
				back->next = next;
			}
		}
		return pre.next;
	}
};
