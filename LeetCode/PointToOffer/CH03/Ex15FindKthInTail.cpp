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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (!pListHead || k == 0) return nullptr;
		auto pfirst = pListHead;
		auto psec = pListHead;
		for (auto i = 1; i < k; ++i) {
			if (psec->next)
				psec = psec->next;
			else
				return nullptr;
		}

		for (; psec->next;) {
			pfirst = pfirst->next;
			psec = psec->next;
		}
		return pfirst;
	}
};

int main(){
	
}	