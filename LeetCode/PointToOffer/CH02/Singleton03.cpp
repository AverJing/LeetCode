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
	//single thread, multithread should add lock
	static shared_ptr<Singleton> getInstance() {
		if (instance == nullptr) {
			instance.reset(new Singleton(), Destroy);
		}
		return instance;
	}
	//Singleton() = delete;
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	static shared_ptr<Singleton> instance;
	static void Destroy(Singleton *) {
		if (instance) delete instance.get();  //call destructor
		std::cout << "remove single instance." << std::endl;
	}
	Singleton() { std::cout << "create single instance." << std::endl; }
	~Singleton() { std::cout << "remove single instance by deconstructor." << std::endl; }
};

shared_ptr<Singleton> Singleton::instance = nullptr;

int main() {
	std::cout << sizeof(Singleton) << std::endl;

	auto s1 = Singleton::getInstance();
	auto s2 = Singleton::getInstance();
	auto s3 = Singleton::getInstance();
}