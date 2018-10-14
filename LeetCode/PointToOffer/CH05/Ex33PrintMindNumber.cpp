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
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Comp
{
public:
	bool operator()(string& lhs, string& rhs) {
		return lhs + rhs < rhs + lhs;		
	}
};

class Solution {
public:
	string PrintMinNumber(vector<int>& numbers) {
		if (numbers.empty()) return "";
		vector<string> strNumber;
		for (auto e : numbers)
			strNumber.push_back(std::to_string(e));

		std::sort(strNumber.begin(), strNumber.end(), Comp());

		string result;
		for (auto& e : strNumber)
			result += e;

		return result;
	}
};

int main(){
	vector<int> ivec{ 3,32,321 };
	Solution s;
	std::cout << s.PrintMinNumber(ivec);
}	