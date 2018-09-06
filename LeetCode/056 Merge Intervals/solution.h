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
Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return vector<Interval>();
		//std::sort(intervals.begin(), intervals.end(), comp);
		
		std::sort(intervals.begin(), intervals.end(),
			[](const Interval& lhs, const Interval& rhs)
		{return lhs.start < rhs.start; }
		);
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
	/*
	bool comp(const Interval& lhs, const Interval& rhs) {
		return lhs.start <= rhs.start;
	}*/

	/*
	    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        for (const auto &interval : intervals) {
            if (!ret.empty() && interval.start <= ret.back().end)
                ret.back().end = std::max(interval.end, ret.back().end);
            else ret.push_back(interval);
        }
        return ret;
    }
	*/
};
