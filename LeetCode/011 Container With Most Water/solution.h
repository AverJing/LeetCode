/*
*
*
*@author: Aver Jing
*@description：
*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
*n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
*Find two lines, which together with x-axis forms a container, 
*such that the container contains the most water.
*	Note: You may not slant the container and n is at least 2.
*@date：Aug 5, 2018
*
*
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ret = 0;
		for (auto beg = height.cbegin(), end = prev(height.cend()); beg < end; *beg < *end ? ++beg : --end) {
			ret = max(ret, static_cast<int>(end - beg) * min(*beg, *end));
		}
		return ret;
	}
};
