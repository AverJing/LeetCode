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
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		int result = nums[0], index = 0;;
		for (auto i = 1; i < nums.size(); ++i) {
			int temp = result;
			for (auto j = index+1; j <= i; ++j) {
				temp += nums[j];
				if (result < temp && temp > nums[j]) result = temp, index = j;
				else if (result < nums[j]) result = nums[j], index = j; 
				else;
			}
		}
		return result;
	}
};
int main(){
	vector<int> ivec{ -2,1,-3,4,-1,2,1,-5,4 };
	Solution s;
	s.maxSubArray(ivec);
}	