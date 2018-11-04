/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//the number of node in CBT
#include <iostream>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

int mostLeftLevel(Ptr head, int level) {
	while (head) {
		++level;
		head = head->left;
	}
	return level - 1;
}

int bs(Ptr head, int L, int H) {
	if (L == H) return 1;

	if (mostLeftLevel(head->right, L + 1) == H) {
		return (1 << (H - L)) + bs(head->right, L + 1, H);  //右子树高度是树高度-1，那么左子树节点个数是2^(H-L)，在递归求右子树
	}
	else {
		return (1 << (H - L - 1)) + bs(head->left, L + 1, H);//右子树高度是树高度-2，那么右子树节点个数是2^(H-L-1)，在递归求左子树
	}
}

int NodeNum(Ptr head) {
	if (!head) return 0;

	return bs(head, 1, mostLeftLevel(head, 1));
}

int main(){
	typename Ptr head(new TreeNode(5));  //不加typename，编译器会推断为函数声明
	head->left = std::make_shared<TreeNode>(TreeNode(3));
	head->right = std::make_shared<TreeNode>(TreeNode(8));
	head->left->left = std::make_shared<TreeNode>(TreeNode(2));
	head->left->right = std::make_shared<TreeNode>(TreeNode(4));
	head->left->left->left = std::make_shared<TreeNode>(TreeNode(3));
	head->right->left = std::make_shared<TreeNode>(TreeNode(7));
	head->right->right = std::make_shared<TreeNode>(TreeNode(10));

	std::cout << NodeNum(head);
}	