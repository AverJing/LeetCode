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
A string S of lowercase letters is given. We want to partition this 
string into as many parts as possible so that each letter appears in at 
most one part, and return a list of integers representing the size of 
these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> cache(26, -1);//保存每个字符最后出现的位置
		vector<int> res;

		for (int i = 0; i < S.size(); ++i) {
			cache[S[i] - 'a'] = i;
		}

		for (int firstIndex = 0; firstIndex < S.size();) {
			int lastIndex = firstIndex;
			for (int i = firstIndex; i < S.size() && i <= lastIndex; ++i) {
				int index = cache[S[i] - 'a'];
				if (index > lastIndex)
					lastIndex = index;
			}
			res.push_back(lastIndex - firstIndex + 1);
			firstIndex = lastIndex + 1;
		}

		return res;
	}
};

int main(){
	
	return 0;
}