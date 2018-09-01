
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
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		auto beg = std::unique(nums.begin(), nums.end());
		nums.erase(beg, nums.end());
		int result = 1;
		for (auto i = 0; i < nums.size(); ) {
			if (nums.at(i) <= 0) ++i;
			else if (nums.at(i) == result)  ++i, ++result;
			else return result;
		}
		return result;
	}
	//better answer
	/*
	int firstMissingPositive(int A[], int n) {
        for (int i=0; i<n; ++i)
            while (A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
                swap(A[i], A[A[i]-1]);
        for (int i=0; i<n; ++i)
            if (A[i] != i+1) return i+1;
        return n+1;
    }
	*/
};
