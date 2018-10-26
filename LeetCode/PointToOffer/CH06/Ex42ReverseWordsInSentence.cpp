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
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.empty()) return "";

		std::reverse(str.begin(), str.end());

		size_t start = 0;
		for (; ;) {
			size_t i = str.find_first_of(' ', start);
			if (i == string::npos) {
				std::reverse(str.begin() + start, str.end());
				break;
			}			
			else {
				std::reverse(str.begin() + start, str.begin() + i);
				start = i + 1;
			}
		}
		/*
		size_t start = 0;
		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] == ' ') {
				std::reverse(str.begin() + start, str.begin() + i);
				start = i+1;
			}
			if (i == str.size() - 1)
				std::reverse(str.begin() + start, str.end());
		}
		*/

		return str;
	}
};

int main(){
	Solution s;
	std::cout << s.ReverseSentence("hello world! hhhh lll ");
}	