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
	//bad answer
	/*
	ListNode* sortList(ListNode* head) {
		if (!head) return NULL;
		ListNode *real_head = new ListNode(-10);
		real_head->next = head;
		ListNode* pre = real_head->next, *root = real_head;
		auto nex = pre->next;
		pre->next = NULL;
		while (nex != NULL) {
			//root = head; pre = head->next;
			pre = real_head->next;
			root = real_head;
			auto temp = nex;  nex = nex->next; temp->next = NULL;
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
			
		}
		return real_head->next;
	}
	*/
	//use merge sort
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)  return head;

		//快慢指针找到中间节点
		ListNode *fast = head, *slow = head;
		while (fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		//断开
		fast = slow;
		slow = slow->next;
		fast->next = NULL;

		ListNode *l1 = sortList(head); //前半段排序
		ListNode *l2 = sortList(slow); //后半段排序
		return mergeTwoLists(l1, l2);
	}

	//Merge Two Sorted Lists
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1);
		for (ListNode* p = &dummy; l1 != NULL || l2 != NULL; p = p->next)
		{
			int val1 = l1 == NULL ? INT_MAX : l1->val;
			int val2 = l2 == NULL ? INT_MAX : l2->val;
			if (val1 <= val2)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
		}
		return dummy.next;
	}

};