/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>

class Solution {
public:
	/*
	float mySqrt(int x) {
		if (x == 0) return 0;
		float t = x/2;
		for (; std::abs(t * t - x) > 0.00000001;) {
			//t = t - ((t * t - x) / (2 * t));
			//化简
			t = (t + x / t) / 2.0;
		}
		return t;
	}*/
	/*
	float mySqrt(int x) {
		if (x == 0) return 0;
		long t = x ;
		for (; t * t > x;) {
			//t = t - ((t * t - x) / (2 * t));
			//化简
			t = (t + x / t) / 2;
		}
		return t;
	}*/
	
	int mySqrt(int x) {
		if (x == 1 || x == 0) {
			return x;
		}
		int start = 1;
		int end = x;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			int sqrt = x / mid;
			if (sqrt == mid) {
				return mid;
			}
			else if (sqrt > mid) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		return end;
	}
};

int main(){
	Solution s;
	std::cout << s.mySqrt(2147395599);

	return 0;
}