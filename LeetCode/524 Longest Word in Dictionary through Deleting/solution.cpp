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
Given a string and a string dictionary, find the longest string in the 
dictionary that can be formed by deleting some characters of the given 
string. If there are more than one possible results, return the longest 
word with the smallest lexicographical order. If there is no possible 
result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string res;
		for (auto& e : d) {
			int j = 0;
			if (res.size() > e.size() || (res.size() == e.size() && res < e)) continue;
			for (int i = 0; i < s.size() && j < e.size();) {
				if (e[j] == s[i]) ++j, ++i;
				else ++i;
			}
			if (j == e.size()) res = e;;
		}
		return res;
	}
	/*
		string findLongestWord(string s, vector<string>& d) {
		std::sort(d.begin(), d.end(), [](const string& lhs, const string& rhs) {return lhs.size() > rhs.size() || (lhs.size() == rhs.size() && lhs < rhs); });

		for (auto& e : d) {
			int j = 0;
			for (int i = 0; i < s.size() && j < e.size();) {
				if (e[j] == s[i]) ++j, ++i;
				else ++i;
			}
			if (j == e.size()) return e;
		}
		return {};
	}
	*/
};

int main(){
	
	return 0;
}