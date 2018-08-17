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
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.
	Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
#pragma once

#include <string>
#include <stack>

using std::string; using std::stack;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (auto c : s)
			if (!stk.empty() && ((c == ')' && stk.top() == '(') || (c == '}' && stk.top() == '{') || (c == ']' && stk.top() == '['))) stk.pop();
			else stk.push(c);
			return stk.empty();
	}
};
