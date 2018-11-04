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
#include <unordered_map>

struct Node {
	int value;
	Node* next;
	Node* random;
	Node(unsigned v) :value(v), next(nullptr),random(nullptr) {}
};

Node* copyListWithRand1(Node* head) {
	std::unordered_map<Node*, Node*> map;
	Node* cur = head;
	while (cur) {
		map.insert({ cur, new Node(cur->value) });
		cur = cur->next;
	}
	cur = head;
	while (cur) {
		auto result = map.find(cur);
		result->second->next = cur->next ? map.find(cur->next)->second : nullptr;
		result->second->random = cur->random ? map.find(cur->random)->second : nullptr;
		cur = cur->next;
	}
	return map.find(head)->second;
}

//第二种 方法，原地拷贝，剑指offer原题
Node* copyListWithRand2(Node* head) {
	if (!head) return nullptr;

	Node* cur = head;
	Node* next = nullptr;
	while (cur)
	{
		next = cur->next;
		cur->next = new Node(cur->value);
		cur->next->next = next;
		cur = next;
	}
	//set copy node random
	cur = head;
	Node* curCopy = nullptr;
	while (cur) {
		next = cur->next->next;
		curCopy = cur->next;
		curCopy->random = cur->random ? cur->random->next : nullptr;
		cur = next;
	}

	cur = head;
	auto res = head->next;
	//split
	while (cur) {
		next = cur->next->next;
		curCopy = cur->next;
		cur->next = next;
		curCopy->next = next ? next->next : nullptr;
		cur = next;
	}

	return res;
}


void PrintNode(Node* head) {
	if (!head) return;

	Node* curr = head;
	std::cout << " order: ";
	while (head) {
		std::cout << head->value << ' ';
		head = head->next;
	}
}

void destroy(Node* head) {
	if (!head) return;

	while (head) {
		auto tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main(){
	auto head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
			  
	head->random = head->next->next->next->next->next; // 1 -> 6
	head->next->random = head->next->next->next->next->next; // 2 -> 6
	head->next->next->random = head->next->next->next->next; // 3 -> 5
	head->next->next->next->random = head->next->next; // 4 -> 3
	head->next->next->next->next->random = nullptr; // 5 -> null
	head->next->next->next->next->next->random = head->next->next->next; // 6 -> 4

	//auto headCopy = copyListWithRand1(head);
	auto headCopy = copyListWithRand2(head);

	PrintNode(headCopy);

	destroy(head);
	destroy(headCopy);
}	