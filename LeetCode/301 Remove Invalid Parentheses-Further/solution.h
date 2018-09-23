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
Remove the minimum number of invalid parentheses in order to 
make the input string valid. Return all possible results.

Note: The input string may contain letters other than the 
parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
*/
#pragma once

#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <queue>

using std::vector;
using std::string;
using std::stack;
using std::unordered_set;
using std::queue;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> result;
		unordered_set<string> visited({s});
		queue<string> q({ s }); bool found = false;
		while (!q.empty()) {
			string t = q.front(); q.pop();
			if (isValid(t)) {
				result.push_back(t);
				found = true;
			}
			if (found) continue;
			for (int i = 0; i < t.size(); ++i) {
				if (t[i] != ')' && t[i] != '(') continue;
				string str = t.substr(0, i) + t.substr(i + 1);
				if (!visited.count(str)) {
					q.push(str);
					visited.insert(str);
				}
			}
		}
	}
private:
	bool isValid(string s) {
		stack<char> stk;
		for (auto c : s)
			if (!stk.empty() && ((c == ')' && stk.top() == '('))) stk.pop();
			else if (isalpha(c)) continue;
			else stk.push(c);
		return stk.empty();
	}
};
