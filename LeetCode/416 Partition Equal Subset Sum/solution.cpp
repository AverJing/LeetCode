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
Given a non-empty array containing only positive integers, 
find if the array can be partitioned into two subsets such 
that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>

using std::vector;
using std::bitset;

class Solution {
public:
	bool canPartition(const vector<int>& nums) {
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		int target = sum >> 1;
		if (sum & 0x1) return false;
		vector<bool> res(target + 1, false);
		res[0] = true;
		for (auto e : nums) {
			for (int i = target; i >= e; --i) {
				res[i] = res[i] || res[i - e];
			}
		}
		return res[target];
	}

	//https://www.cnblogs.com/grandyang/p/5951422.html
	bool canPartition(vector<int>& nums) {
		bitset<5001> bits(1);
		int sum = accumulate(nums.begin(), nums.end(), 0);
		for (int num : nums) bits |= bits << num;
		return (sum % 2 == 0) && bits[sum >> 1];
	}
};

int main(){
	Solution s;
	std::cout << s.canPartition({ 3,3,3,4,5 });
}	