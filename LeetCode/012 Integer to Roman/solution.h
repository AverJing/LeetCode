/*
*
*
*@author: Aver Jing
*@description：As followed.
*@date：Aug 6, 2018
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
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"

Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#pragma once

#include <string>
#include <map>

using std::string;
using std::map;

/* wrong anwser,because I am not familiar with the return value of euqal_range, lower_bound
and upper_bound(especially in not-found return value).
Also, not able to translate the mind into code efficiently. Use to much if..else..if..
class Solution {
public:
	string intToRoman(int num) {
		if (!(num > 0 && num < 4000))
			return "";
		map<int, string> key{ {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"} };
		map<int, char> value{ { 1, 'I' },{ 5, 'V' },{ 10, 'X' },{ 50, 'L' },{ 100, 'C' },{ 500, 'D' },{ 1000, 'M' } };
		string result;
		int base = 1000; int p = 0;
		while (true){
			 if(!p) p = num / base * base, num = num-p, base /= 10;
			auto ret = value.equal_range(p);
			if (ret.first == ret.second) { base /= 10; continue; }
			if (ret.second == value.end() )
				result += string(p / 1000, value.find(1000)->second), p = p - p / ret.first->first * ret.first->first;
			else {
				if (key.find(p) != key.end()) result += key.find(p)->second, p = p - key.find(p)->first;
				else {
					result += string(p / ret.first->first, ret.first->second);
					p = p - p / ret.first->first * ret.first->first;
				}
			}
			if (!num) break;
		} 
		return result;
	}
};*/

class Solution {
public:
	string intToRoman(int num) {
		map<int, string> value{ { 1, "I" },{ 5, "V" },{ 10, "X" },{ 50, "L" },{ 100, "C" },{ 500, "D" },{ 1000, "M" },
					{ 4, "IV" },{ 9, "IX" },{ 40, "XL" },{ 90, "XC" },{ 400, "CD" },{ 900, "CM" } };
		string result;
		for (auto cbeg = value.crbegin(); cbeg != value.crend(); ++cbeg) {
			while (num >= cbeg->first) {
				result += cbeg->second;
				num -= cbeg->first;
			}
		}
		return result;
	}
};