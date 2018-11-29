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

//1到N的位置，初始位置M,一个机器人走P步后回到K的步骤
int ways(int N, int M, int P, int K) {
	if (N < 2 || M < 1 || M > N || P < 0 || K > N || K < 1) {
		return 0;
	}

	if (P == 0) {
		return M == K ? 1 : 0;
	}
	int res = 0;
	if (M == 1) {
		res = ways(N, M + 1, P - 1, K);
	}
	else if (M == N) {
		res = ways(N, M - 1, P - 1, K);
	}
	else {
		res = ways(N, M + 1, P - 1, K) + ways(N, M - 1, P - 1, K);
	}
	return res;
}

int main(){
	
}	