/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//寻找中序遍历的前驱和后继节点
#include <iostream>
#include <string>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	std::shared_ptr<TreeNode> parent;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr), parent(nullptr) {}
};


Ptr getMostLeftNode(Ptr node) {
	while (node->left) {
		node = node->left;
	}
	return node;
}

Ptr getMostRightNode(Ptr node) {
	while (node->right) {
		node = node->right;
	}
	return node;
}

Ptr getSuccessorNode(Ptr node) {
	if (!node) return nullptr;

	if (node->right) {
		return getMostLeftNode(node->right);
	}
	else {
		auto p1 = node->parent;
		while (p1&&p1->left != node) {
			node = p1;
			p1 = p1->parent;
		}
		return p1;
	}
}

Ptr getPoineerNode(Ptr node) {
	if (!node) return nullptr;

	if (node->left) {
		return getMostRightNode(node->left);
	}
	else {
		auto p1 = node->parent;
		while (p1&&p1->right != node) {
			node = p1;
			p1 = p1->parent;
		}
		return p1;
	}
}

int main(){
	typename Ptr head(new TreeNode(5));  //不加typename，编译器会推断为函数声明
	head->left = std::make_shared<TreeNode>(TreeNode(3));
	head->left->parent = head;
	head->right = std::make_shared<TreeNode>(TreeNode(8));
	head->right->parent = head;
	head->left->left = std::make_shared<TreeNode>(TreeNode(2));
	head->left->left->parent = head->left;
	head->left->right = std::make_shared<TreeNode>(TreeNode(4));
	head->left->right->parent = head->left;
	head->left->left->left = std::make_shared<TreeNode>(TreeNode(3));
	head->left->left->left = head->left->left;
	head->right->left = std::make_shared<TreeNode>(TreeNode(7));
	head->right->left->parent = head->right;
	head->right->left->left = std::make_shared<TreeNode>(TreeNode(6));
	head->right->left->left->parent = head->right->left;
	head->right->right = std::make_shared<TreeNode>(TreeNode(10));
	head->right->right->parent = head->right;
	head->right->right->left = std::make_shared<TreeNode>(TreeNode(9));
	head->right->right->left->parent = head->right->right;
	head->right->right->right = std::make_shared<TreeNode>(TreeNode(11));
	head->right->right->right->parent = head->right->right;

	Ptr res = getSuccessorNode(head);//5
	std::cout << (res ? res->value : -1) << ' ';

	res = getSuccessorNode(head->left->right);//4
	std::cout << (res ? res->value : -1) << ' ';

	res = getSuccessorNode(head->right->right->right);//11
	std::cout << (res ? res->value : -1) << ' ';

	std::cout << std::endl;

	res = getPoineerNode(head);//5
	std::cout << (res ? res->value : -1) << ' ';

	res = getPoineerNode(head->left->right);//4
	std::cout << (res ? res->value : -1) << ' ';

	res = getPoineerNode(head->right->right->right);//11
	std::cout << (res ? res->value : -1) << ' ';
}	