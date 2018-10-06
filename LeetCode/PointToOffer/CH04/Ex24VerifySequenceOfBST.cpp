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
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return false;

		int root = sequence.back();
		int i = 0;
		for (; i < sequence.size() - 1; ++i) {
			if (sequence[i] > root) break;
		}

		int j = i;
		for (; j < sequence.size() - 1; ++j) {
			if (sequence[j] < root) return false;
		}

		bool left = true;
		if (i > 0) left = VerifySquenceOfBST(
			vector<int>(sequence.begin(), sequence.begin() + i));
		bool right = true;
		if (i < sequence.size()-1) right = VerifySquenceOfBST(
			vector<int>(sequence.begin() + i, sequence.end() - 1));

		return left && right;
	}
};

int main(){
	
}	