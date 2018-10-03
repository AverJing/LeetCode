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
	int value;
	ListNode* next;
};

void Delete(ListNode** plistHead, ListNode* pToBeDeleted) {
	if (!plistHead || !pToBeDeleted)
		return;
	//删除的节点不是尾节点
	if (!pToBeDeleted->next) {
		ListNode* pNext = pToBeDeleted->next;
		pToBeDeleted->value = pNext->value;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = nullptr;
	}
	else if (*plistHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*plistHead = nullptr;
	}
	else {
		ListNode* pNode = *plistHead;
		while (pNode->next != pToBeDeleted) {
			pNode = pNode->next;
		}
		pNode->next = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

int main(){
	
}	