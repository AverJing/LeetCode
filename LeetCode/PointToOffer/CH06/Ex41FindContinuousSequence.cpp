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
#include <vector>

using std::vector;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum <= 0) return vector<vector<int> >();
		vector<vector<int> > result;
		unsigned int small = 1, big = 2;
		unsigned int currSum = small + big;
		for (; small < (sum + 1) / 2;) {
			if (currSum == sum) {
				vector<int> part;
				part.reserve(big - small + 1);
				for (auto tmp = small; tmp <= big; ++tmp)
					part.push_back(tmp);
				result.push_back(part);
				
				currSum -= small;
				++small;
				++big;
				currSum += big;
			}
			else if (currSum < sum) {
				++big;
				currSum += big;
			}			
			else {
				currSum -= small;
				++small;
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	for (auto& e : s.FindContinuousSequence(15)) {
		for (auto p : e)
			std::cout << p << ' ';
		std::cout << std::endl;
	}
}	