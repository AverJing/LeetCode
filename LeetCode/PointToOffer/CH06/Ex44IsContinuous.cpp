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
#include <algorithm>

using std::vector;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty()) return false;

		std::sort(numbers.begin(), numbers.end());

		int countZero = std::count(numbers.begin(), numbers.end(), 0);

		int small = countZero;
		int big = small + 1;
		int numberGap = 0;
		while (big < numbers.size()) {
			if (numbers[small] == numbers[big])
				return false;
			else {
				numberGap += numbers[big] - numbers[small] - 1;
				if (numberGap > countZero) return false;
				++small;
				++big;
			}
		}
		return true;
	}
};

int main(){
	
}	