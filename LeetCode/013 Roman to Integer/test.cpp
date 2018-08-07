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
#include <string>
//#include "solution.h"

using namespace std;

/*
Question:
string s = "A";
string p = "ABCD";
how to compare p[0] and s ?
*/

int main(){
	//Solution s;
	//cout << s.romanToInt("LVIII") << endl;
	const string s = "A";  //In fact, s is equal to "A\0"
	string p = "ABCD";
	if(s == p.substr(0, 1))
		cout <<boolalpha << "true" ;
}	