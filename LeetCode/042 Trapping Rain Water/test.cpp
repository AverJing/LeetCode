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

int main(){
	Solution s;
	vector<int> ivec{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	s.trap(ivec);
}	