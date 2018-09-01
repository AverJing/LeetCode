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
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
#pragma once

#include <string>

using std::string;

class Solution {
public:
	string countAndSay(int n) {
		string result;
		int count = 1;
		string temp = "1";
		for (auto i = 1, j = 0; i < n; ++j) {
			if (j == temp.size()) j = 0, ++i, temp = result, result.clear();
			if (j + 1 < temp.size()) {
				if (temp[j] == temp[j + 1]) {
					++count;
					//++j;
				}
				else {
					result += std::to_string(count) + temp[j];
					count = 1;
				}
			}
			else {
				result += std::to_string(count) + temp[j];
				count = 1;
			}
		}
		return temp;
	}
};
