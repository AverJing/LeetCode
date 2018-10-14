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

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* pLastNodeInList = nullptr;
		ConvertNode(pRootOfTree, pLastNodeInList);

		//pLastNodeInList指向双链表的尾节点
		//我们需要返回头节点
		TreeNode* pHead = pLastNodeInList;
		while (pHead && pHead->left) {
			pHead = pHead->left;
		}
		return pHead;
	}
private:
	void ConvertNode(TreeNode* pNode, TreeNode* &pLastNodeInList) {
		if (!pNode) return;

		TreeNode* pCurrent = pNode;
		//找到最左节点
		if (pCurrent->left)
			ConvertNode(pCurrent->left, pLastNodeInList);
		//更改当前节点的左指针
		pCurrent->left = pLastNodeInList;
		//令当前节点左侧的节点指向它
		if (pLastNodeInList)
			pLastNodeInList->right = pCurrent;
		//更新上次访问节点
		pLastNodeInList = pCurrent;

		if(pCurrent->right)
			ConvertNode(pCurrent->right, pLastNodeInList);
	}
};

int main(){
	
}	