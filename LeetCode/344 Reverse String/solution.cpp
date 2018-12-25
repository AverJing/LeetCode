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
https://leetcode-cn.com/problems/reverse-string/description/  
https://leetcode.com/problems/reverse-string/description/
编写一个函数，其作用是将输入的字符串反转过来。

示例 1:

输入: "hello"
输出: "olleh"
示例 2:

输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"
*/
#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
	string reverseString(string s) {
		//std::reverse(s.begin(), s.end());
		//return s;

		for (auto _First = s.begin(), _Last = s.end(); _First != _Last && _First != --_Last; ++_First)
		{
			//std::iter_swap(_First, _Last); //Swaps the values of the elements the given iterators are pointing to.
			std::swap(*_First, *_Last);
		}

		return s;
	}
};

int main(){
	
}	