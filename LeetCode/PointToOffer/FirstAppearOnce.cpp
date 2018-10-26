/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

//https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

如果当前字符流没有存在出现一次的字符，返回#字符。
*/


#include <iostream>
#include <vector>

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		++hashArray[ch - '\0'];
		if (hashArray[ch - '\0'] == 1) {
			data.push_back(ch);
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (auto e : data) {
			if (hashArray[e - '\0'] == 1)
				return e;
		}
		return '#';
	}

private:
	//https://zhuanlan.zhihu.com/p/21102748
	//error
	//std::vector<int> hashArray(128,1);  //自动初始化
	//会跟函数名冲突
	unsigned char hashArray[128];
	std::vector<char> data;
};

class Test {
public:
	//疑问，此处的是调用的移动构造吗
	//我觉得是拷贝构造，可是编译器会对其进行优化吗
	//将未命名的空间直接给data
	//在调试的时候，看不到具体执行的什么
	Test() :data(
		std::vector<int>(10, 0)) {}
	void Print() {
		for (auto e : data)
			std::cout << e << ' ';
		std::cout << std::endl;
	}
private:
	std::vector<int> data;
};

int main(){
	//Solution s;
	//s.Insert('c');

	Test t;
	t.Print();
}	