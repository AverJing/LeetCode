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
#include <unordered_map>
#include <vector>

using Arr = std::vector<int>;
using HashMap = std::unordered_map<int, int>;

int getMaxLength(const Arr& a, int k) {
	if (a.empty()) return 0;

	HashMap cache;
	cache.insert({ 0,-1 });
	int len = 0;
	int sum = 0;
	for (int i = 0; i < a.size(); ++i) {
		sum += a[i];
		if (cache.find(sum - k)!=cache.end()) {
			auto tmp = cache[sum - k];
			len = tmp > len ? tmp : len;
		}
		if(cache.find(sum) == cache.end()) {
			cache.insert({ sum,i });
		}
	}
	return len;
}


int main(){
	std::cout << getMaxLength({ 7,3,2,1,1,7,5,3 }, 7);
}	