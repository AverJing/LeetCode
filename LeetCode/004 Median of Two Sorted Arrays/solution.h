#pragma once
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).

You may assume nums1 and nums2 cannot be both empty.

Example1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> temp;
		//temp.reserve(std::max(nums1.size(), nums2.size()));
		auto beg1 = nums1.begin(), beg2 = nums2.begin();
		for (;beg1 != nums1.end() && beg2 != nums2.end();) {
			if (*beg1 < *beg2) {
				temp.push_back(*beg1++);
			}
			else {
				temp.push_back(*beg2++);
			}
		}
		for(; beg1 != nums1.end();)
			temp.push_back(*beg1++);
		for (; beg2 != nums2.end();)
			temp.push_back(*beg2++);

		return temp.size() % 2 ? temp[temp.size() / 2] : (temp[temp.size() / 2] + temp[(temp.size() - 1) / 2])/2.0;
	}
};