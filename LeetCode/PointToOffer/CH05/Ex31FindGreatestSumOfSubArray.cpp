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
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty()) return;
		int sum = 0, maxNumber = INT_MIN;
		for (auto e : array) {
			sum += e;
			if (e > sum)
				sum = e;
			if (sum > maxNumber)
				maxNumber = sum;
		}
		return maxNumber;
	}
};

int main(){
	
}	