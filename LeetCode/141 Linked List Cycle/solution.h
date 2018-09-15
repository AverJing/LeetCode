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
Given a linked list, determine if it has a cycle in it.

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
	//have head node 
	bool hasCycle(ListNode *head) {
		if (!head || !head->next) return false;
		ListNode *low = head;
		ListNode *fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			low = low->next;
			fast = fast->next->next;
			if (low == fast) return true;
		}
		return false;
	}
};