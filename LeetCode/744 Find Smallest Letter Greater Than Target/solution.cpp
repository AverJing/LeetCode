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
Given a list of sorted characters letters containing only lowercase letters, 
and given a target letter target, find the smallest element in the list
that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and
letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique 
letters.
target is a lowercase letter.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	char nextGreatestLetter(const vector<char>& letters, char target) {
		int start = 0, end = letters.size() - 1;	
		char result =  '\0';
		while (start <= end) {
			int mid = start + ((end - start) >> 1);
			int cmp = letters[mid] - target;
			if ( cmp > 0) {
				if (result - target <= 0 || result - target > cmp) {
					result = letters[mid];
				}
				end = mid - 1;
			}
			else
				start = mid + 1;
		}
		return result == '\0' ? letters[0] : result;
	}*/

	char nextGreatestLetter(const vector<char>& letters, char target) {
		int start = 0, end = letters.size() - 1;
		while (start <= end) {
			int mid = start + ((end - start) >> 1);
			if (letters[mid] > target) {
				end = mid - 1;
			}
			else
				start = mid + 1;
		}
		return start < letters.size() ? letters[start] : letters[0];
	}

	/*
	char nextGreatestLetter(const vector<char>& letters, char target) {
		auto iter = std::upper_bound(letters.begin(), letters.end(), target);
		if (iter - letters.begin() < letters.size()) {
			return letters[iter - letters.begin()];
		}
		else {
			return letters[0];
		}
	}*/
};

int main(){
	Solution s;
	std::cout << s.nextGreatestLetter({ 'c','f','j' }, 'g');

	return 0;
}