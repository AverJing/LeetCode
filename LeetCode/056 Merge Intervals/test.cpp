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
#include <algorithm>
#include <functional>

using std::vector;
using namespace std::placeholders;

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	/*
	bool comp(const Interval& lhs, const Interval& rhs) {
		return lhs.start <= rhs.start;
	}*/
	struct {
		bool operator()(const Interval& lhs, const Interval& rhs) {
			return lhs.start < rhs.start;
		}
	}comp;

	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return vector<Interval>();
		//std::sort(intervals.begin(), intervals.end(), std::bind(&comp, _1, _2));
		std::sort(intervals.begin(), intervals.end(), comp);
		/*
		std::sort(intervals.begin(), intervals.end(),
			[](const Interval& lhs, const Interval& rhs)
				{return lhs.start < rhs.start; }
		);*/
		vector<Interval> result;
		result.push_back(intervals[0]);
		for (int i = 1, j = 0; i < intervals.size(); ++i) {
			if (result[j].end >= intervals[i].start && result[j].start <= intervals[i].end) {
				result[j].end = result[j].end >= intervals[i].end ? result[j].end : intervals[i].end;
				result[j].start = result[j].start <= intervals[i].start ? result[j].start : intervals[i].start;
			}
			else {
				result.push_back(intervals[i]);
				++j;
			}

		}
		return result;
	}

};
int main(){
	vector<Interval> interval{ {1,3},{2,6},{8,10} };
	Solution s;
	s.merge(interval);
}	