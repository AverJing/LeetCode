/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//用数组结构实现大小固定的栈和队列
#include <iostream>
#include <vector>

template<class T>
class Stack {
public:
	Stack(unsigned size):index(0) { data.resize(size, 0); }
	T push(const T& rhs) {
		if (index >= data.size())
			throw std::runtime_error("the stack is full.");
		data[index++] = rhs;
	}
	T pop() {
		if (index == 0)
			throw std::runtime_error("the stack is empty.");
		return data[--index];
	}
	T peek() {
		if(index==0)
			throw std::runtime_error("the stack is empty.");
		return data[index-1];
	}
private:
	size_t index;
	std::vector<T> data;
};

template<class T>
class Queue {
public:
	Queue(unsigned size) :start(0),end(0),size(0) { data.resize(size, 0); }
	void push(const T& rhs) {
		if (size >= data.size())
			throw std::runtime_error("the stack is full.");
		++size;
		data[end++%data.size()] = rhs;
	}
	T pop() {
		if (size == 0)
			throw std::runtime_error("the stack is empty.");
		--size;
		return data[start++%data.size()];
	}
	T peek() {
		if (size == 0)
			throw std::runtime_error("the stack is empty.");
		return data[start];
	}
private:
	size_t start;
	size_t end;
	size_t size;
	std::vector<T> data;
};

int main(){
	/*
	Stack<int> s(10);
	for(int i = 0; i < 8; ++i)
		s.push(i);
	std::cout << s.peek() << ' ';
	std::cout << s.pop() << ' ';
	std::cout << s.pop() << ' ';   
	s.push(9);
	std::cout << s.pop() << ' ';*/

	//注意函数在std::cout << s.pop() << ' '<< s.pop()
	//两个函数调用顺序可不一定。。。。这就导致了输出结果可能出错 6  7

	Queue<int> s(10);
	for (int i = 0; i < 8; ++i)
		s.push(i);
	std::cout << s.peek() << ' ';
	std::cout << s.pop() << ' ';
	std::cout << s.pop() << ' ';
	s.push(9);
	s.push(10);
	s.push(11);
	std::cout << s.pop() << ' ';
	std::cout << s.pop() << ' ';
	std::cout << s.pop() << ' ';
	std::cout << s.pop() << ' ';
	std::cout << s.pop() << ' ';
}	