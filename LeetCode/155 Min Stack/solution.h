/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
#pragma once

#include <vector>
#include <stack>

using std::vector;
using std::stack;

/*
class MinStack {
public:
	//initialize your data structure here.
MinStack() {

}

void push(int x) {
	if (min.empty()) min.push_back(x);
	else if (x <= min[min.size() - 1]) min.push_back(x);
	mini_stack.push_back(x);
}

void pop() {
	if (top() == min[min.size() - 1]) min.pop_back();
	mini_stack.pop_back();
}

int top() {
	return mini_stack[mini_stack.size() - 1];
}

int getMin() {
	return min[min.size() - 1];
}
private:
	vector<int> min;
	vector<int> mini_stack;
};
*/

class MinStack {
public:
	MinStack() {

	}

	void push(int x) {
		value.push(x);
		if (minv.empty() || x <= minv.top()) {
			minv.push(x);
		}

	}

	void pop() {
		if (value.top() == minv.top()) {
			minv.pop();
		}
		value.pop();

	}

	int top() {
		return value.top();
	}

	int getMin() {
		return minv.top();
	}
private:
	stack<int> value;
	stack<int> minv;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
