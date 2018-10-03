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
	/*
	void reOrderArray(vector<int> &array) {
		if (array.empty()) return;
		for (auto iter1 = array.begin(), iter2 = std::prev(array.end());
			iter1 < iter2;) {
			while(iter1 < iter2 && *iter1 & 0x01)
				++iter1;
			while(iter1 < iter2 && (*iter2 & 0x01) == 0)//注意优先级   ==优先于&
				--iter2;

			if (iter1 < iter2) {
				std::swap(*iter1, *iter2);
			}
		}
	}*/
	/*
	void reOrderArray(vector<int> &array) {
		if (array.empty()) return;
		vector<int> even;
		int count = 0;
		for (auto iter = array.begin();
			iter != array.end(); ++iter) {
			if (*iter & 0x01) {
				*(iter - count) = *iter;
			}		
			else {
				++count;
				even.push_back(*iter);
			}
		}
		auto tmp = array.begin();
		std::advance(tmp, array.size() - count);
		std::copy(even.begin(), even.end(), tmp);
	}*/

	void reOrderArray(vector<int> &array) {
		vector<int> result;
		int num = array.size();
		for (int i = 0; i < num; i++)
		{
			if (array[i] % 2 == 1)
				result.push_back(array[i]);
		}
		for (int i = 0; i < num; i++)
		{
			if (array[i] % 2 == 0)
				result.push_back(array[i]);
		}
		array = result;
		//std::swap(array, result);
	}
};

int main(){
	vector<int> result{ 1,2,3,4,5,6,7 };
	Solution s;
	s.reOrderArray(result);

	for (auto e : result)
		std::cout << e << ' ';
}	