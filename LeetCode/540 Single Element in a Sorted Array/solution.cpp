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
Given a sorted array consisting of only integers where every element 
appears twice except for one element which appears once. Find this 
single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
*/
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	/*
	int singleNonDuplicate(vector<int>& nums) {
		int result = 0;
		for (auto e : nums)
			result ^= e;

		return result;
	}*/
	//对二分搜索的修改
	//根据数组中肯定存在一个只出现一次而其他数字出现两次的特征，修改
	/*
	int singleNonDuplicate(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;
		while (start < end) {
			int mid = start + ((end - start) >> 1);			
			//if (mid % 2) {
			//	if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
			//		start = mid + 1;//特别点
			//	else
			//		end = mid - 1;
			//}
			//else {
			//	if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
			//		end = mid - 2;//特别点，越过两个相等的
			//	else
			//		start = mid + 1;
			//}
			//将上边代码的冗余整合
			if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
				end = mid % 2 ? end : mid - 2;//特别点，越过两个相等的
				start = mid % 2 ? mid + 1 : start;
			}				
			else {
				start = mid % 2 ? start : mid + 1;
				end = mid % 2 ? mid - 1 : end;
			}		
		}

		return nums[end];
	}*/
	//更简练
	int singleNonDuplicate(vector<int>& nums) {
		int l = 0, h = nums.size() - 1;
		while (l < h) {
			int m = l + (h - l) / 2;
			if (m % 2 == 1) {
				m--;   // 保证 l/h/m 都在偶数位，使得查找区间大小一直都是奇数
			}
			if (nums[m] == nums[m + 1]) {
				l = m + 2;
			}
			else {
				h = m;
			}
		}
		return nums[l];
	}
};

int main(){
	
	return 0;
}