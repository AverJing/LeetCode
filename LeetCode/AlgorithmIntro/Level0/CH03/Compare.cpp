/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//use lambda/operator< to test comparator
//this code is just for lambda 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

static unsigned id = 0;

struct Student {
	std::string name;
	unsigned ID;  //automatically
	unsigned age;
	Student(const std::string& name, unsigned age) 
		:name(name), age(age), ID(++id) {
	}
	/*
	std::ostream& operator<<(const Student& rhs) const{
		std::cout << name << ' ' << ID << age;
	}*/
	friend std::ostream& operator<<(std::ostream& os, const Student& rhs) {
		os << rhs.name << '\t' << rhs.ID << '\t' << rhs.age;
		return os;
	}
};

int main(){
	Student s1("xiao", 22);
	Student s2("xiaoli", 18);
	Student s3("linda", 21);
	Student s4("hihi", 21);
	std::vector<Student> tmp{ s3,s1,s2,s4 };

	//sort is not stable
	std::sort(tmp.begin(), tmp.end(),
		[](const Student& s1, const Student& s2) { return s1.ID < s2.ID; });

	std::sort(tmp.begin(), tmp.end(),
		[](const Student& s1, const Student& s2) { return s1.age < s2.age; });

	/*
	std::stable_sort(tmp.begin(), tmp.end(),
		[](const Student& s1, const Student& s2) { return s1.ID < s2.ID; });

	std::stable_sort(tmp.begin(), tmp.end(),
		[](const Student& s1, const Student& s2) { return s1.age < s2.age; });
	*/
	for (const auto& e : tmp) {
		//e.operator<<(e);   //horrible
		std::cout << e << std::endl;  //better
	}
}	