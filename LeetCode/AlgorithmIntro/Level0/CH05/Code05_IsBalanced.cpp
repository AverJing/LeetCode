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
#include <algorithm>

class TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

std::pair<bool, int> process(Ptr head) {
	if (!head) return { true, 0 };
	auto leftData = process(head->left);
	if (!leftData.first)
		return { false, 0 };
	auto rightData = process(head->right);
	if (!rightData.first)
		return { false, 0 };
	if (std::abs(rightData.first - leftData.first) > 1)
		return { false, 0 };

	return { true, std::max(leftData.second, rightData.second) + 1 };
}

int main(){
	typename Ptr head(new TreeNode(5));  //不加typename，编译器会推断为函数声明
	head->left = std::make_shared<TreeNode>(TreeNode(3));
	head->right = std::make_shared<TreeNode>(TreeNode(8));
	head->left->left = std::make_shared<TreeNode>(TreeNode(2));
	head->left->right = std::make_shared<TreeNode>(TreeNode(4));
	head->left->left->left = std::make_shared<TreeNode>(TreeNode(3));
	head->right->left = std::make_shared<TreeNode>(TreeNode(7));
	head->right->left->left = std::make_shared<TreeNode>(TreeNode(6));
	head->right->right = std::make_shared<TreeNode>(TreeNode(10));
	head->right->right->left = std::make_shared<TreeNode>(TreeNode(9));
	head->right->right->right = std::make_shared<TreeNode>(TreeNode(11));

	std::cout << process(head).first << std::endl;
}	