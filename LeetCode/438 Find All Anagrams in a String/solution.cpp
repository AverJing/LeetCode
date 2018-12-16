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
Given a string s and a non-empty string p, find all the start indices of 
p's anagrams in s.

Strings consists of lowercase English letters only and the length of 
both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::string;

//关于滑动窗口求解的总结
//https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.

class Solution {
public:
	//暴力解
	//果然不行。
	//22!= 1124000727777607680000...
	/*
	vector<int> findAnagrams(const string& s, const string& p) {
		if (s.empty() || p.empty()) return {};
		auto tmp(p);
		std::sort(tmp.begin(), tmp.end());

		std::unordered_set<string> com;
		vector<int> res;
		do {
			com.insert(tmp);
		} while (std::next_permutation(tmp.begin(),tmp.end()));

		int n = s.size() - p.size();
		int len = p.size();
		for (int i = 0; i <= n; ++i) {
			if (com.find(s.substr(i, len)) != com.end())
				res.push_back(i);
		}

		return res;
	}*/
	/* TLE  超时
	vector<int> findAnagrams(const string& s, const string& p) {
		if (s.empty() || p.empty()) return {};
		auto tmp(p);
		std::sort(tmp.begin(), tmp.end());

		vector<int> res;
		std::unordered_set<string> compa;
		compa.insert(tmp);
		int n = s.size() - p.size();
		int len = p.size();
		for (int i = 0; i <= n; ++i) {
			auto sub = s.substr(i, len);
			std::sort(sub.begin(), sub.end());
			if (compa.find(sub)!=compa.end())
				res.push_back(i);
		}

		return res;
	}*/
	/*比前边的好一点，但是还是超时
	vector<int> findAnagrams(const string& s, const string& p) {
		if (s.empty() || p.empty()) return {};

		vector<int> res;
		std::unordered_map<char, int> cmp;
		for (auto e : p) {
			++cmp[e];
		}
		int n = s.size() - p.size();
		int len = p.size();
		for (int i = 0; i <= n; ++i) {
			auto sub = s.substr(i, len);
			auto copyMap(cmp);
			if (checkValid(copyMap, sub))
				res.push_back(i);		
		}
		return res;
	}
	bool checkValid(std::unordered_map<char, int>& copyMap, const string& sub) {
		for (auto e : sub) {
			if (copyMap.find(e) == copyMap.end())
				return false;
			else {
				if (--copyMap[e] < 0) return false;
			}
		}
		return true;
	}*/
	//使用滑动窗口求解
	//精妙在，减少判断，结合全部都是a的情况分析。
	vector<int> findAnagrams(const string& s, const string& p) {
		if (s.empty() || p.empty()) return {};

		vector<int> res;
		std::unordered_map<char, int> cmp;
		for (auto e : p) {
			++cmp[e];
		}
		int lens= s.size();
		int count = p.size();
		int start = 0, end = 0;
		while (end < lens){ 
			if (cmp.find(s[end]) != cmp.end()) {
				if (--cmp[s[end]] >= 0) --count;
			}
			++end;

			while (count == 0) {
				if (cmp.find(s[start]) != cmp.end()) {
					if (++cmp[s[start]] > 0) ++count;
				}
				if (end - start == p.size())
					res.push_back(start);
				++start;
			}
		}
		return res;
	}
};

int main(){
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string p = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	Solution so;

	for (auto e : so.findAnagrams(s, p)) {
		std::cout << e << ' ';
	}
}	