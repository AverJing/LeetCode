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
#include <regex>

using std::string;

class Solution {
public:
	/*
	bool isNumeric(const char* string)
	{
		if (!string) return false;
		if (*string == '\0') return false;

		if ((string[0] == '-' || string[0] == '+')) {
			if (*(string+1) == '\0') return false;
			++string;
		}
		int dot = 0, num = 0, eCount = 0;
		while (*string != '\0') {
			if (isNumberChar(*string)) {
				++string;
				++num;
			}
			else if (*string == '.') {
				//-.123  也算数字。。。 去掉  num == 0
				if (dot > 0 || eCount > 0)
					return false;
				++string;
				++dot;
			}
			else if (*string == 'e' || *string == 'E') {
				if (num == 0 || eCount > 0)
					return false;
				++eCount;
				++string;
				if (*string == '-' || *string == '+')
					++string;
				if (*string == '\0')
					return false;
			}
			else return false;
		}
		return true;
	}*/
	//使用正则表达式求解
	//简洁，但是慢
	bool isNumeric(const char* s)
	{
		string pattern("[\\+-]?[0-9]*(\\.[0-9]*)?([eE][\\+-]?[0-9]+)?");
		std::regex r(pattern);
		return std::regex_match(s, r);
	}
private:
	bool isNumberChar(char c) {
		return c >= '0' && c <= '9';
	}
};

int main(){
	Solution s;
	std::cout << s.isNumeric("123.45e+6");
}	