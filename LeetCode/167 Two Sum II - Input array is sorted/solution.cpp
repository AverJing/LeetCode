/*
*
*
*@author: Aver Jing
*@description£º
*@date£º
*
*
*/
/*
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you 
may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
	/*¸ü¿ì
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> cache;
		cache.insert({ target - numbers[0], 0 });
		for (int i = 1; i < numbers.size(); ++i) {
			auto res = cache.find(numbers[i]);
			if (res != cache.end()) {
				return { res->second + 1,i + 1 };
			}
			else {
				cache.insert({ target - numbers[i],i });
			}
		}
	}*/
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (int i = 0, j = numbers.size() - 1; i < j;) {
			int sum = numbers[i] + numbers[j];
			if (sum == target)
				return { i + 1,j + 1 };
			else if (sum < target)
				++i;
			else
				--j;
		}
	}
};

int main() {
	
	return 0;
}
