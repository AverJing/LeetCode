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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2) return nullptr;
		auto root1 = pHead1, root2 = pHead2;
		int length1 = 0, length2 = 0;
		while (root1) {
			++length1;
			root1 = root1->next;
		}
		while (root2) {
			++length2;
			root2 = root2->next;
		}
		for (; length1 > length2; --length1)
			pHead1 = pHead1->next;
		for (; length2 > length1; --length2)
			pHead2 = pHead2->next;

		while (pHead1 && pHead2) {
			if (pHead1->val == pHead2->val)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return nullptr;
	}
};

int main(){
	
}	