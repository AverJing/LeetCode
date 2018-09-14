/*
*
*
*@author: Aver Jing
*@description：
*@date：Sep 14, 2018
*
*
*/
/*
Given a non-empty string s and a dictionary wordDict containing 
a list of non-empty words, determine if s can be segmented into 
a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
			 Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
#pragma once

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (std::find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) return true;
		std::vector<string::const_iterator> cache{ s.cbegin() };

		for (auto subEnd = s.cbegin(); subEnd != s.cend(); ++subEnd) {
			for (auto subBeg : cache) {
				if (subBeg < subEnd &&
					std::find(wordDict.begin(), wordDict.end(), string(subBeg, subEnd)) != wordDict.end()) {
					if (std::find(wordDict.begin(), wordDict.end(), string(subEnd, s.cend())) != wordDict.end())
						return true;
					cache.push_back(subEnd); break;
				}
			}
		}
		return false;
	}
};
