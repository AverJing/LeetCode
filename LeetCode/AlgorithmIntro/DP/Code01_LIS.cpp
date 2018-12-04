/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>

#include <vector>
#include <algorithm>
#include <set>

using std::vector;
using std::set;

//O(n^2)
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())	return 0;
		vector<int> result({ nums[0] });
		for (auto e : nums) {
			if (e > result.back()) {
				result.push_back(e);
			}
			else {
				auto it = std::lower_bound(result.begin(), result.end(), e);
				*it = e;
			}
		}
		return result.size();
	}

	/*
	int lengthOfLIS(vector<int>& nums) {
	if (nums.empty())	return 0;
	set<int> result({ nums[0] });
	for (auto e : nums) {
		if (e > *result.rbegin()) {
			result.insert(e);
		}
		else {
			//注意不能直接对set的值进行修改。
			result.erase(result.lower_bound(e));
			result.insert(e);
		}
	}
	return result.size();
}
	*/
};


int main(){
	
}	