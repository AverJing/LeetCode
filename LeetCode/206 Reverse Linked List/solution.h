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
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. 
Could you implement both?
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
	//create head node
	/*
	ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;
		ListNode root = ListNode(-1); //real head
		ListNode* real_head = &root;
		ListNode* next;
		while(head) {
			next = head->next;
			auto tmp = real_head->next;
			real_head->next = head;
			head->next = tmp;
			head = next;
		}
		return real_head->next;
	}
	*/
	//do not use head node
	ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;
		ListNode* prev = NULL;
		ListNode* next;
		ListNode* curr = head;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
};
