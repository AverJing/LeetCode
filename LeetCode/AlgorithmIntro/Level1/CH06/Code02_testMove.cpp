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
#include <list>
#include <ctime>
#include <algorithm>

namespace Jcy_testListMove {

	struct Point{
		int x;
		int y;
		Point(int x = 0, int y = 0) :x(x), y(y) {}
		Point(const Point&) = default;
		Point(Point&&) = default;
	};
	struct PointList {
		std::list<Point> plane;
		PointList() = default;
		PointList(const PointList&) = default;
		PointList(PointList&&) noexcept = default;
	};

	void test_construct(){
		auto start = clock();
		std::list<PointList> cube;	
		cube.push_back(PointList());
		for (int i = 0; i < 1000; ++i) {
			cube.begin()->plane.push_back(Point(i, i+1));
		}
		cube.push_back(PointList());
		cube.push_back(PointList());
		for (int i = 0; i < 1000; ++i) {
			cube.begin()->plane.push_back(Point(i+100, i + 101));
		}

		auto pos = ++cube.begin();

		while (!cube.begin()->plane.empty()) {
			auto t = cube.begin()->plane.begin();
			pos->plane.push_back(*t);
			cube.begin()->plane.pop_front();
		}

		while (!std::prev(cube.end())->plane.empty()) {
			auto t = cube.begin()->plane.begin();
			pos->plane.push_back(*t);
			cube.begin()->plane.pop_front();
		}
		std::cout << pos->plane.size() << ' ';
		auto end = clock();
		std::cout << end - start << std::endl;
	}

	void test_move() {
		auto start = clock();
		std::list<PointList> cube;
		cube.push_back(PointList());
		for (int i = 0; i < 1000; ++i) {
			cube.begin()->plane.push_back(Point(i, i + 1));
		}
		cube.push_back(PointList());
		cube.push_back(PointList());
		for (int i = 0; i < 1000; ++i) {
			cube.begin()->plane.push_back(Point(i + 100, i + 101));
		}

		auto pos = ++cube.begin();
		//https://stackoverflow.com/questions/17733943/how-to-quickly-swap-object-in-containers-such-as-list-and-vector-in-c
		//可以用splice交换节点的位置
		//注意merge操作必须是有序的

		//没有解决我的问题
		//从一个list中的节点通过move到另一个list，免除构造
		while (!cube.begin()->plane.empty()) {
			auto t = cube.begin()->plane.begin();
			pos->plane.splice(pos->plane.end(), cube.begin()->plane, t);
		}

		while (!std::prev(cube.end())->plane.empty()) {
			auto t = cube.begin()->plane.begin();
			pos->plane.splice(pos->plane.end(), cube.begin()->plane, t);
		}
		std::cout << cube.begin()->plane.size() << ' ';
		std::cout << pos->plane.size() << ' ';
		auto end = clock();
		std::cout << end - start << std::endl;
	}
};

int main(){
	Jcy_testListMove::test_move();
}	