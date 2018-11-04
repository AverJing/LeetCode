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

struct Node {
	int value;
	Node* next;
	Node(unsigned v) :value(v),next(nullptr) {}
};

struct DoubleNode {
	int value;
	DoubleNode* next;
	DoubleNode* prev;
	DoubleNode(unsigned v) :value(v), next(nullptr),prev(nullptr) {}
};

Node* reverseNode(Node* head) {
	if (!head) return nullptr;
	
	Node* pre = nullptr;	
	Node* nextNode;
	while (head) {
		nextNode = head->next;
		head->next = pre;
		pre = head;
		head = nextNode;
	}
	return pre;
}

void PrintNode(Node* head) {
	if (!head) return;

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

DoubleNode* reverseDoubleNode(DoubleNode* head) {
	if (!head) return nullptr;

	DoubleNode* pre = nullptr;
	DoubleNode* nextNode;
	while (head) {
		nextNode = head->next;
		head->next = pre;
		head->prev = nextNode;//difference
		pre = head;
		head = nextNode;
	}
	return pre;
}

void PrintDoubleNode(DoubleNode* head) {
	if (!head) return;

	while (head) {
		std::cout << head->value << ' ';
		head = head->next;
	}
}

void destroy(DoubleNode* head) {
	if (!head) return;

	while (head) {
		auto tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main(){
	/*
	auto head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);

	auto head = reverseNode(head1);

	PrintNode(head);

	destroy(head);*/

	auto head1 = new DoubleNode(1);
	head1->next = new DoubleNode(2);
	head1->next->prev = head1;
	head1->next->next = new DoubleNode(3);
	head1->next->next->prev = head1->next;

	auto head = reverseDoubleNode(head1);

	PrintDoubleNode(head);

	destroy(head);
}	