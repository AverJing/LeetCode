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
https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers and an integer k, you need to find the total 
number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of 
the integer k is [-1e7, 1e7].
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
	/*
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, vector<int>> cache;
		int sum = 0;
		int res = 0;
		cache.insert({ 0,{-1} });
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			auto tmp = cache.find(sum - k);
			if (tmp != cache.end()) {
				res += tmp->second.size();
			}
			cache[sum].push_back(i);
		}
		return res;
	}*/
	//opimization
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> cache;
		int sum = 0;
		int res = 0;
		cache.insert({ 0, 1 });
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			res += cache[sum - k];
			++cache[sum];
		}
		return res;
	}
};

int main(){
	
}	