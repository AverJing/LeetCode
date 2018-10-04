/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	/*
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1) return pHead2;
		if (!pHead2) return pHead1;

		ListNode* pRecursiveHead = nullptr;

		if (pHead1->val < pHead2->val) {
			pRecursiveHead = pHead1;
			pRecursiveHead->next = Merge(pHead1->next, pHead2);
		}
		else {
			pRecursiveHead = pHead2;
			pRecursiveHead->next = Merge(pHead1, pHead2->next);
		}
		return pRecursiveHead;
	}*/
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1) return pHead2;
		if (!pHead2) return pHead1;

		ListNode pRecursiveHead = ListNode(-1);
		ListNode* pNext = &pRecursiveHead;
		for (; pHead1 && pHead2;) {
			if (pHead1->val < pHead2->val) {
				pNext->next = pHead1;
				pNext = pNext->next;
				pHead1 = pHead1->next;
			}
			else {
				pNext->next = pHead2;
				pNext = pNext->next;
				pHead2 = pHead2->next;
			}
		}
		if(pHead1) {
			pNext->next = pHead1;
		}
		if(pHead2) {
			pNext->next = pHead2;
		}
		return pRecursiveHead.next;
	}
};

int main(){
	
}	