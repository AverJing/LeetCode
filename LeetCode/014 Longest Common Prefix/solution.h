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
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:

All given inputs are in lowercase letters a-z.
*/
#pragma once

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

/*
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result;
		if (strs.empty()) return result;

		//use STL sort algorithm
		sort(strs.begin(), strs.end());
		
		auto beg = strs.begin();
		auto end = prev(strs.end());
		for (auto i = 0; i < beg->size() && i < end->size(); ++i) {
			if ((*beg)[i] == (*end)[i])
				result.push_back((*beg)[i]);
			else
				return result;
		}
		return result;
	}
};*/

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()) return "";
		for (size_t i = 0; i<strs.front().size(); ++i) {
			for (const auto &str : strs)
				if (i == str.size() || str.at(i) != strs.front().at(i))
					return strs.front().substr(0, i);
		}
		return strs.front();
	}
};

