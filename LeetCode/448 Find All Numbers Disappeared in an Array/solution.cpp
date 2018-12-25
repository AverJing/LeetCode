/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this 
array.

Could you do it without extra space and in O(n) runtime? You may assume 
the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	//我通过交换下标，将每个位置都放好，-1的位置自然是缺的
	/*
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		if (nums.empty()) return {};

		for (int i = 0; i < nums.size(); ++i) {
			while (nums[i]!=-1 && nums[nums[i] - 1]!= nums[i]) {
				std::swap(nums[nums[i] - 1], nums[i]);
			}
			if (i!=nums[i]-1) { nums[i] = -1; }
		}

		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == -1) res.push_back(i + 1);

		return res;
	}*/
	//比我的优雅很多。
	//只标记第一次出现的。
	vector<int> findDisappearedNumbers(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++) {
			int m = abs(nums[i]) - 1;
			nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
		}


		vector<int> vec;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)
				vec.push_back(i + 1);
		}
		return vec;
	}
};

int main(){
	
}	