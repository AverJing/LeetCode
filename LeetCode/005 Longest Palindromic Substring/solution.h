#pragma once
/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example2:
Input: "cbbd"
Output: "bb"
*/

#include <string>

using std::string;

class Solution {
	void longestPalindrome(const string& s, int b, int e, int &start, int &end) {
		int len = s.size();
		while (b > 0 && e < len && s[b] == s[e])
			--b, ++e;
		++b, --e;
		if (e - b > end - start) {
			start = b;
			end = e;
		}
	}
public:
	string longestPalindrome(string s) {
		int len = s.size(); 
		if (len == 0) return s;
		int start = 0, end = 0;
		for (int i = 0; i < s.size - 1; ++i) {
			longestPalindrome(s, i, i, start, end);
			longestPalindrome(s, i, i+1, start, end);
		}
		return s.substr(start, end - start + 1);
	}
};