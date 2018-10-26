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

using std::vector;

//在牛客上   记得把返回值设为long long，要不然会出错。  数据太大
class Solution {
public:
	int InversePairs(vector<int>& data) {
		if (data.empty()) return 0;

		vector<int> copy(data);

		int count = InversePairsCore(data, copy, 0, data.size() - 1);
		return count;
	}
private:
	int InversePairsCore(vector<int>& data, vector<int>& copy, int start, int end) {
		if (start == end) {
			//copy[start] = data[start];
			return 0;
		}

		int length = (end - start) / 2;

		int left = InversePairsCore(copy, data, start, start + length);
		int right = InversePairsCore(copy, data, start + length + 1, end);

		//i初始化为前半段最后一个数字的下标
		int i = start + length;
		//j初始化为后半段最后一个数字的下标
		int j = end;
		int indexCopy = end;
		int count = 0;
		while (i >= start && j >= start + length + 1) {
			if (data[i] > data[j]) {
				copy[indexCopy--] = data[i--];
				count += j - start - length;
			}
			else {
				copy[indexCopy--] = data[j--];
			}
		}
		for (; i >= start; --i)
			copy[indexCopy--] = data[i];
		for (; j >= start+length+1; --j)
			copy[indexCopy--] = data[j];

		return left + right + count;
	}
};

int main(){
	vector<int> tmp{ 7,5,6,4 };
	Solution s;
	std::cout << s.InversePairs(tmp);
}	