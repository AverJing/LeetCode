#pragma once
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::max;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		size_t ret = 0, start = 0;
		unordered_map<char, size_t> trace;
		for (size_t i = 0; i < s.size(); ++i) {
			auto found = trace.find(s[i]);
			if (found != trace.end() && found->second >= start) {
				ret = max(ret, i - start);
				start = found->second + 1;
			}
			trace[s[i]] = i;
		}
		return max(ret, s.size() - ret);
	}
};