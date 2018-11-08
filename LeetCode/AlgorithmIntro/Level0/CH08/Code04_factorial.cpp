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

template<unsigned n>
struct Fact {
	enum { value = n * Fact<n - 1>::value };
	//int value = n * Fact<n - 1>::value;
};

template<>
struct Fact<1>
{
	enum { value = 1 };
};

int RecurseFact(int n) {
	if(n == 1) return 1;

	return n * RecurseFact(n - 1);
}

int IterateFact(int n) {
	if (n < 0) return 0;
	int result = 1;
	
	for (int i = 1; i <= n; ++i)
		result *= i;

	return result;
}

int main(){
	Fact<4>  s;
	std::cout << s.value;
}	