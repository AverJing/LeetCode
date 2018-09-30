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
#include <memory>

using std::shared_ptr;

class Singleton {
public:
	static Singleton* getInstance() {
		static Singleton instance;
		return &instance;
	}
	//Singleton() = delete;
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	Singleton() { std::cout << "create single instance." << std::endl; }
	~Singleton() { std::cout << "remove single instance by deconstructor." << std::endl; }
};


int main() {
	std::cout << sizeof(Singleton) << std::endl;

	auto s1 = Singleton::getInstance();
	auto s2 = Singleton::getInstance();
	auto s3 = Singleton::getInstance();
}