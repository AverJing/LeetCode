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


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReconnectNodes(pHead);
	}
private:
	void CloneNodes(RandomListNode* root) {
		if (!root) return;
		auto nextNode = root;
		while (nextNode) {
			auto cloneNode = new RandomListNode(nextNode->label);

			cloneNode->next = nextNode->next;
			nextNode->next = cloneNode;
			nextNode = cloneNode->next;
		}
	}
	void ConnectSiblingNodes(RandomListNode* root) {
		auto nextNode = root;
		while (nextNode) {
			auto cloneNode = nextNode->next;
			if(nextNode->random)
				cloneNode->random = nextNode->random->next;
			nextNode = cloneNode->next;
		}
	}
	RandomListNode* ReconnectNodes(RandomListNode* root) {
		auto nextNode = root;
		RandomListNode* cloneNodeHead = nullptr;
		RandomListNode* cloneNext = nullptr;

		if (root) {
			cloneNodeHead = cloneNext = root->next;
			nextNode->next = cloneNext->next;
			nextNode = nextNode->next;
		}
		while (nextNode) {
			cloneNext->next = nextNode->next;
			cloneNext = cloneNext->next;
			nextNode->next = cloneNext->next;
			nextNode = nextNode->next;
		}
		return cloneNodeHead;
	}
};

int main(){
	
}	