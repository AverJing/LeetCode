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

/*
class Singleton {
public:
	static Singleton s;
};

Singleton Singleton::s = Singleton();
*/

class Singleton {
public:
	static shared_ptr<Singleton> getInstance() {
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

//note: static member can access class private member
shared_ptr<Singleton> Singleton::instance(new Singleton(), Singleton::Destroy);

int main() {
	//std::cout << sizeof(Singleton);
	auto s1 = Singleton::getInstance();
	auto s2 = Singleton::getInstance();
	auto s3 = Singleton::getInstance();
}