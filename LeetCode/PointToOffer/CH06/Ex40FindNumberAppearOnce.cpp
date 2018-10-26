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
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.empty()) return;

		int result = 0;
		for (auto e : data) {
			result ^= e;
		}
		auto indexOf1 = FindFirstBitIs1(result);
		*num1 = *num2 = 0;

		for (auto e : data) {
			if (IsBit1(e, indexOf1))
				*num1 ^= e;
			else
				*num2 ^= e;
		}
	}
private:
	unsigned int FindFirstBitIs1(int num) {
		int indexBit = 0;
		while ((num & 0x01) == 0 && (indexBit < 8 * sizeof(int))) {
			num = num >> 1;
			++indexBit;
		}
		return indexBit;
	}
	bool IsBit1(int num, unsigned int indexBit) {
		num = num >> indexBit;
		return num & 0x01;
	}
};

int main(){
	
}	