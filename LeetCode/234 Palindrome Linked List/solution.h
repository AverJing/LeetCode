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
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
	ListNode* reverse(ListNode* root) {
		ListNode* prev = NULL;
		while (root != NULL) {
			auto next = root->next;
			root->next = prev;
			prev = root;
			root = next;
		}
		return prev;
	}
	bool isPalindrome(ListNode* head) {
		auto fast = head, slow = head; int count = 0;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		if (fast != NULL) slow = slow->next;
		slow = reverse(slow);
		fast = head;

		for (; slow!=NULL; slow = slow->next, fast=fast->next ) {
			if (slow->val != fast->val) {
				return false;
			}
		}
		return true;
	}
};
