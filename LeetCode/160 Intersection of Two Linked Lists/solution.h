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
Write a program to find the node at which the intersection of 
two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
				   ↘
					 c1 → c2 → c3
				   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA && !headB) return NULL;
		int sizeA = 0, sizeB = 0;
		auto rootA = headA, rootB = headB;
		for (; rootA != NULL;) {
			++sizeA; rootA = rootA->next;
		}
		for (; rootB != NULL;) {
			++sizeB; rootB = rootB->next;
		}
		for (; sizeA < sizeB; ++sizeA) {
			if (!headB) return NULL;
			headB = headB->next;
		}
		for (; sizeB < sizeA; ++sizeB) {
			if (!headA) return NULL;
			headA = headA->next;
		}

		for (; headA != NULL && headB != NULL;) {
			if (headA == headB) return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
};
