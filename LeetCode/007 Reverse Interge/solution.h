#pragma once
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <string>
#include <climits>

using std::string;

//性能太差，应该直接进行处理
/*
class Solution {
public:
int reverse(int x) {
string s = std::to_string(x);
string int_max = std::to_string(INT_MAX);
string result;
if (s[0] == '-') {
for (auto rbeg = s.rbegin(); rbeg != s.rend() - 1; ++rbeg) {
result += *rbeg;
}
return -(result.size() == int_max.size() && result > int_max ? 0 : stoi(result)) ;
}
else {
for (auto rbeg = s.rbegin(); rbeg != s.rend(); ++rbeg) {
result += *rbeg;
}
return (result.size() == int_max.size() && result > int_max ? 0 : stoi(result));
}
}
};
*/
/*
#include <climits>

class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};*/

#include <string>
#include <sstream>

using std::string;

class Solution {
public:
	int reverse(int x) {
		bool isNeg;
		(x < 0) ? isNeg = true : isNeg = false;
		string s = std::to_string(x);
		std::cout << s << std::endl;
		int j = s.size() - 1;
		int i = 0;
		while (i < j)
		{
			if (isNeg)
			{
				//        std::cout << "HERE" <<  std::endl;
				i++;
				//      j--;
				isNeg = false;
				//          continue;
			}
			else
			{
				//          std::cout << i << " " << j << std::endl;
				std::swap(s[i], s[j]);
				i++;
				j--;
			}
		}
		int num;
		std::stringstream ss(s);
		ss >> num;
		if (num >= INT_MAX || num <= INT_MIN)
			return 0;
		//       int num = std::stoi(s);
		return num;
	}
};



//https://leetcode.com/articles/reverse-integer/