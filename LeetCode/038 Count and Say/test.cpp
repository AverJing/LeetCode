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
	string countAndSay(int n) {
		string result;
		int count = 1;
		string temp = "1";
		for (auto i = 1, j = 0; i < n; ++j) {
			if (j == temp.size()) j = 0, ++i, temp = result, result.clear();
			if (j + 1 < temp.size()) {
				if (temp[j] == temp[j + 1]) {
					++count;
					//++j;
				}
				else {
					result += std::to_string(count) + temp[j];
					count = 1;
				}
			}
			else {
				result += std::to_string(count) + temp[j];
				count = 1;
			}
		}
		return temp;
	}
};

int main(){
	Solution s;
	s.countAndSay(4);
	
}	