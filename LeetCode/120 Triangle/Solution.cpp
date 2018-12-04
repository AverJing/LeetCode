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
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
	 [2],
	[3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 
(i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;

		vector<int> dp(triangle[triangle.size() - 1]);

		for (int i = triangle.size() - 2; i >= 0; --i) {
			for (int j = 0; j < triangle[i].size(); ++j) {
				dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
			}
		}

		return dp[0];
	}
};

int main(){
	
}	