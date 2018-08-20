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

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		int length = 0;
		for (auto &e : nums) {
			if (e != val)
				++length;
		}
		return length;
	}
};

int main(){
	Solution s;
	std::vector<int> ivec;
	s.removeElement(ivec, 5);
}	