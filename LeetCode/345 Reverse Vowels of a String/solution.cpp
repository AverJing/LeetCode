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
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/
#include <iostream>
#include <string>
#include <cctype>

using std::string;

class Solution {
public:
	string reverseVowels(string s) {
		for (int i = 0, j = s.size() - 1; i < j;) {
			bool sym1 = isVowel(std::tolower(s[i])), sym2 = isVowel(std::tolower(s[j]));
			if (sym1&&sym2) std::swap(s[i++], s[j--]);
			else if (sym1) --j;
			else if (sym2) ++i;
			else ++i, --j;
		}
		return s;
	}
	bool isVowel(char ch) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
		return false;
	}
};

int main(){
	
	return 0;
}