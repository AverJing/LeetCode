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

class Base final{

};

/*
class Exten :public Base {

};*/

template<typename T>
class MakeSealed {
	friend T;
private:
	MakeSealed() {}
	~MakeSealed() {}
};

class SealedClass2 :virtual public MakeSealed< SealedClass2> {
public:
	SealedClass2() {}
	~SealedClass2() {}
};

class SealedClass3 :public SealedClass2 {
public:
	SealedClass3() {}
	~SealedClass3() {}
};

int main(){
	
}	