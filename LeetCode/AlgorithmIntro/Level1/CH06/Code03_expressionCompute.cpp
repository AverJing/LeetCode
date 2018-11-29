/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

//LeetCode 227

#include <iostream>
#include <string>
#include <stack>
#include <deque>

using String = std::string;
using Stack = std::stack<int>;

namespace Jcy_ver_1 {
	class Solution {
	public:
		int getValue(const String& s) {
			if (s.empty()) return 0;

			int num = 0;
			Stack sym;
			bool step = false;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] <= '9'&&s[i] >= '0') {
					num = num * 10 + (s[i] - '0');
					//1.为了排除空格，且得到空格前边的数
					//2. 为了得到最后的数字
					if ((i + 1 < s.size() && s[i + 1] == ' ') || i + 1 == s.size()) {
						sym.push(num);
						step = true;
					}
				}
				else if (s[i] == ')') {
					sym.push(num);
					//计算括号内的运算
					getNoParenthesesNum(sym);
					step = true;
					//检查左括号左边是否有*/，即括号计算完后是否有计算可以完成
					checkMulOrDiv(sym);
					num = 0;
				}
				else if (s[i] == '(') {
					sym.push(s[i]);
				}
				else if (s[i] == ' ') {
					continue;
				}
				else {//(s[i] != '(') 
					if (!step) {
						sym.push(num);
					}
					step = false;
					checkMulOrDiv(sym);
					sym.push(s[i]);
					num = 0;
				}
			}

			checkMulOrDiv(sym);
			return getNoParenthesesNum2(sym);
		}

		//为了从左向右求得+-的结果
		int getNoParenthesesNum2(Stack& stk) {
			Stack s;
			while (!stk.empty()) {
				s.push(stk.top());
				stk.pop();
			}
			while (!s.empty() && s.size() > 1) {
				//注意该字符是 '\x2'和'2'不同
				//以16禁止表示的字符
				int cur1 = s.top();  //s.top()-'0'
				s.pop();
				char top = s.top();
				s.pop();
				int cur2 = (int)s.top();
				s.pop();
				if (!s.empty() && s.top() == '(') {
					s.pop();
					s.push(getBasicResult(top, cur1, cur2));
					break;
				}
				s.push(getBasicResult(top, cur1, cur2));
			}
			return s.top();
		}
		//计算（）中的结果
		int getNoParenthesesNum(Stack& s) {
			while (!s.empty() && s.size() > 1) {
				//注意该字符是 '\x2'和'2'不同
				//以16禁止表示的字符
				int cur1 = s.top();  //s.top()-'0'
				s.pop();
				char top = s.top();
				s.pop();
				int cur2 = (int)s.top();
				s.pop();
				if (!s.empty() && s.top() == '(') {
					s.pop();
					s.push(getBasicResult(top, cur2, cur1));
					break;
				}
				s.push(getBasicResult(top, cur2, cur1));
			}
			return s.top();
		}

		//核实是否有*/可以计算
		void checkMulOrDiv(Stack& sym) {
			if (!sym.empty()) {
				int cur1 = sym.top();
				sym.pop();
				if (!sym.empty() && (sym.top() == '*' || sym.top() == '/')) {
					auto top = sym.top();
					sym.pop();
					int cur2 = sym.top();
					sym.pop();
					sym.push(getBasicResult(top, cur2, cur1));
				}
				else {
					sym.push(cur1);
				}
			}
		}
		//返回基本运算结果
		int getBasicResult(char c, int a, int b) {
			if (c == '*' || c == '/') {
				return (c == '*' ? a * b : a / b);
			}
			else if (c == '+' || c == '-') {
				return (c == '+' ? a + b : a - b);
			}
		}
	};
}

using Deque = std::deque<String>;

namespace Jcy_ver_2 {
	class Solution {
	public:
		std::pair<int, int> value(const String& s, int i) {
			Deque stk;
			int pre = 0;
			std::pair<int, int> bra;
			while (i < s.size() && s[i] != ')') {
				if (s[i] <= '9'&&s[i] >= '0') {
					pre = pre * 10 + (s[i++]-'0');
				}
				else if (s[i] != '(') {
					addNum(stk, pre);
					stk.push_back(String(1, s[i++]));  //error: to_string(s[i++])
					//https://blog.csdn.net/carbon06/article/details/79353821
					//三种方法
					pre = 0;
				}
				else {
					bra = value(s, i + 1);
					pre = bra.first;
					i = bra.second + 1;
				}
			}
			addNum(stk, pre);
			return { getNum(stk), i };
		}

		int getValue(const String& s) {
			String str;
			for (auto e : s) {
				if (e != ' ')
					str += e;
			}
			return value(str, 0).first;
		}

		void addNum(Deque& s, int num) {
			if (!s.empty()) {
				int cur = 0;
				auto top = s.back();
				if (top == "*" || top == "/") {
					s.pop_back();
					cur = std::stoi(s.back());
					s.pop_back();
					num = top == "*" ? cur * num : cur / num;
				}
			}
			s.push_back(std::to_string(num));
		}

		int getNum(Deque& s) {
			int res = 0;
			bool add = true;
			String cur;
			int num = 0;
			while (!s.empty()) {
				cur = s.front();
				s.pop_front();
				if (cur == String("+")) {
					add = true;
				}
				else if (cur == String("-")) {
					add = false;
				}
				else {
					num = std::stoi(cur);
					res += add ? num : -num;
				}
			}
			return res;
		}
	};
}


int main(){
	Jcy_ver_2::Solution s;
	std::cout << s.getValue(" 3/2 ");
	
	//char a = '\x2'; //'2'
	//这只是个16进制的转义字符
	//std::cout << a;
}	