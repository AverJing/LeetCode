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
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> cache;
		vector<vector<string>> ret;
		for (auto iter = strs.begin(); iter != strs.end(); ++iter) {
			string str_temp(*iter);
			sort(str_temp.begin(), str_temp.end());
			cache[str_temp].push_back(*iter);
		}
		for (auto iter = cache.begin(); iter != cache.end(); ++iter) {
			ret.push_back(iter->second);
		}
		return ret;
	}
};
