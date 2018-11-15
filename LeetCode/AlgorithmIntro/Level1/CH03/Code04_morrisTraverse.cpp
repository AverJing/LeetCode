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
#include <vector>
#include <string>
#include <queue>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

void morrisPre(Ptr head) {
	if (!head) return;

	Ptr mostRight = nullptr;

	while (head) {
		if (head->left) {
			mostRight = head->left;
			while (mostRight->right && mostRight->right != head) {
				mostRight = mostRight->right;
			}
			if (!mostRight->right) {
				std::cout << head->value << ' ';
				mostRight->right = head;
				head = head->left;
				continue;
			}
			else {
				mostRight->right = nullptr;
				//std::cout << head->value << ' ';
			}
		}
		if(!head->left) std::cout << head->value << ' ';		
		head = head->right;
	}
	std::cout << std::endl;
}

void morrisIn(Ptr head) {
	if (!head) return;

	Ptr mostRight = nullptr;

	while (head) {
		if (head->left) {
			mostRight = head->left;
			while (mostRight->right && mostRight->right != head) {
				mostRight = mostRight->right;
			}
			if (!mostRight->right) {
				mostRight->right = head;
				head = head->left;
				continue;
			}
			else {
				mostRight->right = nullptr;
			}
		}
		std::cout << head->value << ' ';
		head = head->right;
	}
	std::cout << std::endl;
}

Ptr reverseNode(Ptr head) {
	Ptr next = nullptr;
	Ptr pre = nullptr;
	while (head) {
		next = head->right;
		head->right = pre;
		pre = head;
		head = next;
	}
	return pre;
}

void PrintEdge(Ptr head) {
	auto tail = reverseNode(head);
	auto old_tail = tail;
	while (tail) {
		std::cout << tail->value << ' ';
		tail = tail->right;
	}
	reverseNode(old_tail);
}

void morrisPost(Ptr head) {
	if (!head) return;

	Ptr mostRight = nullptr;
	auto old_head = head;
	while (head) {
		if (head->left) {
			mostRight = head->left;
			while (mostRight->right && mostRight->right != head) {
				mostRight = mostRight->right;
			}
			if (!mostRight->right) {
				mostRight->right = head;
				head = head->left;
				continue;
			}
			else {
				mostRight->right = nullptr;
				PrintEdge(head->left);
			}
		}
		head = head->right;
	}
	PrintEdge(old_head);
	std::cout << std::endl;
}

std::vector<std::string> splitByPara(std::string preStr, const std::string& para = "_") {
	if (preStr.empty()) return {};
	std::vector<std::string> data;
	for (int pos = preStr.find_first_of(para); pos != std::string::npos; pos = preStr.find_first_of(para)) {
		data.push_back(preStr.substr(0, pos));
		preStr = preStr.substr(pos + 1);
	}
	return data;
}

std::shared_ptr<TreeNode> reconByPreOrder(std::queue<std::string>& que) {
	auto data = que.front();
	que.pop();
	if (data == "#")
		return nullptr;
	std::shared_ptr<TreeNode> head(new TreeNode(std::stoi(data)));
	head->left = reconByPreOrder(que);
	head->right = reconByPreOrder(que);

	return head;
}

std::shared_ptr<TreeNode> reconByPreString(const std::string& preStr) {
	std::vector<std::string> values = splitByPara(preStr);
	std::queue<std::string> que;
	for (int i = 0; i < values.size(); ++i)
		que.push(values[i]);
	return reconByPreOrder(que);
}

int main(){
	auto head = reconByPreString("1_2_4_#_#_5_#_#_3_6_#_#_#_");

	morrisPre(head);
	morrisIn(head);
	morrisPost(head);
}	