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

using std::vector;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.empty()) return vector<int>();

		vector<int> v;
		for (size_t j = array.size() - 1, i = 0; i < j; ) {
			if (array[i] + array[j] == sum) {
				v.push_back(array[i]);
				v.push_back(array[j]);
				break;
			}
			else if (array[i] + array[j] < sum) {
				++i;
			}
			else
				--j;
		}
		return v;
	}
};

int main(){
	vector<int> ivec{ 1,2,3,4,5,6,7 };
	Solution s;
	s.FindNumbersWithSum(ivec, 7);
}	