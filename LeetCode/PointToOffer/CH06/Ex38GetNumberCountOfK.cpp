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
	int GetNumberOfK(vector<int>& data, int k) {
		if (data.empty()) return 0;

		int first = GetFirstKey(data, k, 0, data.size() - 1);
		int end = GetLastKey(data, k, 0, data.size() - 1);

		if (first > -1 && end > -1)
			return end - first + 1;

		return 0;
	}
private:
	int GetFirstKey(vector<int>& data, int k, int start, int end) {
		if (start > end) return -1;

		int middle = (start + end) / 2;

		if (data[middle] == k) {
			if (middle > 0 && data[middle - 1] != k || middle == 0)  return middle;
			else
				end = middle - 1;
		}
		else if (data[middle] > k) {
			end = middle - 1;
		}
		else
			start = middle + 1;

		return GetFirstKey(data, k, start, end);

	}
	int GetLastKey(vector<int>& data, int k, int start, int end) {
		if (start > end) return -1;

		int middle = (start + end) / 2;

		if (data[middle] == k) {
			if (middle < data.size()-1 && data[middle + 1] != k || middle == data.size() - 1)  return middle;
			else
				start = middle + 1;
		}
		else if (data[middle] > k) {
			end = middle - 1;
		}
		else
			start = middle + 1;

		return GetLastKey(data, k, start, end);
	}
};

int main(){
	vector<int> ivec{ 1,2,3,4,4,4,4,4,5,6,7 };
	Solution s;
	std::cout << s.GetNumberOfK(ivec, 4);
}	