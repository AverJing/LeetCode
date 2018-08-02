#pragma once
/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until 
the first non-whitespace character is found. Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical digits as possible,
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number,
or if no such sequence exists because either str is empty or it contains 
only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

1.Only the space character ' ' is considered as whitespace character.
2.Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
If the numerical value is out of the range of representable values, 
INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.

Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
Thefore INT_MIN (−231) is returned.
*/
#include <climits>
#include <string>
#include <sstream>

using std::string;
//要求是只丢弃开头的空格，这个算法是抛弃所有的空格
/*
class Solution {
public:
	int myAtoi(string str) {
		int ret = 0;  bool sym = false; int count=0;
		for (auto i = 0; i < str.size(); ++i) {
			switch (str[i]) {
			case ' ':
				break;
			case '-':
				sym = true; ++count; break;
			case '+':
				++count;  break;
			default:
				if (str[i] >= '0' && str[i] <= '9') {
					if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && (int)(str[i] - '0') > 7)) return INT_MAX;
					if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && -int(str[i] - '0') < -8 && sym)) return INT_MIN;
					ret = sym ? ret * 10 - (str[i] - '0') : ret * 10 + (str[i] - '0');
				}
				else if (ret != 0 && count < 2)
					return ret;
				else
					return 0;
				break;
			}
		}
		return count < 2 ? ret : 0;
	}
};*/

class Solution {
public:
	int myAtoi(string str) {
		int ret = 0;  int flag = 0; int count = 0;
		auto i = str.find_first_not_of(' ');
		if (str[i] == '-')
		{
			flag = 1;
			i++;
		}
		else if (str[i] == '+')
		{
			i++;
		}
		for (; i < str.size(); ++i) {
				if (str[i] >= '0' && str[i] <= '9') {
					if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && (int)(str[i] - '0') > 7)) return INT_MAX;
					if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && -int(str[i] - '0') < -8)) return INT_MIN;
					ret = flag ? ret * 10 - (str[i] - '0') : ret * 10 + (str[i] - '0');
				}
				else if (ret != 0)
					return ret;
				else
					return 0;
		}
		return ret;
	}
};