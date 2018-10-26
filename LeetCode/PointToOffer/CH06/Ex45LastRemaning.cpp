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
#include <list>
#include <forward_list>

using std::list;
using std::forward_list;

class Solution {
public:
	/*
	int LastRemaining_Solution(int n, int m)
	{
		forward_list<int> number;
		auto begin_before = number.before_begin();
		for (int i = 0; i < n; ++i) {
			begin_before = number.insert_after(begin_before, i);
		}

		auto current = number.begin();
		begin_before = number.before_begin();
		while (!number.empty()) {
			for (int i = 1; i < m; ++i) {
				++current;
				++begin_before;
				if (current == number.end()) {
					current = number.begin(); 
					begin_before = number.before_begin();
				}								
			}
			++current;
				
			number.erase_after(begin_before);

			if (current == number.end()) {
				current = number.begin();
				begin_before = number.before_begin();
			}

			if (std::next(number.begin()) == number.end())
				return *current;
		}
	}
	*/
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1) return -1;
		int last = 0;
		for (int i = 2; i <= n; ++i)
			last = (last + m) % i;
		return last;
	}
};

int main(){

	Solution s;
	std::cout << s.LastRemaining_Solution(5, 2);
}	