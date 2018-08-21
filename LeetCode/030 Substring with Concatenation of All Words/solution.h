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
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word 
in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []
*/
#pragma once

#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if (s.empty() || words.empty()) return res;
		//store single word in words
		unordered_map<string, int> counts;
		for (auto &e : words)++counts[e];

		int words_len = words.size(), word_len = words[0].size();
		for (auto i = 0; i <= int(s.size()) - words_len * word_len; ++i) {
			//store the staring word which is substring in s and its location 
			unordered_map<string, int> seen;
			int j = 0;
			for (j = 0; j < words_len; ++j) {
				auto t = s.substr(i + j * word_len, word_len);
				if (counts.find(t) == counts.end()) break;
				++seen[t];
				if (seen[t] > counts[t])
					break;
			}
			if (j == words_len)
				res.push_back(i);
		}
		return res;
	}
};
