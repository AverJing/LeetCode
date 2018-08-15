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

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#pragma once

#include <vector>
#include <string>
#include <array>

using std::vector; using std::string; using std::array;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret{ "" };
		if (digits.empty()) return vector<string>();
		array<string, 10> map{ "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (auto digit : digits) {
			vector<string> tmp;
			for (auto c : map[digit - '0'])
				for (const auto &pre : ret)
					tmp.push_back(pre + c);
			ret = tmp;
		}
		return ret;
	}
};
