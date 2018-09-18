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
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, 
not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#pragma once

#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using std::vector;
using std::priority_queue;

class Solution {
public:
	/*
	int findKthLargest(vector<int>& nums, int k) {
		//nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
		std::sort(nums.begin(), nums.end(), [](int a, int b) {return a > b; });
		return nums[k - 1];
	}*/
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, std::greater<int>> pq;

		for (int n : nums) {
			pq.push(n);
			if (pq.size() > k) pq.pop();
		}

		return pq.top();
	}
};
