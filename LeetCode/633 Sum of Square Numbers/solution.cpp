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
Given a non-negative integer c, your task is to decide whether there're 
two integers a and b such that a^2 + b^2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
*/
#include <iostream>

class Solution {
public:
	bool judgeSquareSum(int c) {
		if (c < 3) return true;
		for (int i = 0, j = std::sqrt(c); i <= j;) {
			int sum = i * i + j * j;
			if (sum == c) return true;
			else if (sum < c)++i;
			else --j;
		}
		return false;
	}

	/*更简洁
	bool judgeSquareSum(int c) {
        int b=sqrt(c);
        for(int i=0;i<=b;i++)
        {
            int d=(int)sqrt(c - i*i);
            if(i*i + d*d==c ) return true;
        }
        
        return false;
    }
	*/
};

int main(){
	
	return 0;
}