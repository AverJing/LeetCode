/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include "../../Level0/CH01/TestCase.h"

#include <iostream>
#include <vector>

using Arr = std::vector<int>;

struct BFPRT {
	int getMedian(Arr& data, int start, int end) {
		insertSort(data);
		return data[(end + start + 1) >> 1];
	}

	Arr& insertSort(Arr& data) {
		if (data.empty()||data.size()<1) return data;

		for (int i = 1; i < data.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (data[j + 1] < data[j])
					std::swap(data[j + 1], data[j]);
				else
					break;
			}
		}
	}

	std::pair<int, int> partition(Arr& data, int begin, int end, int k) {
		int less = begin - 1;
		int more = end + 1;

		for (int i = begin; i < more; ++i) {
			if (data[i] < k) {
				std::swap(data[++less], data[i]);
			}
			else if (data[i] > k) {
				std::swap(data[--more], data[i]);
			}
			else {
				++i;
			}
		}

		return { less + 1, more - 1 };
	}

	int medianOfMedians(Arr& data, int begin, int end) {
		if (begin == end) return data[begin];
		int offset = (end - begin + 1) % 5 == 0 ? 0 : 1;
		Arr mid((end - begin + 1) / 5 + offset, 0);

		for (int i = 0; i < mid.size(); ++i) {
			int beginI = begin + i * 5;
			int endI = beginI + 4;
			mid[i] = getMedian(data, beginI, std::min(end, endI));
		}
		return medianOfMedians(mid, 0, mid.size()-1);
	}

	int select(Arr& data, int begin, int end, int k) {
		if (begin == end) return data[begin];

		auto pivotValue = medianOfMedians(data, begin, end);
		auto pivot = partition(data, begin, end, pivotValue);

		if (k >= pivot.first && k <= pivot.second){
			return data[k];
		}
		else if (k < pivot.first) {
			return select(data, begin, pivot.first - 1, k);
		}
		else {
			return select(data, pivot.second + 1, end, k);
		}
	}


	Arr getMinKNumsByBFPRT(Arr& data, int k) {
		if (k < 1 || k >data.size()) return data;

		auto copy(data);
		int minKth = select(copy, 0, copy.size() - 1, k - 1);

		Arr res(k, 0);
		int index = 0;
		for (int i = 0; i != data.size(); ++i) {
			if (data[i] < minKth)
				res[index++] = data[i];
		}
		for (; index != res.size(); ++index)
			res[index] = minKth;

		return res;
	}

};

int main(){
	int testTime = 10;
	bool succeed = true;
	int size = 10;
	int value = 100;

	BFPRT b;

	for (int i = 0; i < testTime; ++i) {
		testCase t(size, value);
		auto arr2(t.getArr());
		auto arr3(t.getArr());

		//std::sort(arr2.begin(), arr2.end());
		//BubbleSort(arr3);
		//SelectionSort(arr3);
		//InsertionSort(arr3); 
		for(auto e : arr2)
			std::cout << e << ' ';
		std::cout << std::endl;

		for (auto e : b.getMinKNumsByBFPRT(arr3, 5))
			std::cout << e << ' ';
		std::cout << std::endl;
		
	}
}	