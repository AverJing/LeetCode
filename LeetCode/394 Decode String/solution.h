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
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside 
the square brackets is being repeated exactly k times. Note that k is guaranteed
to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, 
square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits 
and that digits are only for those repeat numbers, k. For example, there won't 
be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
#pragma once
//如何加密呢？  反向过程怎么做？  网易面试考过。
#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
	//wrong 
	/*
	string decodeString(string s) {
		int frequence = 0; 
		string::iterator start;
		string result;
		for (auto it = s.begin(); it != s.end(); ++it) {
			if (*it >= '1' && *it <= '9') {
				frequence = *it - '0';
				start = std::next(it);
			}
			if (std::next(it) == s.end() || *std::next(it) >= '1' && *std::next(it) <= '9') {
				while (--frequence >= 0) {
					result += s.substr(start - s.begin()+1, it - start);
				}
			}
		}
		return result;
	}*/
	string decodeString(string s) {
		int frequence = 0;
		stack<string::iterator> stk;
		string result;
		for (auto it = s.begin(); it != s.end(); ++it) {
			if (*it == ']') {
				stk.pop();
				frequence = *stk.top();

			}
			if (!isalpha(*it)) stk.push(it);
		}
		return result;
	}
};
