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
#include <algorithm>
#include <string>

using std::string;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.empty() || n > str.size() || n < 0) return "";
		if (n == 0 || n == str.size()) return str;

		std::reverse(str.begin(), str.end());

		std::reverse(str.begin(), str.begin() + str.size() - n);
		std::reverse(str.begin() + str.size() - n, str.end());

		return str;
	}
};

int main(){
	Solution s;
	std::cout << s.LeftRotateString("abcdefg", 3);
}	