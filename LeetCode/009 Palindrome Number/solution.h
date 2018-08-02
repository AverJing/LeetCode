#pragma once
/*
Determine whether an integer is a palindrome. 
An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. 
Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:

Coud you solve it without converting the integer to a string?
*/

/*
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int v = 0;
		do {
			int p = x % 10;
			v = v * 10 + p;
		} while (x /= 10);
		if (v == x) return true;
	}
};*/

//not concise
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int v = 0;
		do {
			v = v * 10 + x % 10;
		} while (x /= 10);
		return x==v;
	}
};