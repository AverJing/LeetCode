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
No 128

Given an unsorted array of integers, find the length of 
the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int max{0};
		unordered_map<int, int> map;
		for (auto e : nums) {
			if (!map[e]) {
				map[e] = map[e - 1] + map[e + 1] + 1;
				//core code
				map[e - map[e-1]] = map[e + map[e+1]] = map[e];
				max = std::max(max, map[e]);
			}
		}
		return max;
	}
};
