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
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty()) return vector<string>();
		vector<string> result;
		std::sort(str.begin(), str.end());

		do {
			result.push_back(str);
		} while (std::next_permutation(str.begin(), str.end()));

		return result;
	}
};

int main(){
	
}	