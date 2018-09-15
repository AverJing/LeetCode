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
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
	/*
	ListNode* sortList(ListNode* head) {
		if (!head) return NULL;
		ListNode* pre = head->next, *root = head;
		if (!pre) return head;
		auto nex = pre->next;
		pre->next = NULL;
		while (nex != NULL) {
			root = head; pre = head->next;
			for (; ; ) {
				auto temp = nex;
				if (!pre) {
					root->next = temp;
					temp->next = pre;
					nex = nex->next;
					break;
				}
				if (pre->val < temp->val) {
					root = pre;
					pre = pre->next;
				}
				else {
					root->next = temp;
					temp->next = pre;
					nex = nex->next;
					break;
				}
			}
		}
	}
	*/
	ListNode* sortList(ListNode* head) {
		if (!head) return NULL;
		ListNode *real_head = new ListNode(-10);
		real_head->next = head;
		ListNode* pre = real_head->next, *root = real_head;
		if (!pre) return head;
		auto nex = pre->next;
		pre->next = NULL;
		while (nex != NULL) {
			//root = head; pre = head->next;
			pre = real_head->next;
			root = real_head;
			auto temp = nex;  temp->next = NULL;
			for (; ; ) {
				if (!pre) {
					root->next = temp;
					temp->next = pre;
					break;
				}
				if (pre->val < temp->val) {
					root = pre;
					pre = pre->next;
				}
				else {
					root->next = temp;
					temp->next = pre;
					break;
				}
			}
			nex = nex->next;
		}
		return real_head->next;
	}
};