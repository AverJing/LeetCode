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

using std::string;

class Solution {
public:
	/*
	int StrToInt(string str) {
		if (str.empty()) return 0;
		long long int result = std::stoi(str);
		if (result >= INT_MAX || result < INT_MIN) return 0;
		return result;
	}*/

	int StrToInt(string str) {
		if (str.empty()) return 0;
		
		bool minus = false;
		auto begin = str.begin();
		if (str[0] == '-') {
			minus = true;
			++begin;
		}
		if (str[0] == '+') {
			minus = false;
			++begin;
		}
		
		long long int result = 0;
		for (; begin != str.end(); ++begin) {
			if (*begin >= '0' && *begin <= '9')
				result = result * 10 + (*begin - '0');
			/*
			else if (e == '.') break;
			else {
				continue;
			}*/
			//和实际stoi实现有差别，牛客网的测试用例
			else {
				return 0;
			}
		}

		if (minus) result *= -1;
		if (result >= INT_MAX || result <= INT_MIN) return 0;
		return result;
	}
};

int main(){
	Solution s;
	std::cout << s.StrToInt("-1sab56.5");
}	