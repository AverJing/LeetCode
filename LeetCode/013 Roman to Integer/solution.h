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
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
	Symbol       Value
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, 
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:
	I can be placed before V (5) and X (10) to make 4 and 9. 
	X can be placed before L (50) and C (100) to make 40 and 90. 
	C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3

Example 2:

Input: "IV"
Output: 4

Example 3:

Input: "IX"
Output: 9

Example 4:

Input: "LVIII"
Output: 58
Explanation: C = 100, L = 50, XXX = 30 and III = 3.

Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#pragma once
#include <string>
#include <map>

using std::string;
using std::map;

/*
class Solution {
public:
	int romanToInt(string s) {
		map<string, int> key{ { "IV", 4 },{ "IX",9 },{ "XL", 40 },{ "XC", 90 },{ "CD", 400, },{ "CM", 900 } };
		map<char, int> value{ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
		int result = 0; string::size_type i = 0;
		for (; i < s.size()-1; ++i) {
			string temp;
			if (i + 1 < s.size()) {
				//string substr (size_t pos = 0, size_t len = npos) const;
				temp = s.substr(i, 2);
				if (key.find(temp) != key.end())
				{
					result += key.find(temp)->second; ++i;
				}
				else
					result += value.find(s[i])->second;
			}
		}
		if (i == s.size()-1)
			result += value.find(s[i])->second;
		return result;
	}
};*/

/*
Question:
	string s = "A";
	string p = "ABCD";
	how to compare p[0] and s?

*/

class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
			switch (*iter)
			{
			case 'I': res += res >= 5 ? -1 : 1; break;
			case 'V': res += 5; break;
			case 'X': res += 10 * (res >= 50 ? -1 : 1); break;
			case 'L': res += 50; break;
			case 'C': res += 100 * (res >= 500 ? -1 : 1); break;
			case 'D': res += 500; break;
			case 'M': res += 1000; break;
			}
		return res;
	}
};
