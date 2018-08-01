#pragma once
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

*/
#include <string>
#include <vector>
#include <numeric>

using std::string;
using std::vector;

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.empty() || numRows < 2) return s;
		vector<string> result(numRows);
		for (auto i = 0; i < s.size(); ++i) {
			int m = i % (numRows - 1), n = i / (numRows - 1);
			(n & 0x1 ? result[numRows - m - 1] : result[m]) += s[i];
		}
		return std::accumulate(result.cbegin(), result.cend(), string());
	}
};