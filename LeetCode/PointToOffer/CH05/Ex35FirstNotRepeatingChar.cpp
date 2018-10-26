/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
	/*
	int FirstNotRepeatingChar(string str) {
		if (str.empty()) return -1;
		unordered_map<char, int>  charCount;
		for (auto e: str)
		{
			++charCount[e];
		}
		for (auto e : str) {
			auto result = charCount.find(e);
			if (result->second == 1)
				return str.find_first_of(e);
		}
		return -1;
	}*/
	int FirstNotRepeatingChar(string str) {
		if (str.empty()) return -1;
		vector<int> charCount;
		charCount.resize(256, 0);
		for (auto e : str) {
			++charCount[e];
		}
		for (size_t i = 0; i < str.size(); ++i) {
			if (charCount[str[i]] == 1)
				return i;
		}
		return -1;
	}
};

int main(){
	string s("NXWtnzyoHoBhUJaPauJaAitLWNMlkKwDYbbigdMMaYfkVPhGZcrEwp");
	Solution s1;
	std::cout << s1.FirstNotRepeatingChar(s);
}	