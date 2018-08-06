#pragma once
/*
Given an input string (s) and a pattern (p), 
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

	s could be empty and contains only lowercase letters a-z.
	p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:

	Input:
	s = "aa"
	p = "a"
	Output: false
	Explanation: "a" does not match the entire string "aa".

Example 2:

	Input:
	s = "aa"
	p = "a*"
	Output: true
	Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

	Input:
	s = "ab"
	p = ".*"
	Output: true
	Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

	Input:
	s = "aab"
	p = "c*a*b"
	Output: true
	Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:

	Input:
	s = "mississippi"
	p = "mis*is*p*."
	Output: false
*/
//https://github.com/pezy/LeetCode/tree/master/009.%20Regular%20Expression%20Matching
//dig the deep meaning

#include <string>

using std::string;

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		if (s.empty() && p.empty()) return true;
		auto i = 0, j = 0, temp = 0;
		for (; j != p.size(); ++i, j = temp) {
			if (p[j+1] != '*') ++temp;
			else if (isMatch(s.substr(i), p.substr(temp + 2))) return true;
			if (i == s.size() && p[j] == '.') return false;
			if (!((p[j] == '.') || s[i] == p[j])) return false;
		}
		return i == s.size();

		/*
		const char *cs = s.c_str(), *cp = p.c_str();
		for (char c = *cp; c != '\0'; ++cs, c = *cp) {
		if (cp[1] != '*') ++cp;
		else if (isMatch(cs, cp + 2)) return true;
		if (!(c == *cs || (c == '.' && *cs != '\0'))) return false;
		}
		return *cs == '\0';*/
	}
};
//"misssssis", "mis*is"