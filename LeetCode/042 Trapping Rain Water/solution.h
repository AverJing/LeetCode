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
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, 
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
#pragma once

#include <vector> 
#include <algorithm>

using std::vector;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 3) return 0;
		int count{ 0 };
		for (int i = 0, j = height.size() - 1, maxI = height[i], maxJ = height[j]; 
			i < j; maxI = std::max(maxI, height[i]), maxJ = std::max(maxJ, height[j]))
			if (maxI < maxJ) count += maxI - height[i++];
			else count += maxJ - height[j--];
		return count;
	}
};
