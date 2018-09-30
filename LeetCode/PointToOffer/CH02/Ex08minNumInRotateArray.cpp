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
	int minNumber(const vector<int>& rotateArray) {
		auto minNum = INT_MAX;
		for (auto e : rotateArray) {
			if (e < minNum) minNum = e;
		}
		return minNum;
	}
	int minNumberInRotateArray(const vector<int>& rotateArray) {
		if (rotateArray.empty()) throw new std::exception("empty array");

		int index1 = 0, index2 = rotateArray.size() - 1;
		int indexMid = index1;
		while (rotateArray[index1] >= rotateArray[index2]) {
			if (index2 - index1 == 1) {
				return rotateArray[index2];
			}

			indexMid = (index1 + index2) / 2;
			if (rotateArray[indexMid] == rotateArray[index1] &&
				rotateArray[index1] == rotateArray[index2])
				return minNumber(rotateArray);

			if (rotateArray[indexMid] >= rotateArray[index1]) {
				index1 = indexMid;
			}
			else if (rotateArray[indexMid] <= rotateArray[index2])
				index2 = indexMid;
		}
		return rotateArray[indexMid];
	}
};

int main(){
	
}	