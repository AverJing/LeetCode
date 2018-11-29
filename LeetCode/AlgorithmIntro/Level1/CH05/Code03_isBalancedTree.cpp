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
#include <memory>
#include <algorithm>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

struct ReturnType {
	bool balance;
	int height;
	ReturnType(bool is, int h) :balance(is), height(h) {}
};

ReturnType isBalancedTree(Ptr head) {
	if (!head) return{ true,0 };

	auto left = isBalancedTree(head->left);
	if (!left.balance) return { false,0 };
	auto right = isBalancedTree(head->right);
	if (!right.balance) return { false,0 };

	if (std::abs(left.height - right.height) > 1)
		return{ false,0 };
	return { true, std::max(left.height,right.height)+1 };
}


int main(){
	
}	