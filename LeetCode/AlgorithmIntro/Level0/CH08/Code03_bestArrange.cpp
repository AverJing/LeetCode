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

struct Program {
	int start;
	int end;
	Program(int s, int e) :start(s), end(e) {}
};

using ArrProgram = std::vector<Program>;

int bestArrange(ArrProgram& program, int start) {
	if (program.empty()) return 0;
	
	int result = 0;
	std::sort(program.begin(), program.end(),
		[](const Program& lhs, const Program& rhs) { return lhs.end < rhs.end; });
	for (const auto &e : program) {
		if (start < e.end) {
			++result;
			start = e.end;
		}
	}
	return result;
}

int main(){
	
}	