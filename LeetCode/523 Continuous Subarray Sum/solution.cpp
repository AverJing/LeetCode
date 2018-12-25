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
Given a list of non-negative numbers and a target integer k, write a 
function to check if the array has a continuous subarray of size at 
least 2 that sums up to the multiple of k, that is, sums up to n*k 
where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums 
up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 
5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 
32-bit integer.
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int size = nums.size();
		if (k == 0) {
			for (int i = 0; i < size - 2; ++i) {
				if (nums[i] == 0 && nums[i + 1] == 0)
					return true;
			}
			return false;
		}
		unordered_map<int, int> cache;
		int sum = 0;
		cache.insert({ 0, 0 });
		for (int i = 0; i < size; ++i) {
			sum += nums[i];
			auto iter = cache.find(sum % k);
			if (iter == cache.end()) cache.insert({ sum % k, i + 1 });
			else if(i+1- iter->second >= 2) return true;
		}
		return false;
	}
};

int main(){
	
}	