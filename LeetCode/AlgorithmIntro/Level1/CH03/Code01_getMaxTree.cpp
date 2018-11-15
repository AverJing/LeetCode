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

#include <iostream>
#include <memory>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

template<class T>
using Arr = std::vector<T>;

using HashMap = std::unordered_map<Ptr, std::pair<Ptr, Ptr>>;
//cur left right

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

void popStackSetMap(std::stack<Ptr>& s, HashMap& map, const Ptr& cur) {
	auto s_top = s.top();
	s.pop();
	if (s.empty()) {
		map[s_top] = { nullptr, cur };
	}
	else {
		map[s_top] = { s.top(), cur };
	}
}

//注意数组中没有重复元素
template<class T>
Ptr getMaxTree(const Arr<T>& data) {
	if (data.empty()) return nullptr;

	Arr<Ptr> node(data.size(), nullptr);
	for(int i = 0; i < data.size(); ++i)
		node[i] = std::make_shared<TreeNode>(data[i]);

	HashMap MaxMap;
	std::stack<Ptr> s;

	for (int i = 0; i < data.size(); ++i) {
		auto cur = node[i];
		while (!s.empty() && s.top()->value < data[i]) {
			popStackSetMap(s, MaxMap, cur);
		}
		s.push(node[i]);
	}
	while (!s.empty()) {
		popStackSetMap(s, MaxMap, nullptr);
	}

	Ptr head = nullptr;

	for (int i = 0; i < node.size(); ++i) {
		auto cur = node[i];
		auto res = MaxMap.find(cur);
		//结构如下  node  left right
		//node是当前访问节点  left是左边离他最近比node大的点，right是右边。。
		//nullptr代表没有或者到达边界
		if (!res->second.first && !res->second.second) {
			head = res->first;
		}
		else if (!res->second.first) {
			if (!res->second.second->left) {
				res->second.second->left = res->first;
			}
			else {
				res->second.second->right = res->first;
			}
		}
		else if (!res->second.second) {
			if (!res->second.first->left) {
				res->second.first->left = res->first;
			}
			else {
				res->second.first->right = res->first;
			}
		}
		else {
			auto tmp = res->second.first->value < res->second.second->value ? res->second.first : res->second.second;
			if (!tmp->left) {
				tmp->left = res->first;
			}
			else {
				tmp->right = res->first;
			}
		}
	}
	return head;
}

void PreTraverse(Ptr head) {
	if (!head) return;

	std::cout << head->value << ' ';
	PreTraverse(head->left);
	PreTraverse(head->right);
}

void InTraverse(Ptr head) {
	if (!head) return;

	InTraverse(head->left);
	std::cout << head->value << ' ';
	InTraverse(head->right);
}

int main(){
	Arr<int> ivec{ 3,2,4,1,0,5 };
	auto head = getMaxTree(ivec);
	PreTraverse(head);
	std::cout << std::endl;
	InTraverse(head);
}	