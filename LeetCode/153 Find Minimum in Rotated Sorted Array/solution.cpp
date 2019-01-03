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
Suppose an array sorted in ascending order is rotated at some pivot 
unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	/*
	int findMin(vector<int>& rotateArray) {
		if (rotateArray.empty()) throw new std::exception("empty array");

		int index1 = 0, index2 = rotateArray.size() - 1;
		int indexMid = index1;
		while (rotateArray[index1] >= rotateArray[index2]) {
			if (index2 - index1 == 1) {
				return rotateArray[index2];
			}

			indexMid = (index1 + index2) / 2;
			if (rotateArray[indexMid] == rotateArray[index1] &&
				rotateArray[index1] == rotateArray[index2])
				return minNumber(rotateArray);

			if (rotateArray[indexMid] >= rotateArray[index1]) {
				index1 = indexMid;
			}
			else if (rotateArray[indexMid] <= rotateArray[index2])
				index2 = indexMid;
		}
		return rotateArray[indexMid];
	}

	int minNumber(const vector<int>& rotateArray) {
		auto minNum = INT_MAX;
		for (auto e : rotateArray) {
			if (e < minNum) minNum = e;
		}
		return minNum;
	}*/

	int findMin(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;

		while (start < end) {
			int mid = start + ((end - start) >> 1);
			if (nums[mid] < nums[end]) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
		return nums[start];
	}
};

int main(){
	
	return 0;
}