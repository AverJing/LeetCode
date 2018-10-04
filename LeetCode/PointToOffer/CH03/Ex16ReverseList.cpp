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
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead)  return nullptr;
		ListNode* reverseHead = nullptr;
		auto pNode = pHead;
		ListNode* pPrev = nullptr;

		for (; pNode;) {
			auto pNext = pNode->next;

			if (!pNext) reverseHead = pNode;

			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		return reverseHead;
	}
};

int main(){
	
}	