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
#include <vector>
#include <stack>

//占位  此题难
//

using Arr = std::vector<int>;

int getCommunications(const Arr& mount) {
	if (mount.empty() || mount.size() < 2)
		return 0;

	int maxIndex = 0;
	for (int i = 0; i < mount.size(); ++i) {
		maxIndex = mount[maxIndex] < mount[i] ? i : maxIndex;
	}

	auto getInternalSum = [](int n) {return n == 1 ? 0 : (n*(n - 1)) / 2; };
	std::stack<std::pair<int,int>> s;
	s.push({ mount[maxIndex], 1 }); //num+count
	int res = 0;
	for (int i = (maxIndex < mount.size() - 1 ? maxIndex + 1 : 0); i != maxIndex;) {
		while (!s.empty() && s.top().first < mount[i]) {
			int times = s.top().second;
			s.pop();
			res += getInternalSum(times) + times*2;
		}
		if (!s.empty() && s.top().first == mount[i]) {
			++s.top().second;
		}
		else {
			s.push({ mount[i],1 });
		}
		i = i < mount.size() - 1 ? i + 1 : 0;
	}
	while (!s.empty()) {
		int times = s.top().second;
		s.pop();
		res += getInternalSum(times);
		if (!s.empty()) {
			res += times;
			if (s.size() > 1) {
				res += times;
			}
			else {
				res += s.top().second > 1 ? times : 0;
			}
		}
	}
	return res;
}

int main(){
	std::cout << getCommunications({ 1,2,4,5,3 });
}	