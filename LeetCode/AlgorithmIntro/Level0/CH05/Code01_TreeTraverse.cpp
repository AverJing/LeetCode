/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//此部分对数的遍历做一个总结
//涉及到递归的   先中后
//非递归的  先中后 层次
//以及  神级遍历   Morrise
#include <iostream>
#include <memory>
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

void PreOrderRecur(std::shared_ptr<TreeNode> head) {
	if (!head) return;

	std::cout << head->value << ' ';
	PreOrderRecur(head->left);
	PreOrderRecur(head->right);
}

void InOrderRecur(std::shared_ptr<TreeNode> head) {
	if (!head) return;

	InOrderRecur(head->left);
	std::cout << head->value << ' ';
	InOrderRecur(head->right);
}

void PostOrderRecur(std::shared_ptr<TreeNode> head) {
	if (!head) return;

	PostOrderRecur(head->left);
	PostOrderRecur(head->right);
	std::cout << head->value << ' ';
}

void PreOrderIter(std::shared_ptr<TreeNode> head) {
	if (!head) return;

	std::stack<Ptr> stk;
	stk.push(head);
	while (!stk.empty()) {
		auto data = stk.top();
		std::cout << data->value << ' ';
		stk.pop();

		if (data->right)
			stk.push(data->right);
		if (data->left)
			stk.push(data->left);
	}
}

void InOrderIter(std::shared_ptr<TreeNode> head) {
	if (!head) return;

	std::stack<Ptr> stk;   //区分先序，循环条件的些许差别  因为先序第一个访问的肯定是根节点
						//而中序不一定，这样是为了规整
	while (!stk.empty()|| head) {
		if (head) {
			stk.push(head);
			head = head->left;
		}
		else {
			head = stk.top();
			std::cout << head->value << ' ';
			stk.pop();
			head = head->right;
		}
	}
}

void PostOrderIter(std::shared_ptr<TreeNode> head) {
	if (!head) return;

	std::stack<Ptr> stk; 
	stk.push(head);
	std::stack<Ptr> post;
	while (!stk.empty()) {
		auto data = stk.top();
		post.push(data);
		stk.pop();

		if (data->left)
			stk.push(data->left);
		if (data->right)
			stk.push(data->right);
	}

	while (!post.empty()) {
		auto data = post.top();
		post.pop();
		std::cout << data->value << ' ';
	}
}

void PostOrderIter2(std::shared_ptr<TreeNode> head) {
	if (!head) return;

	std::stack<Ptr> stk; 
	Ptr pre = nullptr;
	while (!stk.empty() || head) {
		if (head) {
			stk.push(head);
			head = head->left;
		}
		else {
			head = stk.top();				
			if (head->right&&head->right != pre) {
				head = head->right;
			}
			else {
				stk.pop();
				std::cout << head->value << ' ';
				pre = head;
				head = nullptr;
			}
		}
	}
}

void LevelOrderIter(std::shared_ptr<TreeNode> head) {
	//if (!head) return;

	std::queue<Ptr> que;
	que.push(head);
	while (!que.empty()) {
		Ptr data = que.front();
		que.pop();
		if (data) {
			std::cout << data->value << ' ';
		}
		else {
			std::cout << "NULL" << ' ';
			continue;
		}
		que.push(data->left);
		que.push(data->right);
	}
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

	/* 层次遍历给出该树
	 5 3 8 2 4 7 10 3 nullptr nullptr nullptr 6 nullptr 9 11	
	*/

	/*
	PreOrderRecur(head);
	std::cout << std::endl;	

	PreOrderIter(head);
	std::cout << std::endl;*/

	/*
	InOrderRecur(head);
	std::cout << std::endl;
	InOrderIter(head);
	std::cout << std::endl;
	*/
	/*
	PostOrderRecur(head);
	std::cout << std::endl;
	PostOrderIter(head);
	std::cout << std::endl;
	PostOrderIter2(head);
	std::cout << std::endl;*/

	LevelOrderIter(head);
	std::cout << std::endl;
	
}	