/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//实现一个保存最小值的栈
#include <iostream>
#include <stack>

template<class T>
class minStack {
public:
	minStack() = default;
	void push(const T& rhs) {
		data.push(rhs);
		if (minNum.empty())
			minNum.push(rhs);
		else if(minNum.top()>rhs)
			minNum.push(rhs);
		else if (minNum.top() < rhs)
			minNum.push(minNum.top());
	}
	T pop() {
		minNum.pop();
		T tmp = data.top();
		data.pop();
		return tmp;
	}
	T getMin() {
		return minNum.top();
	}
private:
	std::stack<T> data;
	std::stack<T> minNum;
};

template<class T>
class minStack_fix {
public:
	minStack_fix() = default;
	void push(const T& rhs) {
		data.push(rhs);
		if (minNum.empty())
			minNum.push(rhs);
		else if (minNum.top() > rhs)
			minNum.push(rhs);
	}
	T pop() {		
		T tmp = data.top();
		if(minNum.top() == tmp)
			minNum.pop();
		data.pop();
		return tmp;
	}
	T getMin() {
		return minNum.top();
	}
private:
	std::stack<T> data;
	std::stack<T> minNum;
};

int main(){
	minStack_fix<int> s;

	for (int i = 0; i < 10; ++i)
		s.push(i);
	std::cout << s.getMin() << ' ';
	s.pop();
	std::cout << s.getMin() << ' ';
	s.pop();
	std::cout << s.getMin() << ' ';
	s.pop();
	std::cout << s.getMin() << ' ';
	s.pop();
	std::cout << s.getMin() << ' ';
}	