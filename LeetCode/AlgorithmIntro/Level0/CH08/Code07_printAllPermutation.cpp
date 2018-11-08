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
#include <algorithm>
#include <string>

void PrintAllPermutation(std::string s) {
	std::sort(s.begin(), s.end());

	do {
		std::cout << s << std::endl;
	} while (std::next_permutation(s.begin(), s.end()));
}

void PrintAllPermutation2(std::string s) {
	std::sort(s.begin(), s.end());

	auto start = std::prev(s.end());
	while (true) {
		for (;;) {
			auto last = start;

			if (*--start < *last) {
				auto iter = s.end();
				while (!(*start < *--iter));

				std::iter_swap(start, iter);
				std::reverse(last, s.end());
				std::cout << s << std::endl;
				break;
			}
			if (start == s.begin()) {
				std::reverse(start, s.end());
				std::cout << s << std::endl;
				return;
			}
		}
		start= std::prev(s.end());
	}
}


int main(){
	PrintAllPermutation2("abc");
}	