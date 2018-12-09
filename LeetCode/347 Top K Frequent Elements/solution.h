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
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), 
where n is the array's size.
*/
#pragma once

#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> frequence;

		for (auto e : nums) {
			++frequence[e];
		}

		vector<int> ret;
		//有些提交的答案 用的是nth_element算法
		priority_queue<pair<int, int>> count;
		for (auto& e : frequence) {
			count.push(std::make_pair(e.second, e.first));
			if (count.size() > frequence.size() - k) {
				ret.push_back(count.top().second);
				count.pop();
			}
		}
		return ret;
	}
};