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
Suppose you have a long flowerbed in which some of the plots are planted
and some are not. However, flowers cannot be planted in adjacent plots 
- they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 
means empty and 1 means not empty), and a number n, return if n new 
flowers can be planted in it without violating the no-adjacent-flowers 
rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
*/
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		if (flowerbed.empty()) return false;
		if (n == 0) return true;
		for (int i = 0; i < flowerbed.size(); ++i) {
			if (flowerbed[i]) continue;
			int pre = i == 0 ? 0 : flowerbed[i - 1];
			int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
			if (pre == 0 && next == 0) {
				--n;
				if (n == 0) return true;
				flowerbed[i] = 1;
			}
		}
		return false;
	}
	/*
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int sz = flowerbed.size();

		for (int i = 0; i < flowerbed.size() && n > 0; i++) {
			int x = i - 1;
			int y = i + 1;

			if (flowerbed[i] == 0 &&
				(x < 0 || flowerbed[x] == 0) &&
				(y == sz || flowerbed[y] == 0)) {
				flowerbed[i] = 1;
				n--;
			}
		}

		return n == 0;
	}*/
};

int main(){
	
	return 0;
}