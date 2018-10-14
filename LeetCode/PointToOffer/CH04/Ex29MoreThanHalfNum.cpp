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
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) return 0;

		int result = numbers[0];
		int count = 1;
		for (auto e : numbers) {
			if (count == 0) {
				result = e;
				count = 1;
			}
			else if (result == e)
				++count;
			else
				--count;
		}

		if (std::count(numbers.begin(), numbers.end(), result) <= numbers.size() / 2)
			return 0;
		return result;
	}*/
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) return 0;

		auto middle = numbers.begin() + (numbers.size() >> 1);
		auto start = numbers.begin();
		auto end = numbers.end();
		auto index = std::partition(start, end,
			[&](int number) {return number < *start; });

		while (index != middle) {
			if (index > middle) {
				end = index - 1;
				index = std::partition(start, end, [&](int number) {return number < *start; });
			}
			else {
				start = index + 1;
				index = std::partition(start, end, [&](int number) {return number < *start; });
			}
		}

		int result = *middle;

		if (std::count(numbers.begin(), numbers.end(), result) <= numbers.size() / 2)
			return 0;
		return result;
	}
};

int main(){
	
}	