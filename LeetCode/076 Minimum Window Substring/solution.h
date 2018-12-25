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
Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, 
return the empty string "".
If there is such window, you are guaranteed that there will 
always be only one unique minimum window in S.
*/
#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
	/* wrong answer
	string minWindow(string s, string t) {
		map<int, string> result;
		int count = 0;
		for (int i = 0, j = 1; i < s.size() - t.size();) {
			if (t.find(s[i]) != string::npos) {
				++count;
				if (s[j] == s[i]) ++i;
				else if (t.find(s[j]) != string::npos) {
					++count;
					++j;
				}
				else ++j;
				if (count == 3) result[j - i + 1] = s.substr(i, j - i + 1), count = 0;
			}
			else {
				++i;
			}
		}
		return result.begin()->second;
	}*/
	//更快
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t) ++map[c];
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < s.size()) {
			if (map[s[end++]]-- > 0) counter--; //in t
			while (counter == 0) { //valid
				if (end - begin < d)  d = end - (head = begin);
				if (map[s[begin++]]++ == 0) counter++;  //make it invalid
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
	/*
	string minWindow(string s, string t) {
		unordered_map<char, int> map;
		for (auto c : t) ++map[c];
		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < s.size()) {
			if (map.find(s[end]) != map.end()) {
				if (--map[s[end]] >= 0) --counter;
			} 
			++end;
			while (counter == 0) { //valid
				if (end - begin < d)  d = end - (head = begin);
				if (map.find(s[begin]) != map.end()) {
					if (++map[s[begin]] > 0) ++counter;
				}
				++begin;
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}*/
};