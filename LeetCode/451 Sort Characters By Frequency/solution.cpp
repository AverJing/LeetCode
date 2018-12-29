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
Given a string, sort it in decreasing order based on the frequency of 
characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>

using std::string;
using std::unordered_map;
using std::vector;
using std::map;

class Solution {
public:
	string frequencySort(string s) {
		map<char, int> charCount;

		for (auto e : s)
			++charCount[e];

		vector<string> result(s.size()+1, "\0");
		for (auto& e : charCount) {
			result[e.second].push_back(e.first);
		}

		string res;
		for (int i = s.size(); i>= 0; --i) {
			if (result[i] != "\0") {
				for (auto c : result[i])
					res += string(i, c);
			}
		}

		return res;
	}
};

int main(){

	return 0;
}