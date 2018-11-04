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

template<class T>
class Queue {
public:
	Queue() = default;
	void push(const T& rhs) {
		pushStk.push(rhs);
	}
	T pop() {
		if (popStk.empty() && pushStk.empty())
			throw std::runtime_error("this queue is empty");
		else if (popStk.empty()) {
			while (!pushStk.empty()) {
				popStk.push(pushStk.top());
				pushStk.pop();
			}
		}
		T tmp = popStk.top();
		popStk.pop();
		return tmp;
	}
	T peek() {
		if (popStk.empty() && pushStk.empty())
			throw std::runtime_error("this queue is empty");
		else if (popStk.empty()) {
			while (!pushStk.empty()) {
				popStk.push(pushStk.top());
				pushStk.pop();
			}
		}
		return popStk.top();
	}
private:
	std::stack<T> pushStk;
	std::stack<T> popStk;
};

//be not familiar
template<class T>
class Stack {
public:
	Stack() = default;
	void push(const T& rhs) {
		queue.push(rhs);
	}
	T pop() {
		if (queue.empty())
			throw std::runtime_error("this queue is empty");
		while(queue.size() > 1) {
			help.push(queue.front());
			queue.pop();
		}
		T tmp = queue.front();
		queue.pop();
		std::swap(queue, help);
		return tmp;
	}
	T peek() {
		if (queue.empty())
			throw std::runtime_error("this queue is empty");
		while (queue.size() > 1) {
			help.push(queue.front());
		}
		T tmp = queue.front();
		queue.pop();
		help.push(tmp);
		std::swap(queue, help);
		return tmp;
	}
private:
	std::queue<T> queue;
	std::queue<T> help;
};

int main(){
	/*
	Queue<int> q;
	for (int i = 0; i < 10; ++i)
		q.push(i);
	std::cout << q.pop() << ' ';
	std::cout << q.pop() << ' ';
	std::cout << q.pop() << ' ';
	std::cout << q.pop() << ' ';*/

	Stack<int> q;
	for (int i = 0; i < 10; ++i)
		q.push(i);
	std::cout << q.pop() << ' ';
	std::cout << q.pop() << ' ';
	std::cout << q.pop() << ' ';
	std::cout << q.pop() << ' ';
}	