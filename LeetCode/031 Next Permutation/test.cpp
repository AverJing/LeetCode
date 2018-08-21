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
	/*
	void nextPermutation(vector<int>& nums) {
		std::next_permutation(nums.begin(), nums.end());
	}*/

	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		auto start = std::prev(nums.end());
		for (;;) {
			auto last = start--;
			if (*start < *last) {
				auto riter = nums.end();
				while (!(*start < *--riter));
				std::iter_swap(start, riter);
				std::reverse(last, nums.end());
				return;
			}
			if (start == nums.begin()) {
				std::reverse(nums.begin(), nums.end());
				return;
			}
		}
	}
};

int main(){
	Solution s;
	vector<int> ivec{ 1,2,4,3 };
	s.nextPermutation(ivec);
	for (auto &e : ivec)
		std::cout << e << ' '; 
}	