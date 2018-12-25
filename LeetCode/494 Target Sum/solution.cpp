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
You are given a list of non-negative integers, a1, a2, ..., an, 
and a target, S. Now you have 2 symbols + and -. For each integer, 
you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal 
to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	//常规DP
	//[1,1,1,1,1]
	//3
	//这种情况，就是杨辉三角，其他类比。
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;

		for (auto e : nums) {
			sum += e;
		}

		if (S > sum || S < -sum)return 0;

		vector<int> res(2* sum + 1, 0);
		res[sum] = 1;//注意真实的下标是0   [-sum, sum]
		for (int i = 0; i < nums.size(); ++i) {
			vector<int> tmp(2 * sum + 1, 0);
			for (int k = 0; k < 2 * sum + 1; ++k) {
				if (res[k]) {
					tmp[k + nums[i]] += res[k];
					tmp[k - nums[i]] += res[k];
				}
			}
			res = tmp;
		}
		return res[sum + S];
	}
	//这个解法。。
	/*结合416来理解   
	int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = { 0 };
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
	*/
};

int main(){
	
}	