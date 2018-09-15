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
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
	ListNode *detectCycle(ListNode *head) {
		if (head && head->next)
			for (ListNode *slow = head, *fast = head->next; fast && fast->next; slow = slow->next, fast = fast->next->next)
				if (slow == fast)
					for (slow = slow->next; true; head = head->next, slow = slow->next)
						if (slow == head) return slow;
		return NULL;
	}
};