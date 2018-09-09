/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/* bad answer
	void sortColors(vector<int>& nums) {
		vector<int> result;
		int count0 = 0, count1 = 0, count2 = 0;
		for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
			if (*iter == 0) ++count0;
			else if (*iter == 1) ++count1;
			else if (*iter == 2) ++count2;
		}
		for (auto i = 0; i < count0 + count1 + count2; ++i) {
			if (i < count0) result.push_back(0);
			else if (i < count0 + count1) result.push_back(1);
			else result.push_back(2);

		}
		nums = result;
	}*/
	void sortColors( vector<int>& nums) {
		if (nums.size() < 2) return;
		//order of variable initialization in for(beg, end) is not from left to right. random.
		for (auto beg = nums.begin(), end = std::next(nums.begin()); beg != nums.end();) {
			if (*beg > *end) {
				std::swap(*beg, *end);
			}
			++end;
			if (end == nums.end()) {
				++beg;
				if (beg == std::prev(nums.end())) break;
				else {
					end = std::next(beg);
				}
			}
		}
	}
};

int main(){
	Solution s;
	vector<int> ivec{ 2,0,2,1,1,0 };
	s.sortColors(ivec);
}	