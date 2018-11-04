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
#include <queue>
#include <string>

static unsigned count = 0;

struct Animal {
	std::string name;
	unsigned ID;
	Animal(std::string s = "") :name(s), ID(++count) {}
};

class DogAndCat {
public:
	DogAndCat() = default;
	Animal pollAll() {
		if (isEmpty())
			throw std::runtime_error("Animal queue is empty");
		else if (isDogEmpty() && !isCatEmpty()) {
			return pollCat();
		}
		else if (!isDogEmpty() && isCatEmpty()) {
			return pollDog();
		}
		else {
			if (peekDog().ID < peekCat().ID)
				return pollDog();
			else
				return pollCat();
		}
	}
	Animal pollCat() {
		Animal tmp = cat.front();
		cat.pop();
		return tmp;
	}
	Animal pollDog() {
		Animal tmp = dog.front();
		dog.pop();
		return tmp;
	}
	Animal& peekDog() {
		return dog.front();
	}
	Animal& peekCat() {
		return cat.front();
	}
	void pushDog(const Animal& rhs) {
		dog.push(rhs);
	}
	void pushCat(const Animal& rhs) {
		cat.push(rhs);
	}
	bool isEmpty() {
		return dog.empty() && cat.empty();
	}
	bool isCatEmpty() {
		return cat.empty();
	}
	bool isDogEmpty() {
		return dog.empty();
	}
private:
	std::queue<Animal> dog;
	std::queue<Animal> cat;
};

int main(){
	DogAndCat test;

	Animal dog1("hello");
	Animal cat1("hi");
	Animal dog2("see");
	Animal cat2("you");
	Animal dog3("later");
	Animal cat3("bye");

	test.pushDog(dog1);
	test.pushCat(cat1);
	test.pushDog(dog2);
	test.pushCat(cat2);
	test.pushDog(dog3);
	test.pushCat(cat3);

	while (!test.isDogEmpty()) {
		std::cout  << test.pollDog().name << ' ';
	}
	while (!test.isEmpty()) {
		std::cout << test.pollAll().name << ' ';
	}
}	