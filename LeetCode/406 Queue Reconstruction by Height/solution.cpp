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
Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people 
in front of this person who have a height greater than or equal to h. 
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <queue>

using std::vector;
using std::pair;
using std::set;
using std::priority_queue;

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		auto compare = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second); };
		auto compareForSet = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {return lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second); };
		//注意set和priority_queue比较符不一样
		//set<pair<int, int>, decltype(compare)>  one(compare);
		priority_queue<pair<int, int>, std::vector<pair<int, int>>, decltype(compare)> two(compare);
		//关键在如何排序
		for (auto& e : people) {
			//one.insert(e);
			two.push(e);
		}

		vector<pair<int, int>> res;
		/*while (!one.empty()) {
			res.insert(res.begin() + one.begin()->second, *one.begin());
			one.erase(one.begin());
		}*/
		while (!two.empty()) {
			res.insert(res.begin() + two.top().second, two.top());
			two.pop();
		}

		return res;
	}
};

int main(){//std::function<bool (const pair<int, int>& lhs, const pair<int, int>& rhs)
	/*auto compare = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {return lhs.second < rhs.second; };
	set<pair<int, int>, decltype(compare) > one(compare);

	one.insert(std::make_pair(1, 2));
	one.insert(std::make_pair(21, 3));
	one.insert(std::make_pair(5, 4));

	for (auto e : one)
		std::cout << e.second << ' ';*/

	vector<pair<int, int>> people{ {7,0}, { 5,0 }, { 7,1 } };
	Solution s;
	s.reconstructQueue(people);
}	