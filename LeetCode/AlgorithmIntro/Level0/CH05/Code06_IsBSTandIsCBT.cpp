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
#include <stack>
#include <queue>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

bool IsBST(Ptr head) {
	if (!head) return true;

	std::stack<Ptr> stk;
	int minNum = INT_MIN;
	while (!stk.empty() || head) {
		if (head) {
			stk.push(head);
			head = head->left;
		}
		else {
			head = stk.top();
			if (head->value >= minNum)
				minNum = head->value;
			else
				return false;
			stk.pop();
			head = head->right;
		}
	}
	return true;
}

bool IsCBT(Ptr head) {
	if (!head) return true;

	std::queue<Ptr> que;
	que.push(head);
	Ptr L = nullptr;
	Ptr R = nullptr;
	bool leaf = false;
	while (!que.empty()) {
		head = que.front();
		que.pop();
		L = head->left;
		R = head->right;
		if ((leaf && (L || R)) || (!L && R)) {
			return false;
		}
		if (L) {
			que.push(L);
		}
		if (R) {
			que.push(R);
		}
		else { //L==nullptr || R==nullptr
			leaf = true;
		}
	}
}

int main(){
	typename Ptr head(new TreeNode(10));  //不加typename，编译器会推断为函数声明
	head->left = std::make_shared<TreeNode>(TreeNode(9));
	head->right = std::make_shared<TreeNode>(TreeNode(15));
	head->left->left = std::make_shared<TreeNode>(TreeNode(8));
	head->left->right = std::make_shared<TreeNode>(TreeNode(10));
	head->left->left->left = std::make_shared<TreeNode>(TreeNode(5));
	head->right->left = std::make_shared<TreeNode>(TreeNode(12));
	head->right->left->left = std::make_shared<TreeNode>(TreeNode(11));
	head->right->right = std::make_shared<TreeNode>(TreeNode(18));
	head->right->right->left = std::make_shared<TreeNode>(TreeNode(17));
	head->right->right->right = std::make_shared<TreeNode>(TreeNode(20));

	//std::cout << IsBST(head);
	std::cout << IsCBT(head);
}	